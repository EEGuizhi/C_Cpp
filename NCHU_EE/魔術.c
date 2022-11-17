#include <stdio.h>
#include <stdlib.h>

int calc(int i, int j, int k) {
    int sum;
    sum = 100*i + 10*k + j
        + 100*k + 10*i + j
        + 100*k + 10*j + i
        + 100*j + 10*i + k
        + 100*j + 10*k + i;

    return sum;
}

int main() {
    int n, i, j, k;

    scanf("%d", &n);
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            for(k=0; k<10; k++) {
                if(calc(i, j, k) == n) {
                    printf("%d %d %d", i, j, k);
                    return 0;
                }
            }
        }
    }

    return 0;
}
