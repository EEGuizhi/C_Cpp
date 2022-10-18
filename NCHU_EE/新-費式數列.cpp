#include <stdio.h>
#include <stdlib.h>

main() {
	int n;
    long long int f[24], new_f[24];
    
    for(int i=0; i<24; i++) {
		if(i>=0 && i<2)
        	f[i] = 1;
    	else
        	f[i] = f[i-1] + f[i-2];
	}
	
	for(int i=0; i<23; i++) {
		new_f[i] = f[i] * f[i+1];
	}
	
	scanf("%d", &n);
	printf("%d", new_f[n-1]);
}
