#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void output(unsigned int n) {
	int i, bit[8];
	for(i=0; i<8; i++) {
		bit[i] = n % 2;
		n /= 2;
	}
	
	for(i=0; i<8; i++) {
		printf("%d", bit[8-i-1]);
	}
}



int main() {
	unsigned int n, arr[4], tmp, max_value;
	int i, j, count_one[4], min, flag;
	
	scanf("%x", &n);
	
	// 眔4bytes 
	tmp = n;
	for(i=0; i<4; i++) {
		arr[i] = tmp & ((unsigned int)pow(2, 8)-1);
		tmp >>= 8;
	}
	
	// 璸衡–byteいだΤぶ1 纗
	min = 9; // Τ91
	flag = 0;
	for(i=0; i<4; i++) {
		
		tmp = arr[i];
		count_one[i] = 0; // ﹍耴箂 
		
		for(j=0; j<8; j++) {
			if(tmp % 2 == 1) // or " if(tmp & 1 == 1) "
				count_one[i] += 1; // 狦ヘ玡程じ1 ê碞糤Ωcount 
			tmp >>= 1; // or " tmp /= 2 "
		}
		
		if(count_one[i] < min) {
			min = count_one[i];
			flag = 0;
		}
		else if(count_one[i] == min) {
			flag = 1;
		}
	}
	
	if(flag) { // 狦Τㄢ常琌Τ程ぶ1 ê碞璶ゑ计
		max_value = 0;
		for(i=0; i<4; i++) {
			if(count_one[i] == min && arr[i] > max_value) {
				max_value = arr[i];
			}
		}
		output(max_value);
	}
	else {
		for(i=0; i<4; i++) {
			if(count_one[i] == min)
				output(arr[i]);
		}
	}
	
	return 0;
}
