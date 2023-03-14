#include<stdio.h>
#include<math.h>

int M(int v[], int a, int b)
{
	int m, m1, m2;
	if (a == b)
		return a;
	m = floor((a+b)/2);
	m1 = M(v, a, m);
	m2 = M(v, m + 1, b);
	if (v[m1] <= v[m2])
		return m1;
	else
		return m2;
}

int main()
{
	int v[10];
	for (int t = 0; t < 10; t++)
		scanf("%d", &v[t]);
	printf("%d \n", M(v, 0, 9));
}
