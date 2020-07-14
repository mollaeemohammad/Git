#pragma once

#include "Macros.h"
#include "Core.h"
#include <stdlib.h>
#include "stdio.h"
#include "FileHelper.h"
#include "Log.h"
#include "Change.h"

#define MAX_SIZE_FILE 1000
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

struct information {
    int id;
    String fileName;
};

enum Boolean initGit();

String toJson(struct logData *data);

String strConcat(String list[], int size);

String currentTime();

enum Boolean getInformation(struct information *inform);

enum Boolean writeInformation(String name, int id);

struct CommitData *commit(struct Diff *diff, String *fileArray, String message);

void maker(String *newArray, String *HEADArray, int id);

void gotoId(String *HEADArray, int id);

void reset(String *HEADArray, int id);

enum Boolean stash(String *HEADArray, int id);

enum Boolean popStash();