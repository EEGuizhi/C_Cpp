#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, len, words = 0, word_len = 0, max_word = 0;
	char str[100];
	
	// input
	len = 0;
	while(1) {
		str[len] = getchar();
		if(str[len] == '\n')
			break;
		len += 1;
	}
	
	// prevent error
	str[len] = 0;
	len += 1;
	
	/* =============== Problem (a) =============== */
	for(i=0; i<len; i++) {
		if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			word_len += 1;
		else {
			if(word_len > 0)
				words += 1;

			if(word_len > max_word)
				max_word = word_len;
			
			word_len = 0;
		}
	}
		
	printf("\n>> (a) The number of words in the sentence is : %d,\n  The maximal length : %d", words, max_word);
	
}
