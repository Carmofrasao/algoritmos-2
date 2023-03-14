#include<stdio.h>

void troca(int v[], int a, int b)
{
	int aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}


void M(int v[], int a, int b, int j)
{
	if (j == b)
		return ;
	if (v[j] > v[j + 1])
	{
		troca(v, j, j+1);
		return M(v, a, b, 0);
	}
	return M(v, a, b, j+1);
}

int main()
{
	int v[10];
	int a, b, j;
	a = 0;
	b = 9;
	j = a;
	for (int t = 0; t < 10; t++)
		scanf("%d", &v[t]);
	M(v, a, b, j);
	for (int t = 0; t < 10; t++)
		printf("%d ", v[t]);
	printf("\n");
}
