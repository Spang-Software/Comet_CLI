#include <stdio.h>
#include "help.h"

void printHelp(void) {
    printf("Options: =========================================================\n");
    printf("  sizes    generate NOVA CSS size variables\n");
    printf("  nebula    Updates Nebula CSS to latest verion (GIT CLI required)\n");
    printf("  help    Display this help message\n");
    printf("  version    Display version number\n");
    printf("  quit    Exit the CLI\n");
    printf("==================================================================\n");
}
