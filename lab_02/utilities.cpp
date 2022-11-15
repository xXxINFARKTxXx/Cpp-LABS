#include "utilities.h"

int inputArray (numArr* arr) {
    printf("Введите количество элементов:");
    if(!scanf("%d", &arr->len) || arr->len <= 0)
        return -1;

    arr->pointer = (float*)(calloc(sizeof(float) * arr->len, sizeof(float)));
    if(!arr->pointer)
        return -2;

    printf("Введите элементы:");
    for(int i = 0; i < arr->len; i++)
        if(!scanf("%f", &arr->pointer[i]))
            return -3;

    return 0;
}

void printArr (numArr arr) {
    if(arr.len == 0) {
        printf("Пустая последовательность!\n");
        return;
    }
    for(int i = 0; i < arr.len; i++)
        printf("%f ", arr.pointer[i]);
}

void freeArr(numArr arr) {
    free(arr.pointer);
}

void copyArr (numArr* from, numArr* to) {
    to->len = from->len;
    memcpy(to->pointer, from->pointer, sizeof(float) * from->len );
}

void addNumToArr (float value, numArr* to) {
    to->pointer[to->len] = value;
    to->len++;
}

void nullArr (numArr* arr) {
    arr->len = 0;
}