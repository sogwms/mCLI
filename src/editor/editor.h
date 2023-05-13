#ifndef __EDITOR_H__
#define __EDITOR_H__

#define INTERNAL_BUFFER_CAPACITY 1024

enum
{
    EDITOR_STATUS_NONE = 0,
    EDITOR_STATUS_NEW,
};

// todo: use dynamic array
typedef struct
{
    char buf[INTERNAL_BUFFER_CAPACITY];
    int bufidx;
    int fsm_status;
    int status;
} editor_t;

// todo: brief
int editor_inputc(editor_t *p, char c);
// todo: brief
int editor_get_status(editor_t *p);

void editor_init(editor_t *p);

const char *editor_get_sentence(editor_t *p);

#endif // __EDITOR_H__