#include<stdio.h>

int busca(int x, int v[], int a, int b)
{
	if (a > b)
		return a-1;
	if (x >= v[b])
		return b;
	else
		return busca(x, v, a, b-1);
}

void troca(int v[], int a, int b)
{
	int aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

void insere(int v[], int a, int b)
{
	int p;
	p = busca(v[b], v, a, b-1);
	for (int i=b; i>p+1; i--)
		troca(v, i, i-1);
	return ;
}

void M(int v[], int a, int b)
{
	if (a >= b)
		return ;
	M(v, a, b-1);
	insere(v, a, b);
	return ;
}

int main()
{
	int v[12];
	int a, b;
	a = 0; 
	b = 11;
	for (int t = 0; t <= b; t++)
		scanf("%d", &v[t]);
	M(v, a, b);
	for (int t = 0; t <= b; t++)
		printf("%d ", v[t]);
	printf("\n");
}
