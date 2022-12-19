#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double a, b;
	
	scanf("%lf %lf", &a, &b);
	a = sqrt(a);
	b = sqrt(b);
	
	if(a > (double)(int)a)  // floor
		a += 1;
	printf("%d", (int)b - (int)a + 1);
	
	return 0;
} 
