#ifndef __MCLI_H__
#define __MCLI_H__

#include "cdef/def_io.h"
#include "cdef/def_command.h"
#include "util.h"

void *mcli_new(itf_writer_t *writer);
int mcli_input(void *p, char *buf, int length);
int mcli_register_cmd(void *p, const char *cmd_name, command_entry_t cmd, void *cmd_ud);

#endif