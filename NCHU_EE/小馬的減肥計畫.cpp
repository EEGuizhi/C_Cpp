#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, d, max, result = 0;
	int s[1000], up, dn;
	
	scanf("%d %d", &n, &d);
	for(int i=0; i<n; i++) {
		scanf("%d", &s[i]);
	}
	
	for(int i=0; i<n; i++) {
		up = 0;
		dn = 0;
		max = 0;
		
		if(s[i] > 0) {
			for(int j=i+1; j<n; j++) {
				if(s[j] > 0)
					up += 1;
				else
					dn += 1;
				
				if(dn<up-d || dn>up+d+1)
					break;
				else
					max += 1;
			}
			if(dn<up-d || dn>up+d)
				max -= 1;
		}
		
		if(result < max)
			result = max;
	}
	
	printf("%d", result);
}
