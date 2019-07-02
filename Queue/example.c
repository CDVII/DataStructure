#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// float, double같은 부동소수점 데이터 타입은 따로 구조체로 만들어서 사용한다.
typedef struct _data {
    float f;
    double d;
}data;

int main(void) {
    int size = 3, i;
    unsigned int ui;
    data *d;

    queue *q = creat_queue();

    for (i = 0; i < size; ++i) {
        ui = (unsigned int)(i * 10.0);
        enqueue_queue(q, (void*)ui);
    }
    while (!is_queue_empty(q))
        printf("unsigned int value is %u\n", (unsigned int)dequeue_queue(q));

    for (i = 1; i < 1 + size; ++i) {
        d = (data*)malloc(sizeof(data));
        d->f = (float)(i * 1.0);
        d->d = i * 1.0;
        enqueue_queue(q, (void*)d);
    }
    while (!is_queue_empty(q)) {
        d = (data*)dequeue_queue(q);
        printf("data float is %f, double is %lf\n", (float)d->f, (double)d->d);
        free(d);
    }

    delete_queue(q);

    return 0;
}