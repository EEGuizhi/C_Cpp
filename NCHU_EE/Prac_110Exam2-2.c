#include <stdio.h>
#include <stdlib.h>

# define LEN 100
int main() {
	int i, words, max_wordlen, flag;
	char str[LEN][30];
	int len[LEN];
	
	// init
	for(i=0; i<LEN; i++) {
		len[i] = 0;
	}

	// input
	flag = 1;
	for(words=0; flag; words++) {
		i = 0;
		while(1) {
			scanf("%c", &str[words][i]);
			
			if((str[words][i] >= 65 && str[words][i] <= 90) || (str[words][i] >= 97 && str[words][i] <= 122)) {
				i += 1;
				len[words] += 1;
			}
			else {
				if(str[words][i] == '\n' || str[words][i] == 0)  // finish input
					flag = 0;
				str[words][i] = 0;  // null char
				if(i == 0)
					words -= 1;
				break;
			}
		}
	}
	
	/* =============== Problem (a) =============== */
	max_wordlen = 0;
	for(i=0; i<words; i++) {
		if(len[i] > max_wordlen)
			max_wordlen = len[i];
	}
	printf("\n>> (a) The number of words in the sentence is : %d,\n>>     The maximal length : %d", words, max_wordlen);
	
}
