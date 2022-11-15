#ifndef LAB_02_UTILITIES_H
#define LAB_02_UTILITIES_H

#endif //LAB_02_UTILITIES_H

#include <cstdlib>
#include <iostream>

typedef struct {
    float* pointer;
    int len;
} numArr;

int inputArray (numArr* arr);

void printArr (numArr arr);

void freeArr(numArr arr);

void copyArr (numArr* from, numArr* to);

void addNumToArr (float value, numArr* to);

void nullArr (numArr* arr);
