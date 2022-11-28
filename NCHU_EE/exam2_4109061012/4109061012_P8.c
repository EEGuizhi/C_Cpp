#include <stdio.h>
#include <stdlib.h>

#define MAX 51
// 題目說句尾為 '?' 或 '.' 或 '!' 

int main() {
	int i, j, flag, words, max_len, len[MAX] = {0};
	char str[MAX][MAX] = {0}, end_char, ch;
	
	// input
	flag = 1;
	for(i=0; flag; i++) {
		j = 0;
		while(1) {
			ch = getchar();
			if(ch == ' ' || ch == '?' || ch == '!' || ch == '.') {
				if(ch == '?' || ch == '!' || ch == '.') {
					end_char = ch;
					flag = 0;  // the end of sentence
				}
				if(j == 0)
					i -= 1;  // not a word
				break;
			}
			else {
				str[i][j] = ch;
				len[i] += 1;  // word length
				j += 1;  // next ch
			}
		}
	}
	words = i;
	
	// output
	for(i=words-1; i>=0; i--) {
		printf("%s", str[i]);
		if(i>0)
			printf(" ");
	}
	printf("%c\n", end_char);  // end of the sentence
	
	max_len = 0;
	for(i=0; i<words; i++) {  // find max. length of words
		if(len[i] > max_len)
			max_len = len[i];
	}
	for(i=0; i<words; i++) {
		if(len[i] == max_len)
			printf("%s", str[i]);
	}
	
	return 0;
} 
