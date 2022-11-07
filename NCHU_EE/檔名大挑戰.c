#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, flag;
	char str[100];
	
	// input
	scanf("%s", &str);
	
	// check
	flag = 0;
	for(i = 0; i < 100; i++) {
		if(str[i] == '.') {
			if((str[i+1] == 'c') && str[i+2] == 0) {
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	
	return 0;
} 
