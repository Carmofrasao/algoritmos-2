#include<stdio.h>

int mdc(int a, int b)
{
	if (b == 0)
		return(a);
	else
		return mdc(b, a % b);
}

int main()
{
	printf("%d \n", mdc(3, 15));
}
