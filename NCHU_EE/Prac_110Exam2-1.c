// by 4109061012
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* ========================= Problem (a) ========================= */
void fn1_ver1(int a[], int n1, int n2) {
	// Non-recursive bubble sort (from largest to smallest)
	int i, j, tmp;
	
	for(i=0; i<n2-n1; i++) {
		for(j=n1; j<n2-i; j++) {
			if(a[j] < a[j+1]) {
				// switch
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void fn1_ver2(int a[], int n1, int n2) {
	// Recursive bubble sort (from largest to smallest)
	int j, tmp;

	for(j=n1; j<n2; j++) {
		if(a[j] < a[j+1]) {
			// switch
			tmp = a[j+1];
			a[j+1] = a[j];
			a[j] = tmp;
		}
	}

	if(n2-1 > n1)
		fn1_ver2(a, n1, n2-1);
}


/* ========================= Problem (b) ========================= */
int fn2(int a[], int len, int target) {
	int i, index, diff, min_diff;
	
	min_diff = (int)(pow(2, 31) - 1);  // Max. value of integer is 2^31 - 1
	for(i=0; i<len; i++) {
		diff = a[i] - target;
		if(diff < 0)
			diff *= -1;
		
		if(diff < min_diff) {
			index = i;
			min_diff = diff;
		}
	}
	
	return index;
}


/* ========================= Print Result ======================== */
void PrintResult(int arr[], int len, int index, int target) {
	int i, flag = 1;
	for(i=0; i<len; i++) {
		if(i > 0) {
			if(arr[i-1] < arr[i])
				flag = 0;
		}
		printf("%3d ", arr[i]);
	}
	// check answer
	if(flag)
		printf("\n>> Bubble sort is Correct :D");
	else
		printf("\n>> Bubble sort is NOT Correct :C");
	
	printf("\n\n>> arr[index = %d] = %d is closest element to the target b = %d", index, arr[index], target);
}


/* ========================= Problem (c) ========================= */
# define LEN 10
# define TARGET 123
int main() {
    int arr[LEN], i, flag;
    
    // generate some numbers
    srand((unsigned) time(NULL));
    for(i=0; i<LEN; i++) {
    	arr[i] = rand() % 1001;  // Not larger than 1000
	}
	
	/*====== Problem (a) ======*/
	 fn1_ver1(arr, 0, LEN-1);
	// fn1_ver2(arr, 0, LEN-1);
	
	
	/*====== Problem (b) ======*/
	int n = LEN, b = TARGET, index;
	index = fn2(arr, n, b);
	
	
	// Print result
	PrintResult(arr, LEN, index, TARGET);

    return 0;
}
