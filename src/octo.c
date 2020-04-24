#include <cli/cli.h>
#include <stdio.h>

int main(int argc, char *const argv[]) {
  octo_cli_opt opt;
  printf("Hello Octo !!\n");
  cli(argc, argv, &opt);
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
