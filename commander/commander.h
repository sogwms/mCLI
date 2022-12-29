#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include "cdef/def_commander.h"
#include "cdef/def_command.h"
#include "def/def_container.h"

#ifdef _WIN32
#pragma warning(disable : 4820)
#endif

typedef struct
{
    itf_writer_t *outobj;
    itf_container_t *conta;
    int counter_cmd;
} commander_t;

int commander_init(commander_t *p, itf_writer_t *outobj);
int commander_deinit(commander_t *p);
int commander_set_outobj(commander_t *p, itf_writer_t *outobj);
int commander_register(commander_t *p, const char *cmd_name, command_entry_t cmd, void *cmd_ud);
int commander_call(commander_t *p, int argc, const char **argv);

#endif