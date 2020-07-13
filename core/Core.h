#pragma once

#include "Macros.h"
#include "Core.h"
#include <stdlib.h>
#include "stdio.h"
#include "FileHelper.h"
#include "Log.h"

#define MAX_SIZE_FILE 10000
#define MAX_ARRAY_SIZE 1000
#define MIN_ARRAY_SIZE 100

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

struct information{
    int id;
    String fileName;
};

enum Boolean initGit();

String toJson(struct logData *data);

String strConcat(String list[], int size);

String currentTime();

enum Boolean getInformation(struct information *inform);