#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

/*
	Test data: 
		a, a
		ab, ba
		besabb, ab
		a, dwadd
		just a te st, test
*/

int search(char *s, char *w) {  // pointer
	int len_s = 0, len_w = 0, i;
	char *ptr;

	// get length
	while(*(s + len_s) != 0)
		len_s += 1;
	while(*(w + len_w) != 0)
		len_w += 1;

	// check
	ptr = s;
	while((len_s - (ptr - s)) >= len_w) {  // 剩下的長度足夠
		if(*ptr == *w) {  // 發現跟w的開頭字元相同
			for(i=0; i<len_w; i++) {
				if(*(ptr + i) != *(w + i))
					break;
				else if(i == len_w-1)
					return 1;  // success
			}
		}

		ptr += 1;
	}
	return 0;
}


int main() {
	int count;
	char str1[MAX_LEN+1] = {0}, str2[MAX_LEN+1] = {0};
	
	// inputs
	gets(str1);
	gets(str2);

	// output
	if(search(str1, str2))
		printf("String 'w' occurs in String 's': True");
	else
		printf("String 'w' occurs in String 's': False");

	return 0;
} 
