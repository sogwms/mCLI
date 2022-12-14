#ifndef __TRIE_H__
#define __TRIE_H__

#include <stdbool.h>
#include <def/def_container.h>

#define CMDNAME_MAX_LENGTH 16

#ifdef _WIN32
#pragma warning(disable : 4820)
#endif
typedef struct trie_node
{
    struct trie_node *parent;
    struct trie_node *child;
    struct trie_node *sib;
    char data;
    bool isDone;
    void *ud;
} trie_node_t;

typedef struct
{
    itf_container_t itf;
    trie_node_t root;
} trie_t;

int trie_add_cmd(trie_node_t *t, const char *name, void *ud);
trie_node_t *trie_find_command_node(trie_node_t *p, const char *s);
int trie_list_all_commands(trie_node_t *p);
trie_node_t *trie_find_mathced_node(trie_node_t *p, const char *s, int *matchedCnt);
void trie_init(trie_t *t);
void trie_deinit(trie_t *t);
void trie_node_init(trie_node_t *n);

#endif
