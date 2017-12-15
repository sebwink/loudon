#ifndef LOUDON_QSORT_H
#define LOUDON_QSORT_H

int qksort(void *data, int size, int esize, int i, int k,
           int (*compare)(const void *key1, const void *key2));

#endif
