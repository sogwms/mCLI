#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "commander.h"
#include "container/trie_container.h"
#include "util.h"
#include "uio.h"
#include "context.h"

#ifdef _WIN32
#pragma warning(disable : 5045)
#endif

// internal representation (storage model) of a command
typedef struct
{
    void *ud;
    command_entry_t entry;
} commander_command_t;

int commander_init(commander_t *p, itf_writer_t *outobj)
{
    if (p == NULL)
        return 0;
    if (outobj == NULL)
        return -1;

    memset(p, 0, sizeof(commander_t));

    p->conta = trie_container_new();

    commander_set_outobj(p, outobj);

    return 0;
}

// internal data deinit
int commander_deinit(commander_t *p)
{
    // TODO
    trie_container_deinit(p->conta);
    free(p->conta);
    p->conta = NULL;

    return 0;
}

int commander_set_outobj(commander_t *p, itf_writer_t *outobj)
{
    p->outobj = outobj;
    return 0;
}

int commander_register(commander_t *p, const char *cmd_name, command_entry_t cmd, void *cmd_ud)
{
    int ret = 0;

    if (p == NULL)
        return 0;
    if (cmd == NULL)
        return 0;
    if (cmd_name == NULL)
        return 0;

    commander_command_t *ns = (commander_command_t *)malloc(sizeof(commander_command_t));
    memset(ns, 0, sizeof(commander_command_t));
    ns->ud = cmd_ud;
    ns->entry = cmd;

    ret = ITF_CALL(p->conta, add_command, cmd_name, ns);
    if (ret != 0)
        return ret;

    p->counter_cmd++;

    return 0;
}

int commander_call(commander_t *p, const char *arg)
{
    if (p == NULL)
        return 0;
    if (arg == NULL)
        return 0;

    // TODO: abstract common functionality
    char *cmd_name = (char *)arg;
    char _last_letter = ' ';
    int _last_letter_idx = 0;
    for (int i = 0; i < (int)strlen(arg); i++)
    {
        if ((arg[i] == ' ') || (arg[i] == '\0'))
        {
            _last_letter = arg[i];
            _last_letter_idx = i;
            break;
        }
    }
    cmd_name[_last_letter_idx] = '\0';
    commander_command_t *cmd = p->conta->find_command(p->conta->p, cmd_name);
    cmd_name[_last_letter_idx] = _last_letter;

    if (cmd != NULL)
    {
        if (cmd->entry != NULL)
        {
            cctx_t cctx;
            ccontext_data_t _ctx;
            _ctx.cmd_ud = cmd->ud;
            _ctx.writer = p->outobj;
            ccontext_init(&cctx, &_ctx);
            return cmd->entry(&cctx, arg);
        }
    }
    else
    {
        itf_string_writer_t stringWriter;
        itf_string_writer_init_by_writer(&stringWriter, p->outobj);
        ITF_CALL(&stringWriter, write, "\r\n");
        cmd_name[_last_letter_idx] = '\0';
        ITF_CALL(&stringWriter, write, cmd_name);
        cmd_name[_last_letter_idx] = _last_letter;

        ITF_CALL(&stringWriter, write, ": command not found\r\n");
    }

    return 0;
}
