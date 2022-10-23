#include <stdio.h>
#include <stdlib.h>

main() {
    int n, N[100], tmp;
    scanf("%d ", &n);
    
    for(int i=0; i<n; i++) {
    	scanf("%d", &N[i]);
	}
	
	for(int i=1; i<n; i++) {
		for(int j=1; j<n; j++) {
			if(N[j] < N[j-1]) {
				tmp = N[j-1];
				N[j-1] = N[j];
				N[j] = tmp;
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		printf("%d ", N[i]);
	}
}
