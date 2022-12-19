/*
Description:
我們知道，若單純使用 >> ，則全部位元往右移，
LSB(最低位元)消失且MSB(最高位元)會自動補 0，
但在組合語言中，有一個指令叫做 ROR ，
他可以讓LSB的位元回到MSB，而不是直接消失，
並且其他位元保持右移。

例如:
0x1(00000000 00000000 00000000 00000001)_2
​
ROR 11 次後會變成 :
0x80000000(10000000 00000000 00000000 00000000)_2
​
也就是原本最後一個位元，跑到了第一個位元，
而其他位元也右移，這就是 ROR 指令的功能。

Input:
每組輸入有兩行。
第一行有一個類型為unsigned int的十六進位數。
第二行有一個正整數 N ，代表要 ROR 幾次。

Output:
請輸出 ROR N 次後的十六進位數。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	unsigned int n, lsb;
	int i, times;
    
    // input
    scanf("%x", &n);
    scanf("%d", &times);
	
	// calc
	for(i=0; i<times; i++) {
		if(n%2 == 1)
			lsb = 1;
		else
			lsb = 0;
			
		n = n >> 1;
		if(lsb)
			n += pow(2, 31); 
	}

	// output
	printf("0x%x", n);
	
	return 0;
}
