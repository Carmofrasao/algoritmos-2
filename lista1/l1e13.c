#include<stdio.h>

int M(int v[], int a, int b)
{
	int soma;
	soma = v[a];
	if (a == b)
		return(v[a]);
	else
		return soma + M(v, a + 1, b);
}

int main()
{
	int v[10];
	int t;
	for (t = 0; t < 10; t++)
		scanf("%d", &v[t]);
	printf("%d \n", M(v, 0, 9));
}
