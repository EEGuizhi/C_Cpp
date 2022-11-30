#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LEN 10

void show(int* arr, int len) {
    int i;

    for(i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* n1, int* n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}


void quick_sort(int* arr, int low, int high) {
    int L = low, R = high;

    while(1) {
        while(arr[R] >= arr[L] && R > L) {
            R -= 1;
        }
		if(L == R) {
            break;
        }
        swap(&arr[L], &arr[R]);
        show(arr, LEN);

        while(arr[L] <= arr[R] && L < R) {
            L += 1;
        }
		if(L == R) {
            break;
        }
        swap(&arr[R], &arr[L]);
        show(arr, LEN);
    }

    if((L-1)-low > 0)
        quick_sort(arr, low, L-1);
    if(high-(R+1) > 0)
        quick_sort(arr, R+1, high);
}


int main() {
    int arr[LEN], i;

    srand((unsigned) time(NULL));
    for(i=0; i<LEN; i++) {
        arr[i] = rand() % 100;
    }
    printf(">> Init:\n");
    show(arr, LEN);
    printf("\n");

    quick_sort(arr, 0, LEN-1);
    printf("\n>> Result:\n");
    show(arr, LEN);

    return 0;
}
