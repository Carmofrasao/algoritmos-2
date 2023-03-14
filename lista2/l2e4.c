#include<stdio.h>

int expo(int x, int n)
{
	if (n == 0)
		return (1);
	else
		return x * expo(x, n-1);
}

int M(int v[], int a, int b, int x)
{
	int i = b-a;
	if (b == a)
		return v[a];
	else
		return v[b] * expo(x, i) + M(v, a, b-1, x);
}

int main()
{
	int v[10];
	int t, a, b, x;
	a=0;
	b=5;
	x=2;
	for (t = 0; t < b+1; t++)
		scanf("%d", &v[t]);
	printf("%d \n", M(v, 2, 4, x));
}
