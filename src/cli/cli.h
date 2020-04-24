#ifndef CLI_H
#define CLI_H

#define F_VERSION 1
#define F_HELP 2
#define F_DEBUG 4

typedef struct {
  char *input;
  char *output;
  unsigned short flags;
} octo_cli_opt;

int cli(int argc, char *const argv[], octo_cli_opt *opt);

void delete_opt(octo_cli_opt **);

#endif