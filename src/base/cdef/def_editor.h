#ifndef __DEF_EDITOR_H__
#define __DEF_EDITOR_H__

#include <stdint.h>
#include "def_io.h"

typedef struct
{
    void *p;
    int (*input)(void *p, const char *buf, int len);
    int (*set_outobj)(void *p, itf_writer_t *writer);
} itf_editor_t;

#endif