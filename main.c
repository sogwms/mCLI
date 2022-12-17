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

static int entry(void *p, int argc, const char **argv, itf_writer_t *outobj)
{
    itf_string_writer_t stringWriter;

    itf_string_writer_init_by_writer(&stringWriter, outobj);
    ITF_CALL(&stringWriter, write, "my echo command def: \r\n");

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

int testMCLI()
{
    void *ins = mcli_new(&writer);

    {
        char inputText[] = "echo hello world hahah";
        mcli_input(ins, strlen(inputText), inputText);
    }
    // {
    //     char inputText[] = "myecho";
    //     mcli_input(ins, sizeof(inputText), inputText);
    // }
    // {
    //     char inputText[] = "myecho2";
    //     mcli_input(ins, sizeof(inputText), inputText);
    // }
    {
        itf_command_t myechocmd;
        myechocmd.entry = entry;
        mcli_register_cmd(ins, "myecho", &myechocmd);
        char inputText[] = "myecho hello world";
        inputText[sizeof(inputText) - 1] = 'f';
        mcli_input(ins, sizeof(inputText), inputText);
    }
}

int main(int argc, char **argv)
{
    testMCLI();

    return 0;
}
