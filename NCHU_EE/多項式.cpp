#include <stdio.h>
#include <stdlib.h>

main() {
	int n1, n2, c1[100], c2[100], final[100];
	
	// input
	scanf("%d", &n1);
	for(int i=0; i<n1; i++) {
		scanf("%d", &c1[n1-i-1]);
	}
	scanf("%d", &n2);
	for(int i=0; i<n2; i++) {
		scanf("%d", &c2[n2-i-1]);
	}
	
	// clear
	for(int i=0; i<n1+n2; i++) {
		final[i] = 0;
	}
	
	// calc
	for(int i=0; i<n1; i++) {
		for(int j=0; j<n2; j++) {
			final[i+j] += c1[i] * c2[j];
		}
	}
	
	// output
	for(int i=0; i<n1+n2-1; i++) {
		printf("%d ", final[n1+n2-2-i]);
	}
}
