#include<stdio.h>

int M(int v[][], int a, int b)
{
	if 
	if (v[a][b] == v[b][a])
		return M(v, a, b);	
	else (v[a][b] != v[b][a])
		return 0;
}

int main()
{
	int v[3][3];
	for (int t = 0; t < 3; t++)
		for (int q = 0; q < 3; q++) 
			scanf("%d", &v[t][q]);
	printf("%d \n", M(v, 0, 2));
}
