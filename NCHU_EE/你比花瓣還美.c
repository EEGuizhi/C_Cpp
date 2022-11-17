#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main () {
    int n, i, j, p[1000], result = 0;
	float ave, sum;
	    
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }

    for(i = 0; i < n; i++) {
        sum = 0;
        for(j = i; j < n; j++) {
            sum += p[j];
            ave = sum / (j+1-i);

            for(int k = i; k < j+1; k++) {
                if((int)(ave*100) == p[k]*100) {
                    result += 1;
                    break;
				}
            }
        }
    }

    printf("%d", result);
    
    return 0;
}
