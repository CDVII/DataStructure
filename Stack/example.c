#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// float, double같은 부동소수점 데이터 타입은 따로 구조체로 만들어서 사용한다.
typedef struct _data {
    float f;
    double d;
}data;

int main(void) {
    int size = 3, i;
    unsigned int ui;
    data *d;

    stack *s = creat_stack();

    for (i = 0; i < size; ++i) {
        ui = (unsigned int)(i * 10.0);
        push_stack(s, (void*)ui);
    }
    while (!is_stack_empty(s))
        printf("unsigned int value is %u\n", (unsigned int)pop_stack(s));

    for (i = 1; i < 1 + size; ++i) {
        d = (data*)malloc(sizeof(data));
        d->f = (float)(i * 1.0);
        d->d = i * 1.0;
        push_stack(s, (void*)d);
    }
    while (!is_stack_empty(s)) {
        d = (data*)pop_stack(s);
        printf("data float is %f, double is %lf\n", (float)d->f, (double)d->d);
        free(d);
    }

    delete_stack(s);
    return 0;
}