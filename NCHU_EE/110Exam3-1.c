#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

void compare_string(char *s1, char *s2, int *p1) {
	while(*s1 != 0) {
		if(*s1 == *s2)
			*p1 = 1;
		else {
			*p1 = 0;
			break;
		}
		s1 += 1;
		s2 += 1;
	}
}

int main() {
	int p1;
	char str1[MAX_LEN+1], str2[MAX_LEN+1];
	
	scanf("%s%s", str1, str2);
	compare_string(str1, str2, &p1);
	
	printf("%d", p1);
	
	return 0;
} 
