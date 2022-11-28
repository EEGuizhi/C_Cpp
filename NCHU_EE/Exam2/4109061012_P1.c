#include <stdio.h>
#include <stdlib.h>

#define MAX 1073741823
int main() {
	int n1, m1;
	int n2, m2;
	int i, j, k;  // n1 x m2
	// int mar1[1000][1000], mar2[1000][1000],  mar3[1000][1000];
	
	// input
	scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
	int mar1[n1][m1], mar2[n2][m2], mar3[n1][m2];
	
	
	for(i=0; i<n1; i++) {
		for(j=0; j<m1; j++) {
			scanf("%d", &mar1[i][j]);
		}
	}
	for(i=0; i<n2; i++) {
		for(j=0; j<m2; j++) {
			scanf("%d", &mar2[i][j]);
		}
	}
	
	// init
	for(i=0; i<n1; i++) {
		for(j=0; j<m2; j++) {
			mar3[i][j] = 0; 
		}
	}
	
	// calc
	for(i=0; i<n1; i++) {
		for(j=0; j<m2; j++) {
			for(k=0; k<m1; k++) {
				mar3[i][j] += mar1[i][k] * mar2[k][j];
			}
		}
	}
	
	// output
	for(i=0; i<n1; i++) {
		for(j=0; j<m2; j++) {
			printf("%d ", mar3[i][j]);
		}
		printf("\n"); 
	}
	
	return 0;
} 
