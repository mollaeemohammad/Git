#pragma once

#include "Macros.h"
#include "Core.h"
#include <stdlib.h>
#include "stdio.h"
#include "FileHelper.h"


struct CommitData {
    int id;
    String date;
    String message;
};

struct logData {
    String path;
    String fileName;
    int caseNumber;
    struct CommitData *cases;

};



String toJson(struct logData *data);

String strConcat(String list[], int size);

String currentTime();