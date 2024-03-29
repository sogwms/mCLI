#include <stdlib.h>
#include "commander_itf.h"
#include "commander.h"

typedef struct
{
    itf_commander_t itf;
    commander_t commander;
} commander_itf_t;

static int register_cmd(void *p, const char *cmd_name, command_entry_t cmd, void *cmd_ud)
{
    commander_itf_t *self = (commander_itf_t *)p;
    if (self == NULL)
        return -1;
    return commander_register(&self->commander, cmd_name, cmd, cmd_ud);
}
static int call(void *p, const char *arg)
{
    commander_itf_t *self = (commander_itf_t *)p;
    if (self == NULL)
        return -1;

    return commander_call(&self->commander, arg);
}
static int set_outobj(void *p, itf_writer_t *writer)
{
    commander_itf_t *self = (commander_itf_t *)p;
    if (self == NULL)
        return -1;
    return commander_set_outobj(&self->commander, writer);
}

itf_commander_t *commander_itf_new(itf_writer_t *outobj)
{
    commander_itf_t *cmder = malloc(sizeof(commander_itf_t));
    commander_init(&cmder->commander, outobj);

    // initialize public interface
    cmder->itf.p = cmder;
    cmder->itf.call = call;
    cmder->itf.register_cmd = register_cmd;
    cmder->itf.set_outobj = set_outobj;

    return &cmder->itf;
}

int commander_itf_deinit(itf_commander_t *p)
{
    // TODO
    // in case of warning
    p = p;
    return 0;
}