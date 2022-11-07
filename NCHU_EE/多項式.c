#include <stdio.h>
#include <stdlib.h>

main() {
	int i, j, n1, n2, c1[1000], c2[1000], final[1000];
	
	// input
	scanf("%d", &n1);
	for(i=0; i<n1; i++) {
		scanf("%d", &c1[n1-i-1]);
	}
	scanf("%d", &n2);
	for(i=0; i<n2; i++) {
		scanf("%d", &c2[n2-i-1]);
	}
	
	// clear
	for(i=0; i<n1+n2; i++) {
		final[i] = 0;
	}
	
	// calc
	for(i=0; i<n1; i++) {
		for(j=0; j<n2; j++) {
			final[i+j] += c1[i] * c2[j];
		}
	}
	
	// output
	for(i=0; i<n1+n2-1; i++) {
		printf("%d ", final[n1+n2-2-i]);
	}
}
