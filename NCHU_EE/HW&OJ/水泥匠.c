#include <stdio.h>
#include <stdlib.h>

#define LEN 10
int main() {
	int n, m, cmd, i, x, p1, p2, tmp;
	char con[LEN];
	
	scanf("%d %d", &n, &m);
	
	for(i=0; i<LEN; i++) {  // init
		if(i < n)
			con[i] = '.';
		else
			con[i] = 'X';
	}
	
	for(i=0; i<m; i++) {
		scanf("%d", &cmd);
		
		if(cmd == 1 || cmd == 2) {  // adjust
			scanf("%d %d", &p1, &p2);
			if(p1 > p2) {
				tmp = p1;
				p1 = p2;
				p2 = tmp;
			}
			if(p1 < 0)
				p1 = 0;
			if(p2 > 9)
				p2 = 9;
		}
		else {
			scanf("%d", &p1);
		}
		
		if(cmd == 1) {  // cmd 1.
			for(x=p1; x<=p2; x++)
				con[x] = 'X';
		}
		else if(cmd == 2) {  // cmd 2.
			for(x=p1; x<=p2; x++)
				con[x] = '.';
		}
		else if(cmd == 3) {  // cmd 3.
			if(con[p1] == '.') {
				con[p1] = 'X';
				for(x=p1+1; x<n && con[x]=='.'; x++)
					con[x] = 'X';
				for(x=p1-1; x>=0 && con[x]=='.'; x--)
					con[x] = 'X';
			}
		}
	}
	
	for(i=0; i<n; i++) {
		printf("%c", con[i]); 
	}
	
	return 0;
}
