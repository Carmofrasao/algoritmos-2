#include<stdio.h>

int mc(int n)
{
	if (n > 100)
		return (n - 10);
	else 
		return mc(mc(n + 11));
}

int main()
{
	int resul;
	resul = mc(85);
	printf("%d \n", resul);
}
