#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1000], end_ch = '';
    int i, j, len = 0;

    // input & get str length
    scanf("%s",&str);
    while(str[len-1] != 0 && str[len] == 0) {
        len += 1;
    }


    // check last char
    if(str[len-1]<65 || (str[len-1]>90 && str[len-1]<97) || str[len-1]>122) {
        end_ch = str[len-1];
        str[len-1] = 0; //null
        len -= 1;
    }


    // output
    i = len-1;
    while(i > 0) {
        if(str[i-1] == ' ' || i == 0) {
            j = i;
            while(str[j] != ' ' && str[j] != 0) {
                printf("%c", str[j]);
                j += 1;
            }
            i -= 1;
        }
        else {
            i -= 1;
        }
    }
    printf("%c", end_ch);
    
    return 0;
}
