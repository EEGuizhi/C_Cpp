#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int bubble_sort(int arr[], int len) {
	int i, flag = 0, tmp, times = 0;
	
	for(i=0; i<len-1; i++) {
		times += 1;
		if(arr[i+1] < arr[i]) {
			tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
			flag = 1;
		}
	}
	
	if(flag == 1 && len > 1) {
		times += bubble_sort(arr, len-1);
	}
	
	return times;
}

int main() {
	int n, arr[MAX] = {0}, i, times;
	
	// input
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	
	// calc
	times = bubble_sort(arr, n);
	
	// output
	printf("%d\n", times);
	for(i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
} 
