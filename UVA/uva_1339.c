// Title: Ancient Cipher, Verdict: Accepted, Run Time: 0.000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char* str1, char* str2, int len) {
    int ab1[26] = {0}, ab2[26] = {0};
    int i, j;
    for(i=0; i<len; i++) {
        ab1[str1[i] - 'A'] += 1;
    }
    for(i=0; i<len; i++) {
        ab2[str2[i] - 'A'] += 1;
    }
    for(i=0; i<26; i++) {
        if(ab1[i] != 0) {
            for(j=0; j<26; j++) {
                if(ab1[i] == ab2[j]) {
                    ab2[j] = 0;
                    ab1[i] = 0;
                    break;
                }
            }
        }
    }
    for(i=0; i<26; i++) {
        if(ab1[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    char engrave[101], origin[101], end_ch;
    int len_en, len_or, i, j;

    while(scanf("%s %s", &engrave, &origin) != EOF) {
        len_en = strlen(engrave);
        len_or = strlen(origin);

        if(len_en != len_or) {
            printf("NO\n");
        }
        else {
            if(check(engrave, origin, len_en))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
