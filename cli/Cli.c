#include "Cli.h"
#include <windows.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>

#define MAX_FILE_NAME 500
#define MAX_PATH_CHAR 1000
#define MAX_ITEM_MEMORY 20000

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

/**
 * saves your current judge histories (public and private)
 */
int saveCurrentHistory() {

}

/**
 * this function saves the file chosen by user in hidden directory
 */
int saveHiddenHistory() {

}

/**
 * this function shows you the name of all items and their IDs in the hidden history directory.
 */
void showHistoryList() {

}

/**
 * as you can guess this function shows an specific file available in the hidden directory that contains your results history
 */
int showHistoryFile() {

}

/**
 * this function is menu that contains two options. Based on user argument it acts differently
 */
int historyMenu(String userArgument) {

}
