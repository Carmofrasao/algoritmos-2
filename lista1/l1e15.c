#include<stdio.h>

char M(int x, int v[], int a, int b)
{
	char r;
	if (a > b)
		return "não";
	r = M(x, v, a, b-1);
	if (r != "não")
		return r;
	if (x = v[b])
		return b;
	else
		return "não";
}

int main()
{
	int v[5];
	int t, x;
	scanf("%d", &x);
	for (t = 0; t < 5; t++)
		scanf("%d", &v[t]);
	printf("%d \n", M(x, v, 0, 4));
}
