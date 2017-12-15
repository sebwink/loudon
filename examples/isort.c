#include <stdio.h>

#include <loudon/isort.h>

int intcmp(const void *key1, const void *key2) {
    return *(int *)key1 < *(int *)key2 ? 1 : -1;
}

void printa(int *a, int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char **argv) {
    int a[10] = {23, 2, 12, 34, 99, 1, -1, 12, 11, 0};
    printa(a, 10);
    printf("Sorting ... \n");
    isort(a, 10, sizeof(int), intcmp);
    printa(a, 10);
}
