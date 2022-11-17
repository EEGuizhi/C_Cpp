#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, num, sum = 0;

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &num);
        sum += num * (i+1);
    }
    
    printf("%d", sum);

    return 0;
}
