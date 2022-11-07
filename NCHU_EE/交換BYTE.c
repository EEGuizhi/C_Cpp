#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
	int i, j;
	unsigned int n, byte[4];
	
	// input
	scanf("%x", &n);
	
	byte[0] = n & ((unsigned int)pow(2, 8) - 1);
	byte[1] = n >> 8;
	byte[1] = byte[1] & ((unsigned int)pow(2, 8) - 1);
	byte[2] = n >> 16;
	byte[2] = byte[2] & ((unsigned int)pow(2, 8) - 1);
	byte[3] = n >> 24;
	
	n = (byte[3] << 24) + (byte[1] << 16) + (byte[2] << 8) + byte[0];
	printf("%#x", n);
}
