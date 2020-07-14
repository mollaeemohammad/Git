#pragma once

#include "Macros.h"
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

enum ShowKind {File, Folder};

String readFile(String path, String filename);

enum Boolean writeFile(String path, String filename, String content);

String *getFilesInDirectory(String path, int *n);

enum Boolean makeDirectories(String path[], int n);

enum Boolean isFileExist(String path, String filename);

enum Boolean isFolderExist(String path);

enum Boolean delete(String filePath, String filename, enum ShowKind kind);

void deleteFolders(int id);