#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
    int tmp, i, j, num = 0;
    int arr[100];

    // generate numbers
    srand((unsigned) time(NULL));
    for(i=0; i<100; i++) {
    	arr[i] = rand() % 1001;  // Not larger than 1000
	}

	// bubble sort
	for(i=1; i<100; i++) {
    	for(j=0; j<100-i; j++) {
			num += 1;
    		if(arr[j+1] < arr[j]) {
    			tmp = arr[j+1];
    			arr[j+1] = arr[j];
    			arr[j] = tmp;
			}
		}
	}

	// output
	for(i=0; i<100; i++) {
		printf("%3d ", arr[i]);
	}
	printf("\nNumber of comparsions: %d", num);
}
