#include <stdio.h>
#include <stdlib.h>

int main() {
	unsigned long long int n, m, i;
	
	// input
	scanf("%d %d", &n, &m);
	
	// calc
	for(i=1; i<m; i++) {
		n *= 2;
	}
	
	// output
	printf("%d", n);
	
	return 0;
} 
