#ifndef LOUDON_ISORT_H
#define LOUDON_ISORT_H
      
int isort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

#endif
