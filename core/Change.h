#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHelper.h"
#include "Core.h"
#include "Log.h"

#define MAX_LINE_SIZE 70
#define MAX_LINE_NUMBER 50
#define fileGets(str,file) fgets(str, MAX_LINE_SIZE, file)

struct StringOrAddress{
    int address;
    String string;
};

struct Diff{
    int size;
    int sign[MAX_LINE_NUMBER];
    struct StringOrAddress *parameter;
};

struct Diff *findChanges(String nameOfFile, String fileArray[], String HEADArray[]);