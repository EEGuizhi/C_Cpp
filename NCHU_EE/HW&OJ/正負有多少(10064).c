#include <stdio.h>
#include <stdlib.h>

int main() {
  	int n, i, pos, neg, num;
	
	// input & calc
  	scanf("%d", &n);
  	
	pos = 0;
	neg = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &num);
		if(num < 0)
			neg += 1;
		else if(num > 0)
			pos += 1;
	}
 
  	// output
  	printf("%d %d", pos, neg);
  	
  	return 0;
}

