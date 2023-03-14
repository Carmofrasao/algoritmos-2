#include<stdio.h>

int expo(int x, int n)
{
	if (n == 1)
		return (x);
	else
		return x * expo(x, n-1);
}

int prog (int a, int r, int n)
{
	if (n == 0)
		return (a);
	else
		return  a*expo(r, n) + prog(a, r, n-1);
}

int main()
{
	int resul;
	resul = prog( 1, 2, 3);
	printf("%d \n", resul);
}
