#include <string.h>
#include <stdio.h>
#include "echo.h"
#include "uio.h"
#include "util.h"

#ifdef _WIN32
#pragma warning(disable : 5045)
#endif

static int entry(cctx_t *ctx, const char *arg)
{
    itf_writer_t *w = ITF_CALL(ctx, get_writer);
    itf_string_writer_t _sw, *sw = &_sw;
    itf_string_writer_init_by_writer(sw, w);
    ITF_CALL(sw, write, arg);

    return 0;
}

void echo_cmd_init(echo_cmd_t *p)
{
    p->name = "echo";
    p->entry = entry;
}