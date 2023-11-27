#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80

void read_line(char *s, int n, int *p1) {  // pointer
	int i, flag = 0;
	*p1 = 0;
	for(i=0; i<n; i++) {
		*s = getchar();  // input
		
		if(flag == 0) {  // initial white space
			if(*s != ' ')
				flag = 1;
			i = 0;
		}

		if(flag) {
			if(*s == '\n') {  // end of input
				*s = 0;  // string end char
				break;
			}
			else if(*s>='a' && *s<='z') {  // lower-case English letter
				*s = (*s - 'a') + 'A';
				*p1 += 1;
			}
			s += 1;
		}
	}
	*s = 0;  // string end char
}

int main() {
	int count;
	char str[MAX_LEN+1];
	
	// main
	read_line(str, 80, &count);
	
	// output
	printf("%d\n%s", count, str);
	
	return 0;
} 
