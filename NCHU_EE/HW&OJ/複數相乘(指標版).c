#include<stdio.h>

struct Complex{
	int real;
	int imag;
};

void fn2(struct Complex var1,struct Complex var2,struct Complex *var3);

int main()
{
	struct Complex var1, var2, var3;
	
	// input
	scanf("%d %d", &var1.real, &var1.imag);
	scanf("%d %d", &var2.real, &var2.imag);
	
	// calc
	fn2(var1, var2, &var3);
	
	// output
	printf("%d %d", var3.real, var3.imag);
	
	return 0;
}

void fn2(struct Complex var1,struct Complex var2,struct Complex *var3)
{
	var3 -> real = 0;
	var3 -> imag = 0;
	
	var3 -> real += var1.real * var2.real;
	var3 -> real -= var1.imag * var2.imag;
	var3 -> imag += var1.real * var2.imag;
	var3 -> imag += var1.imag * var2.real;
}
