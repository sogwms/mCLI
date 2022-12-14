#include <string.h>
#include "cdef/def_io.h"
#include "util.h"

static int write_string_by_writer(void *p, const char *s)
{
    itf_writer_t *writer = (itf_writer_t *)p;
    if (writer == NULL)
        return -1;

    int length = (int)strlen(s);
    return ITF_CALL(writer, write, (const uint8_t *)s, length);
}

void itf_string_writer_init_by_writer(itf_string_writer_t *sw, itf_writer_t *w)
{
    sw->p = w;
    sw->write = write_string_by_writer;
}