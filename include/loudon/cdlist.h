#ifndef LOUDON_CDLIST_H
#define LOUDON_CDLIST_H

#include <stdlib.h>

typedef struct CDListElmt_ {
    void *data;
    struct CDListElmt_ *prev;
    struct CDListElmt_ *next;
} CDListElmt;

typedef struct CDList_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    CDListElmt *head;
} CDList;

void cdlist_init(CDList *list, void (*destroy)(void *data));
void cdlist_destroy(CDList *list);
int cdlist_ins_next(CDList *list, CDListElmt *element, const void *data);
int cdlist_ins_prev(CDList *list, CDListElmt *element, const void *data);
int cdlist_remove(CDList *list, CDListElmt *element, void **data);

#define cdlist_size(list) ((list)->size)
#define cdlist_head(list) ((list)->head)
#define cdlist_tail(list) ((list)->head->prev) // necessary?
#define cdlist_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define cdlist_is_tail(list, element) ((element) == (list)->head->prev ? 1 : 0) // necessary?
#define cdlist_data(element) ((element)->data)
#define cdlist_next(element) ((element)->next)
#define cdlist_prev(element) ((element)->prev)

#endif
