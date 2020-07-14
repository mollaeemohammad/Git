#include "Log.h"
#include "Core.h"


/**
 * this function gets the id and message and makes commit to be in log data and commit file in commit folder
 * @param id
 * @param message
 * @return commit is the commit which this function has made
 */
struct CommitData *makeCommitData(int id, String message) {
    struct CommitData *commit = (struct CommitData *) malloc(sizeof(struct CommitData *));
    commit->date = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
    commit->message = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
    commit->date = currentTime();
    commit->id = id;
    commit->message = message;
    return commit;
}

/**
 * this function makes the structure of log data to the history of file
 * @param pathFile
 * @param nameFile
 * @return pointer to log structure
 */
struct logData *initLogData(String pathFile, String nameFile) {
    struct logData *pData = (struct logData *) malloc(sizeof(struct logData *));
    pData->path = (String) malloc(sizeof(char) * MAX_PATH);
    pData->path = pathFile;
    pData->fileName = (String) malloc(sizeof(char) * MAX_SIZE_FILE);
    pData->fileName = nameFile;
    pData->cases = (struct CommitData *) malloc(sizeof(struct CommitData) * MAX_NUMBER_CASES);\
    pData->caseNumber = 1;
    pData->cases[0] = *makeCommitData(0, "Initializing Git");
    return pData;
}

