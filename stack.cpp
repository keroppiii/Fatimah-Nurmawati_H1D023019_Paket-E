#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100

typedef struct {
    int item[MAXSTACK];
    int count;
} stack;

void membuatstack(stack *x) {
    x->count = 0;
}

int isFull(stack *x) {
    return x->count >= MAXSTACK;
}

int isEmpty(stack *x) {
    return x->count == 0;
}

void push(int data, stack *x) {
    if (isFull(x)) {
        printf("Stack Penuh\n");
    } else {
        x->item[x->count] = data;
        x->count++;
    }
}

void pop(stack *x) {
    if (isEmpty(x)) {
        printf("Stack Kosong\n");
    } else {
        x->count--;
    }
}

void cetak(stack *x) {
    printf("Bilangan ganjil yang ada di stack: ");
    for (int i = x->count - 1; i >= 0; i--) {
        printf("%d ", x->item[i]);
    }
    printf("\n");
}

int main() {
    stack tumpukan;
    membuatstack(&tumpukan);

    int n;
    printf("Masukkan n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n * 2; i += 2) {
        push(i, &tumpukan);
    }

    cetak(&tumpukan);

    return 0;
}