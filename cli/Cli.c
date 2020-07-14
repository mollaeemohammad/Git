#include "Cli.h"
#include <windows.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>

#define MAX_FILE_NAME 500
#define MAX_PATH_CHAR 100
#define MAX_ITEM_MEMORY 2000

struct fileId {
    String fileName;
    int id;
};

/**
 * main function that executes all user command
 *
 */
int runCli(int argc, String argv[]) {
    int userInput = 1;

}

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

void changeDesk(String fileName,String funcName){
    String *fileArray = (String *) malloc(MAX_LINE_NUMBER * sizeof(String));
    String *HEADArray = (String *) malloc(MAX_LINE_NUMBER * sizeof(String));
    for (int i = 0; i < MAX_LINE_NUMBER; i++) {
        fileArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
        HEADArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
    }
    struct Diff *diff;
    diff = findChanges(fileName, fileArray, HEADArray);

    if(!strcmp(funcName, "initGit")){
        if(initGit()){
            changeConsoleColor(COLOR_BLOCK_GREEN);
            printf("The initialization is done\n\n");
        }
    }
}