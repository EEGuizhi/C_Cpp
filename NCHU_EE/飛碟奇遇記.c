#include <stdio.h>
#include <stdlib.h>

int main() {
	char s1[6] = {0}, s2[6] = {0};
	int i;
	long long unsigned sum1 = 1, sum2 = 1;
	
	i = 0;
	while(1) {
		scanf("%c", &s1[i]);
		if(s1[i] == 0 || s1[i] == '\n') {
			s1[i] = 0;
			break;
		}
		else {
			sum1 *= (long long unsigned)(s1[i] - 'A' + 1);
			i += 1;
		}
	}
	i = 0;
	while(1) {
		scanf("%c", &s2[i]);
		if(s2[i] == 0 || s2[i] == '\n') {
			s2[i] = 0;
			break;
		}
		else {
			sum2 *= (long long unsigned)(s2[i] - 'A' + 1);
			i += 1;
		}
	}

	if(sum1%47 == sum2%47)
		printf("GO");
	else
		printf("STAY");
	
	
	return 0;
}
