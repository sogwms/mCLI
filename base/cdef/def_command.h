#ifndef __DEF_COMMAND_H__
#define __DEF_COMMAND_H__

#include "def_io.h"
#include "def_cmd_ctx.h"

/**
 * @ctx: command context handle
 * @argc: indicate the number of arguments
 * @argv: arguments. the first argument is the command name
 */
typedef int (*command_entry_t)(cctx_t *ctx, int argc, const char **argv);

#endif