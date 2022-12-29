#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "cdef/def_cmd_ctx.h"
#include "cdef/def_io.h"

typedef struct
{
    itf_writer_t *writer;
    void *cmd_ud;
} ccontext_data_t;

void ccontext_init(cctx_t *ctx, ccontext_data_t *ud);

#endif