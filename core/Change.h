#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHelper.h"
#include "Core.h"
#include "Log.h"

#define MAX_LINE_SIZE 256
#define MAX_LINE_NUMBER 200
#define fileGets(str,file) fgets(str, MAX_LINE_SIZE, file)

union StringOrAddress{
    int address;
    String string;
};

struct Diff{
    int sign;
    union StringOrAddress parameter;
};

