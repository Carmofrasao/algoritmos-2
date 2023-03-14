#include<stdio.h>
#include<math.h>

void intercala(int v[], int a, int m, int b)
{
	int i, j;
	int u[10];
	if (a >= b)
		return ;
	i = a;
	j = m + 1;
	for(int k = 0; k <= b-a; k++)
		if(j > b || (i <= m && v[i] >= v[j]))
		{
			u[k] = v[i];
			i = i + 1;
		}
		else
		{
			u[k] = v[j];
			j = j + 1;
		}
	for (int k = a; k <= b; k++)
		v[k] = u[k-a];
	return ;
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
