#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "help.h"
#include "version.h"
#include "sizes.h"

int main() {

    char cwd[PATH_MAX];
    char command[20];

    // Get current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error\n");
        return 1;
    }

    // Init
    printf("Wecome to the Spang CLI:\n");
    printf("Enter Command (type \"help\" to list commands):\n");


    while (1) {
        printf("$ ");
        scanf("%s", command); 

        if (strcmp(command,"sizes") == 0) {
            int maxViewport = 0, minViewport = 0;

            printf("Enter Max Viewport Width: "); scanf("%d", &maxViewport); 
            printf("Enter Min Viewport Width: "); scanf("%d", &minViewport); 

            printSizes(&maxViewport, &minViewport);
            continue;

        }
        if (strcmp(command,"help") == 0) {
            printHelp();
            continue;
        }
        if (strcmp(command,"version") == 0) {
            printVersion();
            continue;
        }
        if (strcmp(command,"quit") == 0) {
            break;
        }

        printf("Unknown Command. (type \"help\" to list commands):\n");

    }

    return 0;
}
