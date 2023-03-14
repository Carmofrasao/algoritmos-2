#include<stdio.h>

void M(int v[], int a, int b)
{
	if (a == b+1)
	{
		if (v[a] == v[b])
			printf ("sim\n");
		else
			printf ("não\n");
	}	
	else if (v[a] == v[b])
		return M(v, a+1, b-1);
	else	
		printf ("não\n");
}

int main()
{
	int v[10];
	int t;
	for (t = 0; t <= 9; t++)
		scanf("%d", &v[t]);
	M(v, 0, 9);
}
