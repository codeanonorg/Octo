#include <cli/cli.h>
#include <io/disas.h>
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
  disas_x86((unsigned char *)"\x55\x48\x8b\x05\xb8\x13\x00\x00", 9);
  return 0;
}
