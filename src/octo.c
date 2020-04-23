#include <cli/cli.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  octo_cli_opt opt;
  printf("Hello Octo !!\n");
  cli(argc, argv, &opt);
  return 0;
}
