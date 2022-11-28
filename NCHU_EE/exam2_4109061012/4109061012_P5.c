#include <stdio.h>
#include <stdlib.h>

int main() {
	int t, n, i, j;
	char cmd, data[100000] = {0}, p, q;
	
	// input
	scanf("%d %d", &t, &n);
	for(i=0; i<n; i++) {
		scanf(" %c", &data[i]);
	}
	
	// main
	for(i=0; i<t; i++) {
		scanf(" %c", &cmd);
		if(cmd == 'a') {
			for(j=0; j<n; j++) {
				data[j] = '_';
			}
		}
		else if(cmd == 'b') {
			scanf(" %c", &p);
			for(j=0; j<n; j++) {
				if(data[j] == p)
					data[j] = '_';
			}
		}
		else if(cmd == 'c') {
			scanf(" %c %c", &p, &q);
			for(j=0; j<n; j++) {
				if(data[j] == p)
					data[j] = q;
			}
		}
	}
	
	// output
	for(i=0; i<n; i++) {
		printf("%c ", data[i]); 
	} 
	
	return 0;
} 
