#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check(unsigned int n) {
	unsigned tmp, digit, count, i, j, l = 0;
	
	tmp = n;
	do {
		tmp /= 10;
		l += 1;
	} while(tmp > 0);
	
	for(i=0; i<l; i++) {
		digit = n / (int)pow(10, i) % (int)pow(10, i+1);
		tmp = n;
		count = 0;
		
		for(j=0; j<l; j++) {
			if(digit == tmp%10)
				count += 1;
			tmp /= 10;
		}
		if(count > 1)
			return 1;
	}
	return 0;
}

int main() {
	unsigned int n;
	
	scanf("%d", &n);
	
	if(check(n))
		printf("Repeated digits");
	else
		printf("No repeated digits");
		
	return 0;
}
