#ifndef CLI_H
#define CLI_H

#define F_VERSION 0b1000000000000000
#define F_HELP 0b0100000000000000
#define F_DEBUG 0b0010000000000000

typedef struct {
  char *input;
  char *output;
  unsigned short flags;
} octo_cli_opt;

int cli(int argc, char const *argv[], octo_cli_opt *opt);

void delete_opt(octo_cli_opt **);

#endif