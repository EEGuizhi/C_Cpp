// 4109061012 ³¯¬fµ¾ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
    int tmp, i, j;
    int arr[100];
    
    // generate numbers
    srand((unsigned) time(NULL));
    for(i=0; i<100; i++) {
    	arr[i] = rand() % 1000;
	}
	
	// bubble sort
	for(i=0; i<100; i++) {
    	for(j=0; j<100-j-1; j++) {
    		if(arr[j+1] < arr[j]) {
    			tmp = arr[j+1];
    			arr[j+1] = arr[j];
    			arr[j] = tmp;
			}
		}
	}
	
	// output
	for(i=0; i<100; i++) {
		printf("%d ", arr[i]);
	}
}
