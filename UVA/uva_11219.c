// Title: How old are you?  ,  Verdict: Accepted
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, age;
    int by, bm, bd, cy, cm, cd;

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d/%d/%d %d/%d/%d", &cd, &cm, &cy, &bd, &bm, &by);
        
        age = cy - by - 1;
        if(cm > bm || (cm == bm && cd >= bd)) {
            age += 1;
        }

        if(age < 0) {
            printf("Case #%d: Invalid birth date\n", i+1);
        }
        else if(age > 130) {
            printf("Case #%d: Check birth date\n", i+1);
        }
        else {
            printf("Case #%d: %d\n", i+1, age);
        }
    }

    return 0;
}
