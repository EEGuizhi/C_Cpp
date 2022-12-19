#include <stdio.h>
#include <stdlib.h>

int main() {
	int G, L, a, b, flag = 0;
	
	scanf("%d %d", &G, &L);
	for(a=G; a<=L;) {
		for(b=a; b<=L;) {
			if((a/G)*(b/G)*G == L) {
				printf("%d %d", a, b);
				return 0;
			}
			b += G;
		}
		a += G;
	}

	printf("-1");
	return 0;
} 
