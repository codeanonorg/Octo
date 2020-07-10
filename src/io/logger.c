#include <io/logger.h>

char *log_src_to_string(octo_log_t log_src) {
  switch (log_src) {
  case LOG:
    return "octo";
  case INTERNAL:
    return "octo-internal";
  case IO:
    return "octo-io";
  case CLI:
    return "octo-cli";
  }
}

void octo_log(octo_log_t log_src, octo_cli_t *opt, FILE *out_chan,
              const char *indicator, const char *msg) {
  if (opt->flags[F_VERBOSE]) {
    octo_LOG(log_src, out_chan ? out_chan : stdout, indicator, msg);
  }
}

void octo_err(octo_log_t log_src, octo_cli_t *opt, const char *msg) {
  if (opt->flags[F_VERBOSE]) {
    octo_ERR(log_src, msg);
  }
}

void octo_warn(octo_log_t log_src, octo_cli_t *opt, const char *msg) {
  if (opt->flags[F_VERBOSE]) {
    octo_WARN(log_src, msg);
  }
}

void octo_LOG(octo_log_t log_src, FILE *out_chan, const char *indicator,
              const char *msg) {
  fprintf(out_chan, "[%s] %s : %s\n", log_src_to_string(log_src), indicator,
          msg);
}

void octo_WARN(octo_log_t log_src, const char *msg) {
  octo_LOG(log_src, stderr, "Warning", msg);
}

void octo_ERR(octo_log_t log_src, const char *msg) {
  octo_LOG(log_src, stderr, "Error", msg);
}