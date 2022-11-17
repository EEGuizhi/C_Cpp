#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    unsigned long num[1000], min[2], max[2];
    float ave;

    min[0] = 429496729;
    min[1] = 429496729;
    max[0] = 1;
    max[1] = 1;

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &num[i]);
        
        ave += ((float)num[i] / (float)n);
        
        if(num[i] < min[0]) {
            min[1] = min[0];
            min[0] = num[i];
        }
        else if(num[i] < min[1]) {
        	min[1] = num[i];
		}
        
        if(num[i] > max[0]) {
            max[1] = max[0];
            max[0] = num[i];
        }
        else if(num[i] > max[1]) {
        	max[1] = num[i];
		}
    }

    printf("%d %d\n", max[1], min[1]);
    printf("%.2f", ave);
    
    return 0;
}
