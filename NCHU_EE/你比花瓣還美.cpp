#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

main () {
    int n;
    scanf("%d", &n);

    int p[1000];
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }

    int result = 0;
    float ave, sum;
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = i; j < n; j++) {
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
}
