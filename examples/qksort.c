#include <stdio.h>

#include <loudon/qksort.h>

int intcmp(const void *key1, const void *key2) {
    if (*(int *)key1 == *(int *)key2)
        return 0;
    else
        return *(int *)key1 < *(int *)key2 ? -1 : 1;
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
    qksort(a, 10, sizeof(int), 0, 9, intcmp);
    printa(a, 10);
}
