#pragma once

#include <stdlib.h>
#include "stdio.h"
#include "FileHelper.h"
#include <string.h>

#define MAX_NUMBER_CASES 100

struct logData *initLogData(String pathFile, String nameFile);

struct CommitData *makeCommitData(int id, String message);