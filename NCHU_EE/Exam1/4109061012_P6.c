#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void output(unsigned int n) {
	int i;
	for(i=0; i<8; i++) {
		printf("%d", n / (unsigned int)pow(2, 8-i-1) % 2);
	}
}



int main() {
	unsigned int n, arr[4], tmp, max_value;
	int i, j, count_one[4], min, flag;
	
	scanf("%x", &n);
	
	// 取得4個bytes 
	tmp = n;
	for(i=0; i<4; i++) {
		arr[i] = tmp & ((unsigned int)pow(2, 8)-1);
		tmp >>= 8;
	}
	
	// 計算每個byte中分別有多少1 個別儲存
	min = 9; // 代表有9個1
	flag = 0;
	for(i=0; i<4; i++) {
		
		tmp = arr[i];
		count_one[i] = 0; // 初始歸零 
		
		for(j=0; j<8; j++) {
			if(tmp % 2 == 1) // or " if(tmp & 1 == 1) "
				count_one[i] += 1; // 如果目前的最低位元為1 那就增加一次count 
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
	
	if(flag) { // 如果有兩個以上都是有最少個1 那就要再比數值大小
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
