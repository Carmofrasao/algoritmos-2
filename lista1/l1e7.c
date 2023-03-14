#include<stdio.h>

int prog (int n, int r, int a)
{
	if (n == 1)
		return (a);
	else
		return prog(n - 1, r, a) + r;
}

int main()
{
	int resul;
	resul = prog(5, 3, 2);
	printf("%d \n", resul);
}
