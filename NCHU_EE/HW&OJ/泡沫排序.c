#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, N[100], tmp;
    scanf("%d ", &n);
    
    for(i=0; i<n; i++) {
    	scanf("%d", &N[i]);
	}
	
	for(i=1; i<n; i++) {
		for(j=1; j<n; j++) {
			if(N[j] < N[j-1]) {
				tmp = N[j-1];
				N[j-1] = N[j];
				N[j] = tmp;
			}
		}
	}
	
	for(i=0; i<n; i++) {
		printf("%d ", N[i]);
	}
	
	return 0;
}
