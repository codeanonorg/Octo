#ifndef LOGGER_H
#define LOGGER_H

#include <cli/cli.h>
#include <stdio.h>

/**
 * @brief Utils for logging
 *
 */

/**
 * @brief Log sources
 *
 */
typedef enum { LOG, INTERNAL, IO, CLI } octo_log_t;

/**
 * @brief Log a message
 *
 * @param src       Source of the log
 * @param opt       Cli option
 * @param out_chan  Output channel
 * @param ind       Indicator to prefix the message with
 * @param msg       The message to log
 */
void octo_log(octo_log_t src, octo_cli_t *opt, FILE *out_chan, const char *ind,
              const char *msg);

/**
 * @brief Log a message in stderr with indicator "Warning"
 *
 */
void octo_warn(octo_log_t, octo_cli_t *, const char *);

/**
 * @brief Log a message in stderr with indicator "Error"
 *
 */
void octo_err(octo_log_t, octo_cli_t *, const char *);

/**
 * @brief Same as octo_log but forces output even if verbose mode is disabled.
 *
 */
void octo_LOG(octo_log_t, FILE *, const char *, const char *);

/**
 * @brief Same as octo_warn but forces output even if verbose mode is disabled.
 *
 */
void octo_WARN(octo_log_t, const char *);

/**
 * @brief Same as octo_err but forces output even if verbose mode is disabled.
 *
 */
void octo_ERR(octo_log_t, const char *);

#endif