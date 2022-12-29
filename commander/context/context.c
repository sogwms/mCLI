#include <stddef.h>
#include "context.h"
#include "uio.h"

static void *get_userdata(cctx_t *ctx)
{
    if (ctx == NULL)
        return NULL;

    ccontext_data_t *ud = (ccontext_data_t *)ctx->p;
    return ud->cmd_ud;
}

static itf_writer_t *get_writer(cctx_t *ctx)
{
    if (ctx == NULL)
        return NULL;
    ccontext_data_t *ud = (ccontext_data_t *)(ctx->p);
    return ud->writer;
}

void ccontext_init(cctx_t *ctx, ccontext_data_t *ud)
{
    if (ctx == NULL)
        return;

    ctx->p = ud;
    ctx->get_writer = get_writer;
    ctx->get_userdata = get_userdata;
}