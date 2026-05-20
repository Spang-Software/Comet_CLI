#pragma once

/**
 * @brief Converts a pixel value to rem units.
 *
 * @param pxValue The value in pixels.
 * @return The equivalent value in rem (assuming 16px base).
 */
float pxToRem(int pxValue);

/**
 * @brief Generates a CSS clamp() string for fluid responsive sizing.
 *
 * @param maxViewport Pointer to the maximum viewport width in pixels.
 * @param minViewport Pointer to the minimum viewport width in pixels.
 * @param maxValue The maximum CSS value in pixels.
 * @param minValue The minimum CSS value in pixels.
 * @return A statically allocated string containing the CSS clamp() expression.
 */
char* getClamp(int *maxViewport, int *minViewport, int maxValue, int minValue);
