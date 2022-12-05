#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bubble_sort(long long int arr[], int len) {
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
	int n, i, flag = 1, flag2 = 0;
	
	scanf("%d", &n);
	long long int a[n+1], tmp;
	
	
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	bubble_sort(a, n);
	a[n] = (long long int)pow(2, 32);
	
	tmp = (long long int)pow(2, 32);
	for(i=0; i<=n; i++) {
		if(a[i] == tmp) {
			flag = 1;
		}
		if(a[i] != tmp) {
			if(flag == 0) {
				printf("%d", tmp);
				if(i < n)
					printf(" ");
				flag2 = 1;
			}
			else
				flag = 0;
		}
		tmp = a[i];
	}
	
	if(flag2 == 0)
		printf("None");
	
	return 0;
}
