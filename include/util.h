#pragma once

/**
 * @brief Converts a pixel value to rem units.
 *
 * @param pxValue The value in pixels.
 * @return The equivalent value in rem (assuming 16px base).
 */
float pxToRem(int pxValue);

/**
 * @brief Calculates the slope for a CSS clamp function.
 *
 * @param maxViewport The maximum viewport width in rem.
 * @param minViewport The minimum viewport width in rem.
 * @param maxValue The maximum CSS value in rem.
 * @param minValue The minimum CSS value in rem.
 * @return The slope used in the fluid scaling calculation.
 */
float getClampSlope(float maxViewport, float minViewport, float maxValue, float minValue);

/**
 * @brief Calculates the y-axis intercept for a CSS clamp function.
 *
 * @param slope The slope from getClampSlope().
 * @param minValue The minimum CSS value in rem.
 * @return The y-axis intercept in rem.
 */
float getClampYAxis(float slope, float minValue);

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
