#include<stdio.h>

int M(int v[], int a, int b)
{
	if (a == b)
		return (v[a]);
	else
		return v[a] + M(v, a+1, b);
}

int main()
{
	int v[10];
	int t;
	float s, a, b;
	for (t = 0; t <= 9; t++)
		scanf("%d", &v[t]);
	s = M(v, a=0, b=9) / (b-a+1);
	printf("%f \n", s);
}
