#include "Core.h"
#include "Macros.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include "../cli/Cli.h"
#include <time.h>

#define MAX_SIZE_ITEM_STRING 1000
#define MAX_CONCAT_LEN 1000

/**
 * this function returns the current time
 * @return dateString is a String which contains the current time
 */
String currentTime() {
    String dateString = (char *) malloc(sizeof(char) * 30);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateString, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
            tm.tm_min, tm.tm_sec);
    return dateString;
}

/**
 * this function makes the directories and files which we need to initialize the git
 * @return if it works good then returns true else is false
 */
enum Boolean initGit() {
    enum Boolean gitStatus, commits;
    struct logData *firstLog;
    String nameFile = (String) malloc(sizeof(char) * FILENAME_MAX);
    String forInfo = (String) malloc(sizeof(char) * FILENAME_MAX);
    String headFile;
    if (isFolderExist(".\\git")) {
        print("the git is initialized in past");
        return True;
    }
    gitStatus = !_mkdir(".\\git");
    if (gitStatus) {
        _mkdir(".\\git\\stash");

        printf("\nEnter the name of file: \n");
        scanf("%[^\n]", nameFile);
        headFile = readFile(".\\", nameFile);
        sprintf(forInfo, "0\n%s", nameFile);

        writeFile(".\\git", "Info.txt", forInfo);

        writeFile(".\\git", "status.txt", "");

        firstLog = initLogData(".\\", nameFile);
        writeFile(".\\git", "log.txt", toJson(firstLog));

        writeFile(".\\git", "select.txt", "");

        writeFile(".\\git", "HEAD.txt", headFile);

        commits = !_mkdir(".\\git\\commits");

        if (commits) {
            _mkdir(".\\git\\commits\\0");
            writeFile(".\\git\\commits\\0", "file.txt", headFile);
            return True;
        } else
            return False;
    } else {
        print("There is something wrong to initializing the git\n");
        return False;
    }
}


/**
 *
 * @param data object that represent the analysis of the output data
 * @return json object that represent data
 */
String toJson(struct logData *data) {
    String cases = malloc(data->caseNumber * sizeof(struct CommitData));
    cases[0] = '\0';
    String item = (String) malloc(MAX_SIZE_ITEM_STRING * sizeof(struct CommitData));
    for (int i = 0; i < data->caseNumber; ++i) {
        struct CommitData tempCommitData = data->cases[i];
        sprintf(item, "    {\n"
                      "      \t\"id\": %i,\n"
                      "      \t\"date\": %s,\n"
                      "      \t\"message\": \"%s\",\n"
                      "    },\n", tempCommitData.id, tempCommitData.date,
                tempCommitData.message);
//        String a[2] = {cases, item};
//        cases = strConcat(a, 2);
        strcat(cases, item);
    }
    return cases;

}

enum Boolean getInformation(struct information *inform) {
    FILE *file;
    file = fopen("git\\Info.txt", "r");
    if (file == NULL) {
        return False;
    }
    fscanf(file, "%d", &inform->id);
    char parasite;
    parasite = fgetc(file);
    fscanf(file, "%[^\n]", inform->fileName);
    return True;
}

enum Boolean writeInformation(String name, int id) {
    FILE *infoFile = fopen(".\\git\\Info.txt", "w");
    if(infoFile == NULL)
        return False;
    fprintf(infoFile, "%d\n", id);
    fprintf(infoFile, "%s\n", name);
    return True;
}

/**
 * concat list of strings
 * @param list
 * @param size
 * @return concatenation of string list
 */
String strConcat(String list[], int size) {
    String result = malloc(sizeof(char) * MAX_CONCAT_LEN);
    loop(i, size) {
        strcat(result, list[i]);
    }
    return result;

}

