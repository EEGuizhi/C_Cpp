#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int num;
    struct item *nextPtr;
} item;

int main() {
    item itm01;
    printf(">> itm01 position is: %p\n", &itm01);  // 0062FE00
    printf(">> size is: %d\n\n", sizeof(itm01));

    item itm02;
    printf(">> itm02 position is: %p\n", &itm02);  // 0062FDF0
    printf(">> size is: %d\n\n", sizeof(itm02));

    itm01.nextPtr = &itm02;
    printf(">> nextPtr of itm01 is: %p\n\n", itm01.nextPtr);  // 0062FDF0

    item *itemPtr;
    itemPtr = &itm01;
    printf(">> new itemPtr: %p\n", itemPtr -> nextPtr);  // 0062FDF0

    return 0;
}
