#include<stdio.h>

int expo(int x, int n)
{
	if (n == 1)
		return (x);
	else
		return x * expo(x, n-1);
}

int main()
{
	int resul;
	resul = expo(2, 10);
	printf ("%d \n", resul);
}
