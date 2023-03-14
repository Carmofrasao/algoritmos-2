#include<stdio.h>

int mdc(int a, int b)
{
	int n, resul;
	n = 1;
	resul = 1;
	while (a != 1 && b != 1)
	{
		if (a % n == 0 && b % n == 0)
			resul = n * resul;
		if (a % n == 0)
			a = a / n;
		if (b % n == 0)
			b = b / n;
		n = n + 1;
	}
	return (resul);
}

int main()
{
	printf("%d \n", mdc(3, 15));
}
