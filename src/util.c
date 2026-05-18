#include <stdio.h>
#include "util.h"

float getSlope(int *maxViewport, int *minViewport, int maxValue, int minValue) {
    float slope = (*maxViewport - *minViewport) / (maxValue - minValue);
    return slope;
}

float calcYAxis(float slope, float maxValue) {
    float yAxis = (-1 * maxValue) * slope + maxValue;
    return yAxis; 
}

