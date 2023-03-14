#include<stdio.h>

int M(int n, int b)
{
	if (n == 0)
		return 0;
	else if (n / 2 == 0)
		return b;
	else if (n % 2 == 1)
		return M(n / 2, b+1);
	else
		return M(n / 2, b);
}

int main()
{
	int n, b;
	b = 1;
	scanf("%d", &n);
	printf("%d \n", M(n, b));
}
