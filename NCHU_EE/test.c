// TEST
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEN 10

int main() {
    int arr[LEN][LEN] = {0};  // fill the entire array with number 0, its same for 1D or 2D or... array
    int i, j, str_len;
    char str[1000];
    bool flag = 1;  // bcz line 9 included <stdbool.h>, we can use "bool" type

    for(i=0; i<LEN; i++) {
        for(j=0; j<LEN; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    if(flag) {
        printf("\n>> true\n");
    }

    scanf("%[^*\n]%*c", &str);  // input the char until we key in the '\n' character
    str_len = strlen(str);  // easily get the string's length by the func in <string.h>
    // printf(">> string: %s, string length: %d", str, str_len);

    i = 0;
    while (1)
	{
        scanf("%c", &str[i]);
        if(str[i] == '\n')
            break;
		str_len += 1;
	}
    // printf("\n>> %d", str_len);

    return 0;
}
