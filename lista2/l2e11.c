#include<stdio.h>
#include<math.h>

int M(int x, int v[], int a, int b)
{
	int m;
	if (a > b)
		return "não";
	m = floor((a+b)/2);
	if (x == v[m])
		return m;
	if (x < v[m])
		return M(x, v, a, m-1);
	else
		return M(x, v, m + 1, b);
}

int main()
{
	int v[10];
	int x;
	scanf("%d", &x);
	for (int t = 0; t < 10; t++)
		scanf("%d", &v[t]);
	printf("%d \n", M(x, v, 0, 9));
}
