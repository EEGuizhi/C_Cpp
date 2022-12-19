#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, a[50], min, sum;
	
	// input
	scanf("%d", &n);
	
	min = 10000000; // 10^7 possible max. value
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		if(a[i] < min)
			min = a[i];
	}
	
	// calc
	sum = 0;
	for(i=0; i<n; i++) {
		if(a[i] > min)
			sum += a[i] - min;
	}
	
	// output
	printf("%d", sum);
		
	return 0;
}
