#include <stdio.h>
#include <stdlib.h>

int sum_digits(long long unsigned num) {
	long long unsigned sum = 0;
	while(num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main() {
    long long unsigned num;
    
    // input
    scanf("%d", &num);
    
    // calc
    while(num/10 >= 1) {
    	num = sum_digits(num);
	}
	
	// output
	printf("%d", num);
	
	return 0;
}
