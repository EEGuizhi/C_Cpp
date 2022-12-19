#include <stdio.h>
#include <stdlib.h>

void bubble_sort(long long int arr[], int len) {
	int i, flag = 0;
	long long int tmp;
	
	for(i=0; i<len-1; i++) {
		if(arr[i+1] < arr[i]) {
			tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
			flag = 1;
		}
	}
	
	if(flag == 1 && len > 1) {
		bubble_sort(arr, len-1);
	}
}


int main() {
	int n, i, flag, flag2;
	
	scanf("%d", &n);
	long long int a[n+1], tmp;
	
	
	for(i=0; i<n; i++) {
		scanf("%lld", &a[i]);
	}
	bubble_sort(a, n);
	a[n] = a[n-1] + 1;
	
	flag = 1;  // check repeat value
	flag2 = 0;  // check output
	tmp = a[0] - 1;  // previous value
	for(i=0; i<=n; i++) {
		if(a[i] == tmp) {
			flag = 1;
		}
		else {
			if(flag == 0) {
				if(flag2 == 1)
					printf(" ");
				printf("%lld", tmp);
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
