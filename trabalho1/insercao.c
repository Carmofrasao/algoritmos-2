#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo método da insercao e devolve v */

/* Devolve o lugar que x deve ocupar no vetor v */
int busca(int x, int v[], int a, int b)
{
	if (a > b)
		return a-1;
	if (compara(x, v[b]) >= 0)
		return b;
	return busca(x, v, a, b-1);
}

/* Insere o elemento no lado que esta sendo ordenado */
int insere(int v[], int a, int b)
{
	int p = busca(v[b], v, a, b-1);
	int i = b;
	while (i>p+1)
	{
		troca(v, i, i-1);
		i = i - 1;
	}
	return 0;
}

/* Realiza o InsertionSort ate o vetor v ser ordenado */
int *insercao(int v[], unsigned int a, unsigned int b) 
{
	if (a >= b)
		return v;
	insercao(v, a, b-1);
	insere(v, a, b);
  	return v;
}
