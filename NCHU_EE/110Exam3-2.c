#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define N 5

void file_extension(const char *filename, char *extension) {  // pointer
	// find the end of string
	while(*filename != 0) {
		filename += 1;
	}

	// find last '.'
	while(*(filename-1) != '.') {
		filename -= 1;
	}

	// extract
	while(*filename != 0) {
		*extension = *filename;  // copy
		*(extension+1) = 0;  // string end '\0'
		extension += 1;
		filename += 1;
	}
}

int main() {
	int count = 0, i;
	char str[MAX_LEN+1], ext[10];
	
	for(i=0; i<N; i++) {
		// input
		scanf("%s", str);

		// check & count
		file_extension(str, ext);
		if(ext[0] == 'c' && ext[1] == 0)
			count += 1;
	}
	
	printf("%d", count);
	
	return 0;
} 
