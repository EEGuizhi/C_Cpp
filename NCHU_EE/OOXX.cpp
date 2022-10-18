#include <stdio.h>
#include <stdlib.h>

main() {
    int n, conti = 0, score = 0;
    char ox[80];
    scanf("%d ", &n);
    
    for(int i=0; i<n; i++) {
    	scanf("%c", &ox[i]);
    	if(ox[i] == 'O') {
    		conti += 1;
    		score += conti;
		}
		else {
			conti = 0;
		}
	}
	
	printf("%d", score);
}
