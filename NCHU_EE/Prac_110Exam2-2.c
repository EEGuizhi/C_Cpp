#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

int anagram(char str1[], char str2[], int len1, int len2) {
	int i, ch[26] = {0};
	// int len1, len2;
	// len1 = strlen(str1);
	// len2 = strlen(str2);

	if(len1 == len2) {
		for(i=0; i<len1; i++) {
			ch[str1[i]-'a'] += 1;
		}
		for(i=0; i<len2; i++) {
			ch[str2[i]-'a'] -= 1;
		}
		for(i=0; i<26; i++) {
			if(ch[i] != 0)
				return 0;  // failed
		}
		return 1;  // success
	}
	else
		return 0;  // failed
}

# define LEN 100
int main() {
	int i, j, words, max_wordlen, flag;
	char str[LEN][30] = {0};
	int len[LEN] = {0};

	// input
	flag = 1;
	for(words=0; flag; words++) {
		i = 0;
		while(1) {
			str[words][i] = getchar();
			
			if(str[words][i] == ' ' || str[words][i] == '\n' || str[words][i] == '.' || str[words][i] == '!' || str[words][i] == '?' || str[words][i] == 0) {
				if(str[words][i] == '\n' || str[words][i] == 0)  // finish input
					flag = 0;
				str[words][i] = 0;  // null char
				if(i == 0)
					words -= 1;
				break;
			}
			else {
				i += 1;
				len[words] += 1;
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
	


	/* =============== Problem (b) =============== */
	printf("\n\n>> (b) The palindrome words: \n");
	for(i=0; i<words; i++) {
		flag = 1;
		for(j=0; j<len[i]/2; j++) {
			if(str[i][j] != str[i][len[i]-j-1]) {
				flag = 0;
				break;
			}
		}

		if(flag) {
			printf(">>     %s\n", str[i]);
		}
	}


	/* =============== Problem (c) =============== */
	printf("\n>> (c) The anagram words: \n");
	for(i=0; i<words; i++) {
		for(j=i+1; j<words; j++) {
			if(anagram(str[i], str[j], len[i], len[j])) {
				printf(">>     %s  %s\n", str[i], str[j]);
			}
		}
	}
}
