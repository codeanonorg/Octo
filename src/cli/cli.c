#include <cli/cli.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int cli(int argc, char *const argv[], octo_cli_opt *opt) {
  int c;
  static int verbose_flag = 0;
  static int help_flag = 0;

  static struct option long_options[] = {
      {"verbose", no_argument, NULL, 'p'},
      {"help", no_argument, NULL, 'h'},
      {"input", required_argument, NULL, 'i'},
      {"output", required_argument, NULL, 'o'},
      {0, 0, 0, 0}};

  int option_index = 0;

  while ((c = getopt_long(argc, argv, "i:o:Ovh", long_options,
                          &option_index)) != -1) {
    switch (c) {
    case 'i':
      printf("[i] is set to %s\n", optarg);
      break;
    case 'o':
      printf("[o] is set to %s\n", optarg);
      break;
    case 'O':
      printf("[O] is set (overwriting -o)\n");
      break;
    case 'h':
      printf("[h] is set\n");
      break;
    case '?':
      printf(
          "Usage : %s (-i input_file | --input input_file) input_file (-O | -o "
          "output_file) [ -h | --help ] [ -p | --verbose ]\n",
          argv[0]);
      break;
    default:
      fprintf(stderr, "An unexpected CLI error occurs\n");
      exit(1);
    }
  }

  return 0;
}