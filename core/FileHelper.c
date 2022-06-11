#include "FileHelper.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include "Macros.h"
#include "stdio.h"
#include "string.h"

#define MAX_LINE_SIZE 1000
#define MAX_RESULT_SIZE MAX_LINE_SIZE*99
#define MAX_FILE_RESULT_COUNT 99
#define MAX_FILE_NAME 100
#define FILE_FLAG 0
#define MAX_COMMITS_NUMBER 100

String fileAddressMaker(String path, String filename);

/**
 * @ifnot free the string you causes memory leak
 * @param path directory of your file
 * @param filename filename
 * @return file data as a Text
 */
String readFile(String path, String filename) {
    String fileAddress = (String) malloc(sizeof(char) * MAX_FILE_NAME);
    sprintf(fileAddress, "%s\\%s", path, filename);
    FILE *file = fopen(fileAddress, "r");
    if (!file) {
        return NULL;
    }
    // read file line by line
    String result = malloc(sizeof(char) * MAX_RESULT_SIZE);
    result[0] = '\0';
    String line = malloc(sizeof(char) * MAX_LINE_SIZE);
    while ((line = fgets(line, MAX_LINE_SIZE, file))) {
        strcat(result, line);
    }
    fclose(file);
    free(fileAddress);
    free(line);
    return result;

}

/**
 *
 * @param path path/to/file
 * @param filename
 * @param content the content you want to write to the file
 * @return isSuccessful
 */
enum Boolean writeFile(String path, String filename, String content) {
    String fileAddress = (String) malloc(sizeof(char) * MAX_FILE_NAME);
    sprintf(fileAddress, "%s\\%s", path, filename);
    FILE *file = fopen(fileAddress, "w");
    if (!file) {
        return False;
    }
    fputs(content, file);
    fclose(file);
    return True;

}

/**
 * you should free the list that you given . items first
 * @param path path/to/file
 * @param n size of files
 * @return list of file names in path
 */
String *getFilesInDirectory(String path, int *n) {
    String *result = (String *) malloc(sizeof(String) * MAX_FILE_RESULT_COUNT);
    for (int i = 0; i < MAX_FILE_RESULT_COUNT; i++) {
        result[i] = (String) malloc(sizeof(char) * MAX_FILE_NAME);
    }
    int resSize = 0;

    struct dirent *dir;
    DIR *pDir = opendir(path);

    if (pDir) {
        while ((dir = readdir(pDir)) != NULL) {
            if (dir->d_type == FILE_FLAG) {
                String filename = malloc(sizeof(char) * strlen(dir->d_name));
                strcpy(filename, dir->d_name);
                result[resSize++] = filename;
            }
        }
        closedir(pDir);
    }
    *n = resSize;
    return result;
}

/**
 * make hierarchy directories
 * @param path array of folder names {"path","to","file"}
 * @param n number of folder name
 * @return isSuccessful
 */
enum Boolean makeDirectories(String path[], int n) {
    String beforePath = malloc(sizeof(char) * MAX_LINE_SIZE);
    enum Boolean isOk = True;
    for (int i = 0; i < n; ++i) {
        int status = mkdir(strcat(beforePath, path[i]));
        if (!status) {
            isOk = False;
        }
        strcat(beforePath, "/");
    }
    free(beforePath);
    return isOk;
}

/**
 * check if the file is exist or not
 * @param path
 * @param filename
 * @return 1 if exits and 0 for not exists
 */
enum Boolean isFileExist(String path, String filename) {
    String fileAddress = (String) malloc(sizeof(char) * MAX_FILE_NAME);
    sprintf(fileAddress, "%s\\%s", path, filename);
    struct stat buffer;
    int notExist = stat(fileAddress, &buffer);
    return notExist ? False : True;

}

/**
 *
 * @param path path to file
 * @return is fileExits or not
 */
enum Boolean isFolderExist(String path) {
    DIR *dir = opendir(path);
    if (dir) {
        closedir(dir);
        return True;
    } else if (ENOENT == errno) {
        //file not exist
        return False;
    }
    return False;
}

/**
 *
 * @param path file directory
 * @param filename
 * @return concat path/filename
 */
String fileAddressMaker(String path, String filename) {
    // create file address
    String fileAddress;
    fileAddress = (String) malloc(sizeof(char) * MAX_LINE_SIZE);
    strcpy(fileAddress, path);
    strcat(fileAddress, "\\");
    strcat(fileAddress, filename);
    return fileAddress;
}

/**
 * delete single file
 * @param filePath path/to/file
 * @param filename
 * @return is the file delete or not
 */
enum Boolean delete(String filePath, String filename, enum ShowKind kind) {
    String fileAddress = fileAddressMaker(filePath, filename);
    if (kind == File) {
        int res = remove(fileAddress);
        return res ? False : True;
    } else if (kind == Folder) {
        String command = (String) malloc(sizeof(char) * MAX_FILE_NAME);
        sprintf(command, "rmdir /Q /S %s", fileAddress);
        system(command);
        free(command);
        return isFolderExist(fileAddress) ? False : True;
    }
}

/**
 * deletes the folder even if somethings be on that
 * @param id
 */
void deleteFolders(int id) {
    char numberString[5];
    char addressString[50];
    for (int i = id; i < MAX_COMMITS_NUMBER; i++) {
        sprintf(numberString, "%d", i);
        sprintf(addressString, ".\\git\\commits\\%d", i);
        if (isFolderExist(addressString))
            delete(".\\git\\commits", numberString, Folder);
    }
}
