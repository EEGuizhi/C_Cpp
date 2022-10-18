#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
	unsigned int n, lsb;
	int times;
    
    scanf("%x", &n);
    scanf("%d", &times);
	
	for(int i=0; i<times; i++) {
		if(n%2 == 1)
			lsb = 1;
		else
			lsb = 0;
			
		n = n >> 1;
		if(lsb)
			n += pow(2, 31); 
	}

	printf("0x%x", n);
}
