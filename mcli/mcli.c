#include "mcli.h"

#include <stdlib.h>
#include "commander_itf.h"
#include "controller_itf.h"
#include "editor_itf.h"
#include "builtin_command.h"

#include "util.h"

typedef struct
{
    itf_commander_t *cmder;
    itf_controller_t *ctrler;
    itf_editor_t *editor;
} mcli_t;

void *mcli_new(itf_writer_t *writer)
{
    itf_commander_t *cmder = commander_itf_new(writer);
    register_builtin_commands(cmder);
    itf_controller_t *ctrler = controller_itf_new(cmder, writer);
    itf_editor_t *editor = editor_itf_new(ctrler, writer);

    mcli_t *mcli = malloc(sizeof(mcli_t));
    mcli->cmder = cmder;
    mcli->ctrler = ctrler;
    mcli->editor = editor;

    return mcli;
}

int mcli_input(void *p, char *buf, int len)
{
    if (p == NULL)
        return -1;
    mcli_t *mcli = (mcli_t *)p;

    return ITF_CALL(mcli->editor, input, buf, len);
}

int mcli_register_cmd(void *p, const char *cmd_name, command_entry_t cmd, void *cmd_ud)
{
    if (p == NULL)
        return -1;
    mcli_t *mcli = (mcli_t *)p;

    return ITF_CALL(mcli->cmder, register_cmd, cmd_name, cmd, cmd_ud);
}
