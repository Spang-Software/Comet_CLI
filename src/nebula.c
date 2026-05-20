#include <stdio.h>
#include <stdlib.h>
#include "nebula.h"

#define GIT_HTTP_URL "https://github.com/Spang-Software/Nebula_CSS.git"
#define FILE_NAME "nebula.min.css"
#define FOLDER_NAME "Nebula_CSS"

int cloneNebula(char *cwd) {
    char command[60];

    printf("[INFO] cloning github repo...\n");

    snprintf(command, sizeof(command), "git clone %s %s", GIT_HTTP_URL, cwd);
    int status = system(command);

    if (status != 0) {
        return 1;
    }

    return 0;
}

int updateNebula(char *cwd) {
    char command[200];

    printf("[INFO] extracting files...\n");

    snprintf(command, sizeof(command), "mv -f %s/%s/%s %s/%s", cwd, FOLDER_NAME, FILE_NAME, cwd, FILE_NAME);
    int status = system(command);

    if (status != 0) {
        return 1;
    }

    return 0;
}

int cleanNebula(char *cwd) {
    char command[200];

    printf("[INFO] cleaning up directory...\n");

    snprintf(command, sizeof(command), "rm -rf %s/%s", cwd, FOLDER_NAME);
    int status = system(command);

    if (status != 0) {
        return 1;
    }

    return 0;
}
