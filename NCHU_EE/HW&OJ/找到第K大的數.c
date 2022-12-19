#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int len) {
	int i, j, tmp;
	for(i=1; i<len; i++) {
		for(j=0; j<len-i; j++) {
			if(arr[j+1] < arr[j]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main() {
	int arr[1000];
	int len, i, k;
	
	// input
	scanf("%d", &len);
	for(i=0; i<len; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	
	//calc
	bubble_sort(arr, len);
	
	//output
	printf("%d ", arr[len-k]);
	
	return 0;
}
