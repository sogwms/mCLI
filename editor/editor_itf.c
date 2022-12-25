#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "editor_itf.h"
#include "editor.h"
#include "uio.h"

#ifdef _WIN32

#pragma warning(disable : 4820)
#pragma warning(disable : 5045)

#endif

typedef struct
{
    itf_editor_t itf;
    itf_controller_t *ctrler;
    itf_writer_t *outobj;
    editor_t editor;
} editor_itf_t;
#include <stdio.h>
static int input(void *p, char *buf, int len)
{
    if (p == NULL)
        return -1;
    editor_itf_t *self = p;

    int es;
    for (int i = 0; i < len; i++)
    {
        es = editor_inputc(&self->editor, buf[i]);
        if (es == EDITOR_STATUS_NEW)
        {
            const char *_buf = editor_get_sentence(&self->editor);
            ITF_CALL(self->ctrler, input, (int)(strlen(_buf)), _buf);
        }
    }

    return 0;
}

static int set_outobj(void *p, itf_writer_t *writer)
{
    if (p == NULL)
        return -1;
    editor_itf_t *self = p;
    self->outobj = writer;

    return 0;
}

itf_editor_t *editor_itf_new(itf_controller_t *ctrler, itf_writer_t *writer)
{
    editor_itf_t *editor = malloc(sizeof(editor_itf_t));
    memset(editor, 0, sizeof(editor_itf_t));

    editor_init(&editor->editor);

    editor->ctrler = ctrler;

    editor->itf.p = editor;
    editor->itf.input = input;
    editor->itf.set_outobj = set_outobj;

    ITF_CALL(&editor->itf, set_outobj, writer);

    return &editor->itf;
}