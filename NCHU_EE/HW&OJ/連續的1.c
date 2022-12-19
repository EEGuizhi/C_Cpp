#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

main () {
	unsigned long long int n;
	scanf("%d", &n);
	
	int i = 0, last_p, max = 0;
	while (n > 0) {
		int p = 0;
		while (pow(2, p) <= n) {
			p += 1;
		}
		p -= 1;
		
		n -= pow(2, p);
		if(last_p-1 == p)
			i +=1 ;
		else
			i = 1;
		last_p = p;
		
		if(i > max)
			max = i;
	}

	printf("%d", max);
}



