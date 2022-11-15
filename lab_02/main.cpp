#include "utilities.h"
#include "findSmlstCnsq.h"

int main() {
    numArr arr;
    numArr *res;

    switch (inputArray(&arr)) {
        case -1:
            printf("Ошибка! Некорректный ввод количества элементов.");
            return -1;
        case -2:
            printf("Ошибка! Нехватает памяти.");
            return -2;
        case -3:
            printf("Ошибка! Некорректный ввод элементов.");
            freeArr(arr);
            return  -3;
    }

    res = findSmlstCnsqs(arr);

    //    printArr(*res);
    printf("Длина серии чисел, не являющихся локальными экстремумами: %d\n", res->len);

    freeArr(arr);
    free(res);

    return 0;
}

