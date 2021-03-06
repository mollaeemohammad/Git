#include "Cli.h"
#include <windows.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdarg.h>

#define MAX_FILE_NAME 256
#define MAX_PATH_CHAR 100
#define MAX_ITEM_MEMORY 1000

/**
 * Changes cmd font color
 * @param colorCode
 */
void changeConsoleColor(int colorCode) {
    // color code between 0 to 255
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

/**
 * all funcs are used at here
 * @param funcName
 * @param nargs
 * @param args
 */
void changeDesk(String funcName, int nargs, String *args) {
    String *fileArray = (String *) malloc(MAX_LINE_NUMBER * sizeof(String));
    String *HEADArray = (String *) malloc(MAX_LINE_NUMBER * sizeof(String));
    for (int i = 0; i < MAX_LINE_NUMBER; i++) {
        fileArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
        HEADArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
    }
    struct Diff *diff;
    int selectFlag;

    if (strcmp(funcName, "initGit") == 0) {
        if (initGit()) {
            changeConsoleColor(COLOR_BLOCK_GREEN);
            printf("The initialization is done\n\n");
            changeConsoleColor(COLOR_WHITE);
        } else if (!isFolderExist(".\\git")) {
            changeConsoleColor(COLOR_RED);
            printf("\ngit is not initialized!");
            changeConsoleColor(COLOR_WHITE);
            printf("to initialize the git type git init\n");
            return;
        }
    } else {
        struct information *inform = (struct information *) malloc(sizeof(struct information *));
        inform->fileName = (String) malloc(sizeof(char) * MAX_FILE_NAME);
        getInformation(inform);
        if (!strcmp(funcName, "status")) {
            if (isChanged(inform->fileName)) {
                diff = findChanges(inform->fileName, fileArray, HEADArray);
                changeConsoleColor(COLOR_BLOCK_BLUE);
                showChanges(diff);
                changeConsoleColor(COLOR_WHITE);
            } else {
                changeConsoleColor(COLOR_BLOCK_RED);
                printf("No Changes!\n\n");
                changeConsoleColor(COLOR_WHITE);
            }
        }
        if (strcmp(funcName, "select") == 0) {
            FILE *select = fopen(".\\git\\select.txt", "w");
            fprintf(select, "1");
        }
        if (strcmp(funcName, "unselect") == 0) {
            FILE *select = fopen(".\\git\\select.txt", "w");
            fprintf(select, "0");
        }
        if (strcmp(funcName, "commit") == 0) {
            FILE *select = fopen(".\\git\\select.txt", "r");
            fscanf(select, "%d", &selectFlag);
            if (selectFlag == 0) {
                changeConsoleColor(COLOR_RED);
                printf("No file is selected!\n");
                changeConsoleColor(COLOR_LIGHT_BLUE);
                printf("for selecting the file type ");
                changeConsoleColor(COLOR_WHITE);
                printf("git select");
            } else {
                if (nargs == 2) {
                    changeConsoleColor(COLOR_RED);
                    printf("You must have a message when you commit\n");
                    changeConsoleColor(COLOR_LIGHT_BLUE);
                    printf("type like ");
                    changeConsoleColor(COLOR_WHITE);
                    printf("git commit commitMessage\n");
                    return;
                }
                String message = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
                message[0] = '\0';
                for (int i = 0; i < nargs - 2; i++) {
                    strcat(message, args[i]);
                }
                diff = findChanges(inform->fileName, fileArray, HEADArray);
                commit(diff, fileArray, message);
            }
        }
        if (strcmp(funcName, "stash") == 0) {
            if (nargs == 2) {
                stash(HEADArray, inform->id);
                changeConsoleColor(COLOR_WHITE);
                printf("Id %d is in stash folder\n", inform->id);
            } else {
                int id;
                sscanf(args[0], "%d", &id);
                stash(HEADArray, id);
                changeConsoleColor(COLOR_WHITE);
                printf("Id %d is in stash folder\n", id);
            }
        }
        if (strcmp(funcName, "popstash") == 0) {
            if (popStash()) {
                changeConsoleColor(COLOR_WHITE);
                printf("Version in stash folder is removed\n");
            } else {
                changeConsoleColor(COLOR_RED);
                printf("No version is in stash folder!\n");
                changeConsoleColor(COLOR_WHITE);
            }
        }
        if (strcmp(funcName, "showlog") == 0) {
            changeConsoleColor(COLOR_LIGHT_BLUE);
            showLog();
            changeConsoleColor(COLOR_WHITE);
        }
        if (strcmp(funcName, "reset") == 0) {
            int id;
            if (nargs == 2) {
                changeConsoleColor(COLOR_RED);
                printf("You must type the number of id which you wanna reset it\n");
                changeConsoleColor(COLOR_WHITE);
                return;
            }
            sscanf(args[0], "%d", &id);
            reset(HEADArray, id);
            writeInformation(inform->fileName, id);
            changeConsoleColor(COLOR_WHITE);
            printf("Reset to version %d is done", id);
        }
    }

}