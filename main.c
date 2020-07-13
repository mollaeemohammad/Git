#include <stdio.h>
#include "core/FileHelper.h"
#include "core/Change.h"
#include "core/Macros.h"
#include "core/Core.h"
#include "cli/Cli.h"
#include <string.h>
#include "core/Change.h"


int main() {
    //delete("D:\\GitProject", "GitProject", Folder);
//    _mkdir(".\\test");
//    if(initGit())
//        printf("ok");
//    else
//        printf("fault");
    String *fileArray = (String *) malloc(MAX_LINE_NUMBER * sizeof(String));
    String *HEADArray = (String *) malloc(MAX_LINE_NUMBER * sizeof(String));
    for (int i = 0; i < MAX_LINE_NUMBER; i++) {
        fileArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
        HEADArray[i] = (String) malloc(MAX_LINE_SIZE * sizeof(char));
    }
    struct Diff *temp;
    temp = findChanges("test.txt", fileArray, HEADArray);
    for(int i =0; i<temp->size; i++){
        if(temp->sign[i] == 0)
            printf("%s",temp->parameter[i].string);
        else if(temp->sign[i] == 1){
            printf("%d\n", temp->parameter[i].address);
        }
    }
    return 0;
}
