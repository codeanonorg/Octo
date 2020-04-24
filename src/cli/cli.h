#ifndef CLI_H
#define CLI_H

#include <stdbool.h>

#define F_VERSION 0
#define F_VERBOSE 1
#define F_HELP 2
#define F_OUT 3
#define N_FLAGS 4

typedef struct {
  char *input;
  char *output;
  bool flags[4];
} octo_cli_opt;

int cli(int argc, char *const argv[], octo_cli_opt *opt);

void delete_opt(octo_cli_opt **);

#endif