#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, len, words, word_len, max_word;
	char str[100];
	
	// input
	len = 0;
	while(1) {
		str[i] = getchar();
		if(str[i] == '\n')
			break;
		len += 1;
	}
	printf("%d", len);
	
	/* =============== Problem (a) =============== */
//	words = 0;
//	max_word = 0;
//	word_len = 0;
//	for(i=0; i<len; i++) {
//		if(str[i] != ' ')
//			word_len += 1;
//		else {
//			words += 1;
//			if(word_len > max_word)
//				max_word = word_len;
//			
//			word_len = 0;
//		}
//	}
//	// last word
//	words += 1;
//	if(word_len > max_word)
//		max_word = word_len;
		
	printf("\n>> The number of words in the sentence is : %d,  The maximal length : %d", words, max_word);
	
}
