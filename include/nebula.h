#pragma once
/**
 * @brief Clones Nebula CSS from github into current working directory.
 *
 * @param cwd Pointer to current working directory.
 * @return 0 if secessful, 1 if errored.
 */
int cloneNebula(char *cwd);

/**
 * @brief updates the minified Nebula CSS file in the current directory.
 *
 * @param cwd Pointer to current working directory.
 * @return 0 if secessful, 1 if errored.
 */
int updateNebula(char *cwd);

/**
 * @brief Removes the cloned Nebula CSS folder from the current directory.
 *
 * @param cwd Pointer to current working directory.
 * @return 0 if secessful, 1 if errored.
 */
int cleanNebula(char *cwd);
