#include <string.h>
#include <stdio.h>
#include "echo.h"
#include "uio.h"
#include "util.h"

#pragma warning(disable : 5045)

static int entry(void *p, int argc, const char **argv, itf_writer_t *outobj)
{
    p = p;
    itf_string_writer_t stringWriter;

    itf_string_writer_init_by_writer(&stringWriter, outobj);

    for (int i = 1; i < argc; i++)
    {
        ITF_CALL(&stringWriter, write, argv[i]);
        if (i < argc)
        {
            ITF_CALL(&stringWriter, write, " ");
        }
    }

    return 0;
}

void echo_cmd_init(echo_cmd_t *p)
{
    p->name = "echo";
    p->cmd.entry = entry;
    p->cmd.p = p;
}