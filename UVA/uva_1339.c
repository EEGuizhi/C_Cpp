// Title: Ancient Cipher  , Correct: unkown
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
            // flag = 0;
            printf("NO\n");
        }
        else {
            // flag = check(engrave, origin, len_en);
            if(check(engrave, origin, len_en))
                printf("YES\n");
            else
                printf("NO\n");
            // end_ch = 'A';
            // for(i=0; i<len_en; i++) { // find max alphabet
            //     if(engrave[i] > end_ch) {
            //         end_ch = engrave[i];
            //     }
            // }

            // for(k=end_ch; k<='Z' && flag == 0; k++) {
            //     for(i=0; i<25; i++) { // 26個英文字母(no 'Z') 最多shift 25次
            //         if(check(engrave, origin, len_en)) {
            //             flag = 1;
            //             break;
            //         }

            //         for(j=0; j<len_en; j++) { // shift
            //             engrave[j] += 1;
            //             if(engrave[j] > k) {
            //                 engrave[j] -= k - 'A';
            //             }
            //         }
            //     }
            // }
        }

        // if(flag)
        //     printf("YES\n");
        // else
        //     printf("NO\n");
    }

    return 0;
}
