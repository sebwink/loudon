#ifndef LOUDON_HEAP_H
#define LOUDON_HEAP_H

typedef struct Heap_ {
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    void **tree;
} Heap;

void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2), void (*destroy)(void *data));
void heap_destroy(Heap *heap);
int heap_insert(Heap *insert, const void *data);
int heap_extract(Heap *insert, void **data);

#define heap_size(heap) ((heap)->size)

#endif
