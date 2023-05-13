#ifndef __DEF_CMD_CTX_H__
#define __DEF_CMD_CTX_H__

#include "def_io.h"

typedef struct cctx
{
    void *p;
    void *(*get_userdata)(struct cctx *ctx);
    itf_writer_t *(*get_writer)(struct cctx *ctx);
} cctx_t;

#endif //