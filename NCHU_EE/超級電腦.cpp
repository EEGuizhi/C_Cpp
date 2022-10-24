#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n, output[32];
    
    scanf("%x", &n);
    for(int i=0; i<32; i++) {
    	output[i] = n % (int)pow(2, i+1) / (int)pow(2, i);
	}
	
	for(int i=1; i<=32; i++) {
		//printf("%d", output[32-i]);
		if(output[32-i] == 1)
			printf("*");
		else
			printf("-");
	}
}

