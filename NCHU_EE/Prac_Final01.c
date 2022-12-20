/* Problem:
    輸入兩字串(字串中可能含有空白字元)，請寫一個function，
    計算並回傳兩字串的長度差，
    且使用指標將短字串合併至長字串後方，
    最後在main()中計算合併後的字串中有多少空白字元。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80  // 假設輸入字串最長80字元

int merge(char *short_str, char *long_str) {
    int diff = 0;
    char *ch_ptr;

    ch_ptr = long_str;
    while(*ch_ptr) {
        diff += 1;  // long str len
        ch_ptr++;
    }

    while(*short_str) {
        diff -= 1;  // minus short str len
        *ch_ptr = *short_str;  // copy
        short_str++;
        ch_ptr++;
    }

    return diff;
}

int main() {
    int len1 = 0, len2 = 0, num, i;
    char str1[2*MAX_LEN + 1], str2[2*MAX_LEN + 1];

    // inputs
    while(1) {
        str1[len1] = getchar();
        if(str1[len1] == '\n') {  // enter
            str1[len1] = 0;
            break;
        }
        len1 += 1;
    }
    while(1) {
        str2[len2] = getchar();
        if(str2[len2] == '\n') {  // enter
            str2[len2] = 0;
            break;
        }
        len2 += 1;
    }

    // merge
    if(len1 > len2) {
        num = merge(str2, str1);
        printf("%d\n%s\n", num, str1);

        num = 0;
        for(i=0; str1[i]; i++) {
            if(str1[i] == ' ')
                num += 1;
        }
    }
    else {
        num = merge(str1, str2);
        printf("%d\n%s\n", num, str2);

        num = 0;
        for(i=0; str2[i]; i++) {
            if(str2[i] == ' ')
                num += 1;
        }
    }
    printf("%d", num);

    return 0;
}
