#include<stdio.h>

void M(int v[], int a, int u[], int p, int l, int d)
{
	if (a + d > a + l || p + d > p + l)
		return ;
	else if (v[a + d] != u[p + d])
	{
		printf ("%d", d);
		return M(v, a, u, p, l, d + 1);
	}
	else if (v[a + d] == u[p + d])
	{
		printf ("%d", l + 1);
		return M(v, a, u, p, l, d + 1);
	}
}

int main()
{
	int v[10];
	int u[10];
	int t, a, p, l, d;
	d = 0;
	scanf("%d %d %d", &a, &p, &l);
	for (t = a; t <= a + l; t++)
		scanf("%d", &v[t]);
	for (t = p; t <= p + l; t++)
		scanf("%d", &u[t]);
	M(v, a, u, p, l, d);
	printf("\n");
}
