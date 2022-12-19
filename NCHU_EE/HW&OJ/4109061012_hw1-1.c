// 4109061012 EE109A 陳柏翔
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, i, x, y;
    int arr[99][99];
    
    // input
	while(n < 0 || n%2 == 0)
	{
		printf("Please input the size (odd only): ");
		scanf("%d", &n);
	}
	
    
    // init
    for(x=0; x<n; x++) {
		for(y=0; y<n; y++) {
			arr[x][y] = 0;
		}
	}
    
    // generate
    x = n / 2;
    y = 0;
    for(i=1; i<=n*n; i++) {
    	// has number
		if(arr[x][y] != 0) {
			x -= 1;
			y += 2;
			if(x < 0)
				x += n;
			if(y > n-1)
				y -= n;
		}
		
		// store number
		arr[x][y] = i;

    	// next position
		x += 1;
		y -= 1;
		if(y < 0)
			y += n;
		if(x > n-1)
			x -= n;
	}
	
	// output
	for(y=0; y<n; y++) {
		for(x=0; x<n; x++) {
			printf("%2d ", arr[x][y]);
		}
		printf("\n");
	}
}
