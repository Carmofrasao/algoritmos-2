#include<stdio.h>
#include<math.h>

void intercala(int v[], int p, int q, int r)
{
	int i, j;
	int u[10];
	for (int i = p; i <= q; i++)
		u[i] = v[i];
	for (int j = q + 1; j <= r; j++)
		u[r+q+1-j] = v[j];
	i = p;
	j = r;
	for (int k = p; k <= r; k++)
		if (u[i] <= u[j])
		{
			v[k] = u[i];
			i = i + 1;
		}
		else
		{
			v[k] = u[j];
			j = j + 1;
		}
}

void M(int v[], int a, int b)
{
	int m;
	if (a >= b)
		return ;
	m = floor((a+b)/2);
	M(v, a, m);
	M(v, m+1, b);
	return intercala(v, a, m, b);
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
