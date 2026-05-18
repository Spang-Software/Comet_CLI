#include <stdio.h>
#include "sizes.h"
#include "util.h"

void printSizes(int *maxViewport, int *minViewport) {
    short int sizesMin[16] = {2, 4, 6, 8, 10, 12, 14, 16, 24, 32, 48, 64, 80, 104, 128, 170};
    short int sizesMax[16] = {4, 8, 12, 16, 20, 24, 28, 32, 48, 64, 96, 128, 160, 208, 256, 320};

    printf("CSS Variables: =====================================\n");
    for(int i = 0; i < 16; i++) {
        printf("--s%d: %s;\n", sizesMax[i], getClamp(maxViewport, minViewport, sizesMax[i], sizesMin[i]));
    }
    printf("====================================================\n");
}
