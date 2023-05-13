#include <stddef.h>
#include <string.h>
#include "editor.h"

enum
{
    FSM_STATUS_EMPTY = 0, // the initial status
    FSM_STATUS_TEXT,      //
    FSM_STATUS_DONE,
};

// todo: deal overflow
static void _append(editor_t *p, char c)
{
    p->buf[p->bufidx++] = c;
}

// todo: brief
int editor_inputc(editor_t *p, char c)
{
    if (p == NULL)
        return 0;

    switch (p->fsm_status)
    {
    case FSM_STATUS_EMPTY:
    __sentry:
        if (!(c == '\n' || c == '\r' || c == '\0'))
        {
            _append(p, c);
            p->fsm_status = FSM_STATUS_TEXT;
        }
        break;
    case FSM_STATUS_TEXT:
        if (c == '\n' || c == '\r' || c == '\0')
        {
            p->fsm_status = FSM_STATUS_DONE;
        }
        else
        {
            _append(p, c);
        }
        break;
    case FSM_STATUS_DONE:
        p->fsm_status = FSM_STATUS_EMPTY;
        p->bufidx = 0;
        goto __sentry;
        break;

    default: // should never happen
        p->fsm_status = FSM_STATUS_EMPTY;
    }

    return editor_get_status(p);
}

// todo: brief
int editor_get_status(editor_t *p)
{
    if (p == NULL)
        return EDITOR_STATUS_NONE;

    if (p->fsm_status == FSM_STATUS_DONE)
    {
        return EDITOR_STATUS_NEW;
    }

    return EDITOR_STATUS_NONE;
}

void editor_init(editor_t *p)
{
    if (p == NULL)
        return;
    memset(p, 0, sizeof(editor_t));
}

const char *editor_get_sentence(editor_t *p)
{
    if (p == NULL)
        return NULL;

    _append(p, '\0');
    return p->buf;
}