#include <cli/cli.h>
#include <stdio.h>

int main(int argc, char *const argv[]) {
  octo_cli_opt opt;
  cli(argc, argv, &opt);

  // Just for tests...
  printf("-----------------------------\n");
  printf("        CLI - RECAP          \n");
  printf("-----------------------------\n");
  printf("-> flag VERBOSE : %s \n", opt.flags[F_VERBOSE] ? "set" : "unset");
  printf("-> flag VERSION : %s \n", opt.flags[F_VERSION] ? "set" : "unset");
  printf("-> flag HELP    : %s \n", opt.flags[F_HELP] ? "set" : "unset");
  printf("-> INPUT        : %s \n", opt.input);
  printf("-> OUTPUT       : %s \n", opt.output);
  return 0;
}
