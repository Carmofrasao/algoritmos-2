#include<stdio.h>
#include<math.h>

int f(int a, int b)
{
	if (b == 0)
		return (0);
	if (b % 2 == 0)
		return f(a + a, floor(b/2));
	else
		return f(a + a, floor(b/2)) + a;
}

int main()
{
	printf("%d \n", f(5, 7));
}
