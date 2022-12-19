#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1000];
    int i, n = 0;
    
    // input
    scanf("%d", &n);
    scanf("%s", &str);
    
    // output
	for(i=0; i<n; i++) {
		if(str[n] == 'A')
	    	printf("T");
		else if(str[n] == 'T')
		    printf("A");
		else if(str[n] == 'C')
	    	printf("G");
		else if(str[n] == 'G')
		    printf("C");
    }
    
    return 0;
}
