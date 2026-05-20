#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "help.h"
#include "version.h"
#include "sizes.h"
#include "nebula.h"

int main() {

    char cwd[PATH_MAX];
    char command[20];

    // Get current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error\n");
        return 1;
    }

    // Init
    printf("Wecome to the Comet CLI:\n");
    printf("Enter Command (type \"help\" to list commands):\n");


    while (1) {
        printf("$ ");
        scanf("%s", command); 

        if (strcmp(command,"sizes") == 0) {
            int maxViewport = 0, minViewport = 0;

            printf("Enter Max Viewport Width: "); scanf("%d", &maxViewport); 
            printf("Enter Min Viewport Width: "); scanf("%d", &minViewport); 

            if (maxViewport < 100 || maxViewport > 3000  ) {
                printf("[ERROR] max viewport value (%d) not supported (value must be >= 100 && <= 3000)\n", maxViewport); 
                continue;
            } 
            if (minViewport < 50 || minViewport > 1500  ) {
                printf("[ERROR] min viewport value (%d) not supported (value must be >= 50 && <= 1500)\n", minViewport); 
                continue;
            } 

            printSizes(&maxViewport, &minViewport);
            continue;

        }
        if (strcmp(command,"nebula") == 0) {

            //clone repo into cwd
            if (cloneNebula(cwd)) {
                printf("[ERROR] Error thrown while cloning github repo\n"); 
                continue;
            }

            //update min file
            if (updateNebula(cwd)) {
                printf("[ERROR] Error thrown while updating min file\n");
                continue;
            }

            //clean up cloned folder
            if (cleanNebula(cwd)) {
                printf("[ERROR] Error thrown while cleaning up cloned folder\n");
                continue;
            }

            printf("[SUCCESS] Nebula CSS has been successfully updated\n");
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
