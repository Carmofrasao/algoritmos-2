#include<stdio.h>

int M(int v[], int a, int b)
{
	int n;
	if (a == b)
		return (a);
	n = M(v, a + 1, b);
	if (v[a] < v[n])
		n = a;
	return (n);
}

int main()
{
	int v[10];
	int t;
	for (t = 0; t < 10; t++)
		scanf("%d", &v[t]);
	printf("%d \n", M(v, 0, 9));
}
