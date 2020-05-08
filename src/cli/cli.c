#include <cli/cli.h>
#include <getopt.h>
#include <io/logger.h>
#include <stdio.h>
#include <stdlib.h>

const char *usage =
    "Usage : octo (-i input_file | --input input_file) input_file (-O | -o "
    "output_file) [ -h | --help ] [ -p | --verbose ]";

void check_io(octo_cli_t *opt) {
  if (opt->input == NULL) {
    octo_ERR(CLI, "missing input file");
    octo_ERR(CLI, usage);
    exit(1);
  }
  if (opt->flags[F_OUT]) {
    opt->output = "out.bin";
  } else {
    if (opt->output == NULL) {
      octo_ERR(CLI, "missing output file");
      octo_ERR(CLI, usage);
      exit(1);
    }
  }
}

void default_opt(octo_cli_t *opt) {
  opt->input = NULL;
  opt->output = NULL;
  for (int i = 0; i < N_FLAGS; i++) {
    opt->flags[i] = false;
  }
}

void cli(int argc, char *const argv[], octo_cli_t *opt) {
  int c, option_index;
  char *msg = NULL;

  static struct option long_options[] = {
      {"version", no_argument, NULL, 'V'},
      {"verbose", no_argument, NULL, 'v'},
      {"help", no_argument, NULL, 'h'},
      {"input", required_argument, NULL, 'i'},
      {"output", required_argument, NULL, 'o'},
      {0, 0, 0, 0}};

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
      opt->flags[F_OUT] = true;
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
      octo_ERR(CLI, usage);
      exit(1);
    }
  }

  if (optind < argc) {
    while (optind < argc) {
      sprintf(msg, "unexpected argument %s", argv[optind++]);
      octo_warn(CLI, opt, msg);
    }
  }

  check_io(opt);
}