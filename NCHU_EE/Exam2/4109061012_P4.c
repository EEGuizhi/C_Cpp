#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, len, i, j, tmp;
	int arr1[200] = {0}, arr2[200] = {0};
	
	// input
	scanf("%d %d", &n, &m);
	len = n + m;
	for(i=0; i<n; i++) {
		scanf("%d", &arr1[i]);
	}
	for(i=0; i<m; i++) {
		scanf("%d", &arr2[i]);
	}
	
	// combine
	for(i=n; i<len; i++) {
		arr1[i] = arr2[i-n];
	}
	
	// calc
	for(i=1; i<len; i++) {
		for(j=0; j<len-i; j++) {
			if(arr1[j+1] < arr1[j]) {
				tmp = arr1[j];
				arr1[j] = arr1[j+1];
				arr1[j+1] = tmp;
			}
		}
	}
	
	// output
	for(i=0; i<len; i++) {
		printf("%d ", arr1[i]);
	}
	
	return 0;
} 
