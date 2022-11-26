#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1000][20], tmp, end_ch = 0;
    int i, j, word;

    // input & get numbers of words in sentence
    word = 0;
    j = 0;
    while(1) {
		scanf("%c", &tmp);
		if(tmp == '\n' || tmp == '\r' || tmp == 0)
			break;
		else {
			if(tmp == ' ') {
				word += 1;
				j = 0;
			}
			else {
				str[word][j] = tmp;
				str[word][j+1] = 0;
				j += 1;
			}
		}
	}

    // check last char
    if(str[word][j-1]<(int)'A' || (str[word][j-1]>(int)'Z' && str[word][j-1]<(int)'a') || str[word][j-1]>(int)'z') {
        end_ch = str[word][j-1];
        str[word][j-1] = 0; //null
    }


    // output
    for(i=word; i>=0; i--) {
		printf("%s", str[i]);
		if(i > 0)
			printf(" ");
	}
    printf("%c", end_ch);
    
    return 0;
}
