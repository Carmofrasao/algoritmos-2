#include<stdio.h>

int fat(int n)
{
	if (n == 0)
		return(1);
	else 
		return n * fat(n - 1);
}

int main()
{
	int resul;
	resul = fat(2);
	printf("%d \n", resul);
}
