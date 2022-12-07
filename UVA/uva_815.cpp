// Title: Flooded!, Verdict: Accepted, Run Time: 0.010

/*  此題必須用C++函式庫的printf 用C函示庫的printf會在使用%.2f時四捨五入出不同的值 (確認後發現 其實是C++的有誤)
    以及題目範例解答表示不明確 每輸出一個Region後需要換2行再進行下個Region的輸出。 */

#include <cstdio>
#include <algorithm>

int compare(const void * a, const void * b) {
	return (*(double*)a - *(double*)b);
}

int main() {
	int m, n, i, j, R = 0;
	double elv[30 * 30], water, vol;
	
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
				printf("Region %d\n", R);  // outputs
				printf("Water level is %.2lf meters.\n", elv[i-1] + (water / (double)(n*100)));
				printf("100.00 percent of the region is under water.\n\n");
				break;
			}
			else {
				vol = (elv[i] - elv[i-1]) * 100 * (double)i;
				if(water > vol) {
					water -= vol;
				}
				else {
					printf("Region %d\n", R);  // outputs
					printf("Water level is %.2lf meters.\n", elv[i-1] + (water / (double)(i*100)));
					printf("%.2lf percent of the region is under water.\n\n", (double)100 * i / n);
					break;
				}
			}
		}
	}
	
	return 0;
}
