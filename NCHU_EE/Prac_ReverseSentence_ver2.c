#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[10][20], tmp, end_ch = 0;
    int i, j, words, flag1, flag2;

    // input
    flag1 = 1;
    for(i=0; flag1; i++) {
		flag2 = 1;
		for(j=0; flag2; j++) {
			scanf("%c", &str[i][j]);

			if(str[i][j] == '\n' || str[i][j] == 0) {
				flag1 = 0;
			}
			
			if(str[i][j]<65 || (str[i][j]>90 && str[i][j]<97) || str[i][j]>122) {
				flag2 = 0;
    			str[i][j] = 0;  // null char
			}	
		}
	}
	words = i - 1;

	// output
	for(i=words; i>=0; i--) {
		printf("%s ", str[i]);
	}

    return 0;
}
