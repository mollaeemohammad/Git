#pragma once

#include "../core/Core.h"
#include "../core/Change.h"
#define COLOR_WHITE 7
#define COLOR_YELLOW 6
#define COLOR_LIGHT_BLUE 1
#define COLOR_RED 12
#define COLOR_BLOCK_GREEN 3
#define COLOR_BLOCK_YELLOW 2
#define COLOR_BLOCK_BLUE 9
#define COLOR_BLOCK_RED 4
#define COLOR_CYAN 11

void changeConsoleColor(int colorCode);

int runCli(int argc, String argv[]);

void changeDesk(String funcName, int nargs, String *args);