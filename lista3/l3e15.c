#include<stdio.h>

void troca(int v[], int a, int b)
{
	int aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

int particiona(int v[], int a, int b, int x)
{
	int m;
	m = b + 1;
	for (int i = b; i >= a; i--)
		if (v[i] >= x)
		{
			m = m - 1;
			troca(v, m, i);
		}
	return m;
}

void M(int v[], int a, int b)
{
	int m;
	if (a >= b)
		return ;
	m = particiona(v, a, b, v[a]);
	M(v, a, m-1);
	M(v, m+1, b);
}

int main()
{
	int a, b;
	int v[10];
	a = 0;
	b = 8;
	for (int t = 0; t < b; t++)
		scanf("%d", &v[t]);
	M(v, a, b);
	for (int t = 0; t < b; t++)
		printf("%d ", v[t]);
	printf("\n");
}
