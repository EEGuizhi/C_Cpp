#include <cstdio>
#include <algorithm>

int compare(const void * a, const void * b) {
	return (*(double*)a - *(double*)b);
}

int main() {
	int m, n, i, j, R = 0;
	double elv[30 * 30], water, vol;
	double ans[100][2];
	
	while(1) {
		R += 1;
		// inputs
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0)
			break;
		n *= m;
		for(i=0; i<n; i++) {
			scanf("%lf", &elv[i]);
		}
		scanf("%lf", &water);
		
		// calc
		qsort(elv, n, sizeof(double), compare);
		i = 0;
		while(water > 0) {
			i += 1;
			if(i >= n) {
				printf("Region %d\n", R);
				printf("Water level is %.2lf meters.\n", elv[i-1] + (water / (double)(n*100)));
				printf("100.00 percent of the region is under water.\n");
				break;
			}
			else {
				vol = (elv[i] - elv[i-1]) * 100 * (double)i;
				if(water > vol) {
					water -= vol;
				}
				else {  // outputs
					printf("Region %d\n", R);
					printf("Water level is %.2lf meters.\n", elv[i-1] + (water / (double)(i*100)));
					printf("%.2lf percent of the region is under water. i: %d, n: %d\n", (double)100 * i / n, i, n);
					break;
				}
			}
		}
	}
	
	return 0;
}
