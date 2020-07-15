#ifndef CLI_H
#define CLI_H

#include <stdbool.h>

#define F_VERSION 0
#define F_VERBOSE 1
#define F_HELP 2
#define F_OUT 3
#define N_FLAGS 4

/**
 * @brief Structure holding input informations
 *
 */
typedef struct {
  char *input;
  char *output;
  bool flags[N_FLAGS];
} octo_cli_t;

/**
 * @brief Run the CLI
 *
 * @param argc  Number of arguments
 * @param argv  Array of arguments
 * @param opt   Input information structure
 */
void cli(int argc, char *const argv[], octo_cli_t *opt);

/**
 * @brief Destruct an opt structure
 *
 */
void delete_opt(octo_cli_t **);

/**
 * @brief Initialize an opt structure with default values
 *
 */
void default_opt(octo_cli_t *);

#endif