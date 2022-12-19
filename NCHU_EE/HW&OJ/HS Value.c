#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j, a;
	int happy, sad, len;
	int digits[32];
	
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &a);
		len = 0;
		while(a > 0) {  // input
			digits[len] = a % 10;
			a /= 10;
			len += 1;
		}
		
		happy = 0;  // calc happy value
		for(j=0; j<len; j++) {
			happy += digits[len-j-1] * (j + 1);
		}
		
		sad = 0;  // calc sad value
		for(j=0; j<len; j++) {
			sad += digits[j] * (j + 1);
		}
		
		printf("%d %d\n", happy, sad);
		if(happy > sad)
			printf("%d", happy - sad);
		else
			printf("%d", sad - happy);
		if(i < n-1)
			printf("\n");
	}
	
	return 0;
}
