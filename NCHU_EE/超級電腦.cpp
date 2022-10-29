#include <stdio.h>

int main() {
    unsigned int n, output[32];
    
    scanf("%x", &n);
    for(int i=0; i<32; i++) {
    	if(n%2 == 0)
    		output[i] = 0;
    	else
    		output[i] = 1;
    	n /= 2;
	}

	for(int i=1; i<=32; i++) {
		//printf("%d", output[32-i]);
		if(output[32-i] == 1)
			printf("*");
		else
			printf("-");
	}
}

