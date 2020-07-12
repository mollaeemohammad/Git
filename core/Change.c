#include "Change.h"

enum Boolean isChanged(String nameOfFile) {

    String innerOfFile = readFile(".\\", nameOfFile);
    String innerOfHEAD = readFile(".\\git", "HEAD.txt");
    return strcmp(innerOfFile, innerOfHEAD) ? True : False;
}

String findChanges(String nameOfFile) {
    char filesAddress[50];
    String *fileArray = (String*) malloc(MAX_LINE_NUMBER * sizeof(String));
    String *HEADArray = (String*) malloc(MAX_LINE_NUMBER * sizeof(String));
    for(int i = 0; i<MAX_LINE_NUMBER; i++){
        fileArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
        HEADArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
    }
    String tempLineFile = (String) malloc(MAX_LINE_SIZE * sizeof(char));
    String tempLineHEAD = (String) malloc(MAX_LINE_SIZE * sizeof(char));

    struct Diff *tempDiff = (struct Diff *) malloc(sizeof(struct Diff *));
    sprintf(filesAddress, ".\\%s", nameOfFile);
    FILE *file = fopen(filesAddress, "r");
    sprintf(filesAddress, ".\\git\\HEAD.txt");
    FILE *HEAD = fopen(filesAddress, "r");
    int sizeOfFile = 0, sizeOfHEAD = 0;

    while (tempLineFile = fileGets(tempLineFile, file)) {
        fileArray[sizeOfFile++] = tempLineFile;
    }
    while (tempLineHEAD = fileGets(tempLineHEAD, HEAD)){
        HEADArray[sizeOfHEAD++] = tempLineHEAD;
    }
}