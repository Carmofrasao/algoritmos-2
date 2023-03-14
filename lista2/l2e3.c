#include<stdio.h>

void M(int a, int x)
{
	if (x == a+1)
		return ;
	if (a % x == 0)
	{
		printf("%d \n", x);
		return  M(a, x+1);
	}
	else 
		return	M(a, x+1);
}

int main()
{
	int a, x;
	x=1;
	a=10;
	M(a, x);
}
