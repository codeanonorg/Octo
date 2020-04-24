#include <cli/cli.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage() {
  fprintf(
      stderr,
      "Usage : octo (-i input_file | --input input_file) input_file (-O | -o "
      "output_file) [ -h | --help ] [ -p | --verbose ]\n");
}

void check_io(octo_cli_opt *opt) {
  if (opt->input == NULL) {
    fprintf(stderr, "[octo-cli] missing input file\n");
    print_usage();
    exit(1);
  }
  if (opt->flags[F_OUT]) {
    opt->output = "octo_out";
  } else {
    if (opt->output == NULL) {
      fprintf(stderr, "[octo-cli] missing output file\n");
      print_usage();
      exit(1);
    }
  }
}

void default_opt(octo_cli_opt *opt) {
  opt->input = NULL;
  opt->output = NULL;
  for (int i = 0; i < N_FLAGS; i++) {
    opt->flags[i] = false;
  }
}

void cli(int argc, char *const argv[], octo_cli_opt *opt) {
  int c;

  static struct option long_options[] = {
      {"version", no_argument, NULL, 'V'},
      {"verbose", no_argument, NULL, 'v'},
      {"help", no_argument, NULL, 'h'},
      {"input", required_argument, NULL, 'i'},
      {"output", required_argument, NULL, 'o'},
      {0, 0, 0, 0}};

  int option_index = 0;

  while ((c = getopt_long(argc, argv, "i:o:OvhV", long_options,
                          &option_index)) != -1) {
    switch (c) {
    case 'i':
      opt->input = optarg;
      break;
    case 'o':
      opt->output = optarg;
      break;
    case 'O':
      opt->output = optarg;
      break;
    case 'h':
      opt->flags[F_HELP] = true;
      break;
    case 'v':
      opt->flags[F_VERSION] = true;
      break;
    case 'V':
      opt->flags[F_VERBOSE] = true;
      break;
    default:
      print_usage();
      exit(1);
    }
  }

  if (optind < argc) {
    while (optind < argc)
      printf("[octo-cli] unexpected argument : %s\n", argv[optind++]);
    print_usage();
    exit(1);
  }

  check_io(opt);
}