#include <stdio.h>
#include <math.h>
#include "util.h"

float pxToRem(int pxValue) {
    float remValue = pxValue / 16.00f;
    return remValue;
}

float getClampSlope(float maxViewport, float minViewport, float maxValue, float minValue) {
    float slope = (maxValue - minValue) / (maxViewport - minViewport);
    return slope;
}

float getClampYAxis(float slope, float minValue) {
    float yAxis = (minValue * -1.0f) * slope + minValue;
    return yAxis;
}

char* getClamp(int *maxViewport, int *minViewport, int maxValue, int minValue) {
    static char output[128];
    float maxValueRem = pxToRem(maxValue);
    float minValueRem = pxToRem(minValue);
    float maxViewportRem = pxToRem(*maxViewport);
    float minViewportRem = pxToRem(*minViewport);

    float slope = getClampSlope(maxViewportRem, minViewportRem, maxValueRem, minValueRem);
    float yAxis = getClampYAxis(slope, minValueRem);

    snprintf(output, sizeof(output), "clamp(%grem, (%.3frem + %gvw), %grem)", minValueRem, yAxis, roundf(slope * 1000) / 10, maxValueRem);

    return output;
}
