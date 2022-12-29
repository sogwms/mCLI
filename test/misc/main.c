#include <stdio.h>
#include <time.h>
#include "mcli.h"

static int write(void *p, const uint8_t *buf, int length)
{
    for (int i = 0; i < length; i++)
    {
        putchar(buf[i]);
    }

    return 0;
}

static itf_writer_t writer = {
    .p = &writer,
    .write = write,
};

static int myechocmd_entry(cctx_t *ctx, int argc, const char **argv)
{
    itf_writer_t *w = ITF_CALL(ctx, get_writer);
    itf_string_writer_t _sw, *sw = &_sw;
    itf_string_writer_init_by_writer(sw, w);

    ITF_CALL(sw, write, "my echo command def: \r\n");

    for (int i = 1; i < argc; i++)
    {
        ITF_CALL(sw, write, argv[i]);
        if (i < argc)
        {
            ITF_CALL(sw, write, " ");
        }
    }

    return 0;
}

int testMCLI()
{
    void *ins = mcli_new(&writer);

    {
        char inputText[] = "echo hello world hahah";
        mcli_input(ins, inputText, sizeof(inputText));
    }
    {
        char inputText[] = "myecho";
        mcli_input(ins, inputText, sizeof(inputText));
    }
    {
        char inputText[] = "myecho2";
        mcli_input(ins, inputText, sizeof(inputText));
    }
    {
        mcli_register_cmd(ins, "myecho", myechocmd_entry, NULL);
        char inputText[] = "myecho hello world";
        // inputText[sizeof(inputText) - 1] = 'f';
        mcli_input(ins, inputText, sizeof(inputText));
    }
}

int main(int argc, char **argv)
{
    testMCLI();
    return 0;
}
