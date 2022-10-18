#include <stdio.h>
#include <stdlib.h>

main() {
    char str[30];
    int n = 0;
    int flag = 1;
    
	while(1) {
    	scanf("%c", &str[n]);
    	if(str[n] < 48 || str[n] > 57)
    		break;
    		
    	n += 1;
	}
	
	for(int i=0; i<(n/2 + 1); i++) {
		if(str[i] != str[n-1-i])
			flag = 0;
	}
    
    if(flag)
		printf("YES");
	else
		printf("NO");
}
