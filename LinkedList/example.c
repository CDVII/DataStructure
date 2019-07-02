#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// float, double같은 부동소수점 데이터 타입은 따로 구조체로 만들어서 사용한다.
typedef struct _data {
    float f;
    double d;
}data;

int main(void) {
    int size = 3, i;
    unsigned int ui;
    data *d;

    linkedlist *ll = creat_list();

    for (i = 65; i < 65 + size; ++i)
        add_list_first(ll, (void*)i);
    while (!is_list_empty(ll))
        printf("char value is : %c\n", (char)remove_list_first(ll));

    for (i = 12345678; i < 12345678 + size; ++i)
        add_list_first(ll, (void*)i);
    while (!is_list_empty(ll))
        printf("longlong value is : %lld\n", (long long)remove_list_last(ll));

    for (i = 0; i < size; ++i) {
        ui = (unsigned int)(i * 10.0);
        add_list_last(ll, (void*)ui);
    }
    while (!is_list_empty(ll))
        printf("unsigned int value is %u\n", (unsigned int)remove_list_first(ll));

    for (i = 1; i < 1 + size; ++i) {
        d = (data*)malloc(sizeof(data));
        d->f = (float)(i * 1.0);
        d->d = i * 1.0;
        add_list_last(ll, (void*)d);
    }
    while (!is_list_empty(ll)) {
        d = (data*)remove_list_last(ll);
        printf("data float is %f, double is %lf\n", (float)d->f, (double)d->d);
        free(d);
    }

    delete_list(ll);
    return 0;
}