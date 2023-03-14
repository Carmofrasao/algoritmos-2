#include<stdio.h>

int M(int v[], int a, int b)
{
	int aux;
	if (a == 4 && b == 5)
	{
		return v[b];
	}
	else
	{
		return 
		aux = v[a];
		v[a] = M(v, a + 1, b - 1);
		v[b] = aux;
	} 
}

int main()
{
	int v[10];
	int t, aux;
	for (t = 0; t < 10; t++)
		scanf("%d", &v[t]);
	M(v, 0, 9);
	for (t = 0; t < 10; t++)
		printf("%d \n", v[t]);
}
