#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, l, flag;
	int i, j, k;
	char str[1000], child[1000];
	
	scanf("%d", &n);
	scanf("%s", &str);
	
	l = 0;
	for(i = 0; i < n; i++) {
		// append
		child[l] = str[i];
		l += 1;
		
		// check
		flag = 0;
		k = 0;
		while(k < n) {
			for(j = 0; j < l; j++) {
				if(child[j] != str[k]) {
					flag = 1;
					break;
				}
				k += 1;
			}
			
			if(flag)
				break;
		}
		
		// output
		if(flag == 0) {
			// 建議用此方式輸出 不要直接%s輸出 
			for(j = 0; j < l; j++) {
				printf("%c", child[j]);
			}
			break;
		}
	}
	
	return 0;
} 
