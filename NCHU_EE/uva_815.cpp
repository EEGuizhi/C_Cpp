#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n, elv[30][30], water;
	int i, j;
	
	while(1) {
		scanf("%d %d", &m, &n);  // inputs
		if(m == 0 && n == 0)
			break;
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				scanf("%d", &elv[i][j]);
			}
		}
		scanf("%d", water);
		
		
	}
	
	return 0;
}
