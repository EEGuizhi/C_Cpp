#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n, max;
	int s[50] = {0}, gap[50] = {0};
	
	// input
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &s[i]);
	}
	
	// calc
	for(i=0; i<n; i++) {
		max = 0;
		
		// find max
		for(j=0; j<n; j++) {
			if(i != j) {
				if(s[j] > max) {
					max = s[j];
				} 
			}
		}
		
		// output
		printf("%d ", s[i]-max);
	}
	
	return 0;
} 
