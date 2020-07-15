#include <stdio.h>
#include "core/FileHelper.h"
#include "core/Change.h"
#include "core/Macros.h"
#include "core/Core.h"
#include "cli/Cli.h"
#include <string.h>
#include "core/Change.h"


void help() {
    changeConsoleColor(COLOR_LIGHT_BLUE);
    printf("It seems you may want some help\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("initialize git for the file ");
    changeConsoleColor(COLOR_WHITE);
    printf("git initGit\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("Show status of file ");
    changeConsoleColor(COLOR_WHITE);
    printf("git status\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("To select/unselect the file ");
    changeConsoleColor(COLOR_WHITE);
    printf("git select/unselect\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("To commit the changes ");
    changeConsoleColor(COLOR_WHITE);
    printf("git commit\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("To stash/popStash the file ");
    changeConsoleColor(COLOR_WHITE);
    printf("git stash/popstash\n");
    changeConsoleColor(COLOR_BLOCK_YELLOW);
    printf("The file id which you want is in stash folder in git\n");
    changeConsoleColor(COLOR_RED);
    printf("Warning: just one popstash for each stash you could do\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("To show history of commits ");
    changeConsoleColor(COLOR_WHITE);
    printf("git showlog\n");
    changeConsoleColor(COLOR_BLOCK_GREEN);
    printf("To reset the file to id which you want ");
    changeConsoleColor(COLOR_WHITE);
    printf("git reset id (id is a number)\n");
}


int main(int narg, String *args) {
    if (narg == 1) {
        help();
        return 0;
    }
    String *command = (String *) malloc(sizeof(char) * MAX_LINE_SIZE);
    for (int i = 0; i < narg - 2; i++) {
        command[i] = (String) malloc(sizeof(char) * MAX_WORD_SIZE);
        command[i][0] = '\0';
        strcpy(command[i], args[i + 2]);
    }
    changeDesk(args[1], narg, command);
    return 0;
}
