#include <stdio.h>
#include <stdlib.h>

int check(int a, int b, int G, int L) {
	int i;
	
	for(i=G+1; i<=a; i++) {
		if(a%i == 0 && b%i == 0)
			return 0;
	}
	
	for(i=L-1; i>=b; i--) {
		if(i%a == 0 && i%b == 0)
			return 0;
	}
	
	return 1;
}

int main() {
	int G, L, a, b, flag = 0;
	
	scanf("%d %d", &G, &L);
	for(a=G; a<=L;) {
		for(b=a; b<=L;) {
			if((b/G)%(a/G) == 0 && (a/G) != 1)
			else {
				if(check(a, b, G, L)) {
					printf("%d %d", a, b);
					return 0;
				}
			}
			b += G;
		}
		a += G;
	}
	
	printf("-1");
	return 0;
} 
