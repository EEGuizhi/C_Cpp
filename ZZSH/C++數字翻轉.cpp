#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int input;
	long long int A;
	long long int a;
	while(input = scanf("%d",&A))
	{
		if(input != 1)
		{
			break;
		}
		while(A>0) 
	    {
	    	a = A % 10;
	    	cout<< a;
		    A = A * 0.1;
	    }
	    cout << endl;
	}
	printf(">> Program has ended");
	return 0;
}
