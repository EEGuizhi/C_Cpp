#include <stdio.h>
#include <stdlib.h>


void sum(char n[], int pow) {
	if(n[pow] == '1') {
		n[pow] = '0';
		sum(n, pow+1);
	}
	else {
		n[pow] = '1';
	}
}


void show(char n[]) {
	int i = 0;
	while(n[i] != 0) {
		i++; 
	}
	i -= 1;
	while(i >= 0) {
		printf("%c", n[i]);
		i--;
	}
}


int main() {
	int n, m, i;
	char n1[130] = {0}, n2[130] = {0};
	
	// input & calc
	scanf("%d %d", &n, &m);
	getchar();  // for the '\n'
	
	for(i=0; i<n; i++) {
		n1[n-i-1] = getchar();
	}
	getchar();  // for the '\n'
	
	for(i=0; i<m; i++) {
		n2[m-i-1] = getchar();
		if(n2[m-i-1] == '1')
			sum(n1, m-i-1);
	}
	
	// output
	show(n1);
	
	return 0;
} 
