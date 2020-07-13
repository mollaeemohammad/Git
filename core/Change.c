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
    tempDiff->sign = (int *) malloc(sizeof(int) * MAX_LINE_NUMBER);
    for (int i = 0; i < MAX_LINE_NUMBER; i++) {
        tempDiff->parameter[i].string = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
        tempDiff->sign[i] = (int) malloc(sizeof(int));
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
    if (!isChanged)
        puts("No Changes!");
}

void writeDiffPage(struct Diff *diff) {
    struct information *tempInfo = (struct information *) malloc(sizeof(struct information *));
    tempInfo->fileName = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
    if (getInformation(tempInfo)) {
        String fileAddress = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
        sprintf(fileAddress, ".\\git\\commits\\%d\\diffPage.txt", tempInfo->id + 1);
        FILE *diffPage = fopen(fileAddress, "w");
        if (diffPage == NULL)
            return;
        for (int i = 0; i < diff->size; i++) {
            if (diff->sign[i] == 1) {
                fprintf(diffPage, "1\n");
                fprintf(diffPage, "%d\n", diff->parameter[i].address);
            } else if (diff->sign[i] == 0) {
                fprintf(diffPage, "0\n");
                fprintf(diffPage, "%s", diff->parameter[i].string);
            }
        }
        fclose(diffPage);
    }
}

enum Boolean getDiffPage(struct Diff *diff, int id) {
    char parasite;
    String diffPageAddress = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
    sprintf(diffPageAddress, ".\\git\\commits\\%d\\diffPage.txt", id);
    FILE *diffPage = fopen(diffPageAddress, "r");
    if (diffPage == NULL)
        return False;
    int size = 0;
    for (int i = 0; !feof(diffPage); i++) {
        fscanf(diffPage, "%d", &diff->sign[i]);
        if (diff->sign[i] == 1) {
            parasite = fgetc(diffPage);
            fscanf(diffPage, "%d", &diff->parameter[i].address);
        } else if (diff->sign[i] == 0) {
            parasite = fgetc(diffPage);
            fscanf(diffPage, "%[^\n]", diff->parameter[i].string);
        }
        size++;
    }
    size--;
    diff->size = size;
    free(diffPageAddress);
    fclose(diffPage);
    return True;
}