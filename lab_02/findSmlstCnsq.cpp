#include "utilities.h"

short isLocalExtremum (int index, numArr in);

numArr *findSmlstCnsqs(numArr arr) {
    numArr* res = (numArr*)malloc(sizeof (numArr));
    res->len = arr.len;
    res->pointer = (float*)malloc(sizeof(float) * arr.len);

    numArr buff;
    buff.len = 0;
    buff.pointer = (float*)malloc(sizeof(float) * arr.len);

    for (int i = 0; i < arr.len; i++) {
        if(isLocalExtremum(i, arr)) {
            if (res->len > buff.len && buff.len)
                copyArr(&buff, res);
            nullArr(&buff);
        }
        else {
            addNumToArr(arr.pointer[i], &buff);
        }
    }

    if (res->len > buff.len)
        copyArr(&buff, res);
    freeArr(buff);
    return res;
}

short isLocalExtremum (int index, numArr in) {
    if(index && index != in.len-1)
        if (in.pointer[index] < in.pointer[index + 1] && in.pointer[index] < in.pointer[index - 1] ||
        in.pointer[index] > in.pointer[index + 1] && in.pointer[index] > in.pointer[index - 1])
        return 1;

    return 0;
}

