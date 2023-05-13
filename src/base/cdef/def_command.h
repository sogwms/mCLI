#ifndef __DEF_COMMAND_H__
#define __DEF_COMMAND_H__

#include "def_io.h"
#include "def_cmd_ctx.h"

/**
 * @ctx: command context handle
 */
typedef int (*command_entry_t)(cctx_t *ctx, const char *arg);

#endif