#include "Change.h"

enum Boolean isChanged(String nameOfFile) {

    String innerOfFile = readFile(".\\", nameOfFile);
    String innerOfHEAD = readFile(".\\git", "HEAD.txt");
    return strcmp(innerOfFile, innerOfHEAD) ? True : False;
}


struct Diff *findChanges(String nameOfFile, String fileArray[], String HEADArray[]) {
    char filesAddress[50];

    String tempLineFile = (String) malloc(MAX_LINE_SIZE * sizeof(char));
    String tempLineHEAD = (String) malloc(MAX_LINE_SIZE * sizeof(char));

    struct Diff *tempDiff = (struct Diff *) malloc(sizeof(struct Diff *));
    tempDiff->parameter = (struct StringOrAddress *) malloc(sizeof(struct StringOrAddress) * MAX_LINE_NUMBER);
    for (int i = 0; i < MAX_LINE_NUMBER; i++) {
        tempDiff->parameter[i].string = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
    }

    sprintf(filesAddress, ".\\%s", nameOfFile);
    FILE *file = fopen(filesAddress, "r");
    sprintf(filesAddress, ".\\git\\HEAD.txt");
    FILE *HEAD = fopen(filesAddress, "r");
    int sizeOfFile = 0, sizeOfHEAD = 0, found = 0;

    while (tempLineFile = fileGets(tempLineFile, file)) {
        strcpy(fileArray[sizeOfFile++], tempLineFile);
    }
    tempDiff->size = sizeOfFile;
    while (tempLineHEAD = fileGets(tempLineHEAD, HEAD)) {
        strcpy(HEADArray[sizeOfHEAD++], tempLineHEAD);
    }
    for (int i = 0; i < sizeOfFile; i++) {
        found = 0;
        for (int j = i; j < sizeOfHEAD; j++) {
            if (!strcmp(HEADArray[i], fileArray[j])) {
                tempDiff->sign[i] = 1;
                tempDiff->parameter[i].address = j;
                found = 1;
                break;
            }
        }
        if (!found) {
            tempDiff->sign[i] = 0;
            tempDiff->parameter[i].string = fileArray[i];
        }
    }
    return tempDiff;
}

void showChanges(struct Diff *diff) {
    int isChanged = 0;
    for (int i = 0; i < diff->size; i++) {
        if (diff->sign[i] == 0) {
            printf("%d\n%s", i + 1, diff->parameter[i].string);
            isChanged = 1;
        }
    }
    if(!isChanged)
        puts("No Changes!\n");
}