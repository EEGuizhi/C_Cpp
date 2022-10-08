#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{
	int N,K,i,j,s,g;
	float a,b,c,d;
	scanf("%d",&N);
	scanf("%d",&K);

	int X1[1000];
	int Y1[1000];
	int X2[1000];
	int Y2[1000];
	j=0;
	g=0;
	for(i=0 ; i<N ; i++)
	{
		scanf("%d",&X1[i]);
		scanf("%d",&Y1[i]);
		scanf("%d",&X2[i]);
		scanf("%d",&Y2[i]);
    }

	
	for(i=0;i<K;)
	{
		if(g >= N)
		{
			g=0;
		}
		j=g+1;
		if(j >= N)
		{
			j = 0;
		}
		if((X2[g] - X1[g]) == 0)
		{
			a=0;
		}
		else
		{
			a=(Y2[g] - Y1[g]) / (X2[g] - X1[g]);
		}
        
        if((X2[j] - X1[j]) == 0)
		{
			b=0;
		}
		else
		{
			b=(Y2[j] - Y1[j]) / (X2[j] - X1[j]);
		}
		
	    
		c=Y1[i] - (a * X1[i]);
		d=Y1[j] - (b * X1[j]);
		
		if(((((Y2[g] - Y1[g]) != 0) && (a==0)) || (((Y2[j] - Y1[j]) != 0) && (b==0))) && ((((Y2[g] - Y1[g]) != 0) && (a==0)) != (((Y2[j] - Y1[j]) != 0) && (b==0))))
		{
			i=i+1;
			s=j+1;
			printf("%d %d",g+1,s);
			cout << endl;
		}
		g=g+1;
		
		if((((a / b) == 0) && ((c / d) == 0 )) || (((b / a) == 0) && ((d / c) == 0 )) || (((a / b) == 0) && ((d / c) == 0 )) || (((b / a) == 0) && ((c / d) == 0 )))
		{
			i=i+1;
			s=j+1;
			printf("%d %d",g,s);
			cout << endl;
		}
	} 
	system("PAUSE");
	return 0;
}
