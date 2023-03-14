#include<stdio.h>

void M(int a, int x)
{
	int d;
	d = 1;
	for (int t = 0; t <= a; t++)
	{
		if (a % d == 0)
			printf("%d \n", d);
		d = d + 1;
	}
}

int main()
{
	int a, x;
	x=1;
	a=10;
	M(a, x);
}
