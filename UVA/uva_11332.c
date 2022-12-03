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
    
    while(1) {
        // input
        scanf("%lld", &num);
        if(num == 0)
            break;
        
        // calc
        while(num/10 > 0) {
            num = sum_digits(num);
        }
        
        // output
        printf("%d\n", num);
    }
	
	return 0;
}
