/*
Disscuss:
    1st win:
        N-0 >= 1  &&　N-0 <= M  -->  N >= 1+(0~0M)  &&  N <= M+(0~0M)
        N-(1~M) >= 2  &&  N-(1~M) <=2M  -->  N >= 2+(1~M)  &&  N <= 2M+(1~M)
        N-(2~2M) >= 3  &&  N-(2~2M) <=3M  -->  N >= 3+(2~2M)  &&  N <= 3M+(2~2M)

        (1) N < M+1
        (2) N == M+2  ||  N == 2M+1

        1, 1~M, M:   N > M+1  &&  N <= M+2
        M, 1~M, M:   N <= 2M+1  &&  N > 2M

    2nd win:
        N-(1~M) >= 1  &&  N-(1~M)  <= M  -->  N >= 1+(1~M)  &&  N <= M+(1~M)
        N-(2~2M) >= 2  &&  N-(2~2M)  <= 2M  -->  N >= 2+(2~2M)  &&  N <= 2M+(2~2M)
        conclusion: N >= i+(i~i*M) && N <= i*M+(i~i*M)

        (1) N == M+1


    conclusion: N >= i+(i~i*M) && N <= i*M+(i~i*M)  會是後者勝
    對手拿最小 ==>   N >= i+(i) && N <= i*M+(i)        ==>    N >= 2*i && N <= i*(M+1)
    對手拿最大 ==>   N >= i+(i*M) && N <= i*M+(i*M)    ==>    N >= i*(1+M) && N <= i*(2*M)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned n, m, i, flag = 0;

    scanf("%d %d", &n, &m);
    for(i=0; i<=n/(m+1); i++) {
        if((n >= 2*i && n <= i*(m+1)) &&
           (n >= i*(m+1) && n <= i*(2*m)))
            flag = 1;
    }

    if(flag)
        printf("Lose");
    else
        printf("Win");

    return 0;
}
