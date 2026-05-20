#include <stdio.h>
#include <math.h>
#include "util.h"

float pxToRem(int pxValue) {
    float remValue = pxValue / 16.00f;
    return remValue;
}

char* getClamp(int *maxViewport, int *minViewport, int maxValue, int minValue) {
    static char output[60];
    float maxValueRem = pxToRem(maxValue);
    float minValueRem = pxToRem(minValue);
    float maxViewportRem = pxToRem(*maxViewport);
    float minViewportRem = pxToRem(*minViewport);

    float slope = (maxValueRem - minValueRem) / (maxViewportRem - minViewportRem);
    float yAxis = (minValueRem * -1.0f) * slope + minValueRem;

    snprintf(output, sizeof(output), "clamp(%grem, (%.3frem + %gvw), %grem)", minValueRem, yAxis, roundf(slope * 1000) / 10, maxValueRem);

    return output;
}
