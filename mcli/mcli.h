#ifndef __MCLI_H__
#define __MCLI_H__

#include "cdef/def_io.h"
#include "cdef/def_command.h"
#include "util.h"

void *mcli_new(itf_writer_t *writer);
int mcli_input(void *p, int length, char *buf);
int mcli_register_cmd(void *p, const char *cmd_name, itf_command_t *cmd);

#endif