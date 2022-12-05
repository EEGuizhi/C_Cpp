#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, k, min, dif;

    scanf("%d %d", &n, &m);
    char str[n][m], tmp;
    
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            str[i][j] = getchar();
            if(str[i][j] == '\n' || str[i][j] == 0)
                j -= 1;
        }
    }

    min = 999 * 8;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i == j)
                break;
            else {
                dif = 0;
                for(k=0; k<m; k++) {
                    if(str[i][k] > str[j][k])
                        dif += (int)(str[i][k] - str[j][k]);
                    else {
                        dif += (int)(str[j][k] - str[i][k]);
                    }
                }
                if(dif < min)
                    min = dif;
            }
        }
    }

    printf("%d", min);

    return 0;
}
