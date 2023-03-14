#include<stdio.h>

int mult(int n, int m)
{
	if ((n < 0 && m < 0) || (m < 0 && n > 0))
		return mult(-1 * n, -1 * m);
	if (m == 1)
		return (n);
	else
		return n + mult(n, m - 1);
}

int main()
{
	int resul;
	resul = mult(5, 3);
	printf("%d \n", resul);
}
