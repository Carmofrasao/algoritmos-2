#include<stdio.h>

int M(int n, int k)
{
	if (n < k)
		return 0;
	if (k == 0)
		return 1;
	if (0 < k <= n)
		return M(n-1, k-1) + M(n-1, k);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d \n", M(n, k));
}
