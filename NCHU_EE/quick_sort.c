// unfinished
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LEN 10

void swap(int* n1, int* n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}


void quick_sort(int* arr, int n1, int n2) {
    int L = n1, R = n2-1, i;
	bool flagL, flagR;
	
    while(L < R) {
    	flagL = 1;
    	flagR = 1;
    	while(flagL || flagR) {
    		if(arr[L] <= arr[n2] && L < R)
    			L += 1;
			else
				flagL = 0;

    	    if(arr[R] >= arr[n2] && L < R)
        	    R -= 1;
        	else
        		flagR = 0;
		}
        
        if(L != R) {
        	swap(&arr[L], &arr[R]);	
    		printf("\n");
    		for(i=0; i<LEN; i++) {
        		printf("%d ", arr[i]);
    		}
		}   
    }
    if(arr[L] > arr[n2]) {
        swap(&arr[L], &arr[n2]);
        
    	printf("\n");
    	for(i=0; i<LEN; i++) {
        	printf("%d ", arr[i]);
    	}
	}
    

    if((L-1)-n1 > 0)
        quick_sort(arr, n1, L-1);
    if(n2-(R+1) > 0)
        quick_sort(arr, R+1, n2);
}


int main() {
    int arr[LEN], i;

    srand((unsigned) time(NULL));
    for(i=0; i<LEN; i++) {
        arr[i] = rand() % 100;
    }
    for(i=0; i<LEN; i++) {
        printf("%d ", arr[i]);
    }

    quick_sort(arr, 0, LEN-1);
    printf("\n");
    for(i=0; i<LEN; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
