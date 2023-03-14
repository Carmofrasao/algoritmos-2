#include<stdio.h>

int minimo(int v[], int a, int b)
{
	int m;
	if (a == b)
		return a;
	m = minimo(v, a, b-1);
	if (v[b]<v[m])
		m = b;
	else 
		return m;
}

void troca(int v[], int a, int b)
{
	int aux;
	if (v[a] != v[b])
	{
		aux = v[a];
		v[a] = v[b];
		v[b] = aux;
	}
}

void M(int v[], int a, int b)
{
	if (a >= b)
		return ;
	troca(v, a, minimo(v, a, b));
	return M(v, a+1, b);
}

int main()
{
	int a, b;
	int v[10];
	a = 0;
	b = 6;
	for (int t = 0; t < b; t++)
		scanf("%d", &v[t]);
	M(v, a, b);
	for (int t = 0; t < b; t++)
		printf("%d ", v[t]);
	printf("\n");
}
