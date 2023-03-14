#include "insercao.h"
#include "particiona.h"


/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort com inserção e devolve v       */

int *quicksort_insercao(int v[], int a, int b, unsigned int m) 
{
	while(a < b)
	{
	   /* Depois de testar alguns valores percebemos que 4 era o que dava o melhor desempenho 
	   Entao 4 vai ser o tamanho do vetor onde o insercao vai ser usado                    */
		if (b - a <= 4)
		{
			insercao(v, a, b);
			break;
		}
		/* Caso o vetor particionado tenha mais do que 4 elementos, o quicksort
		   sera aplicado no lugar do insertion, ate que ele seja do tamanho adequado
		   para que o insercao seja utilizado                                     */
		else
		{
			m = particiona(v, a, b, v[b]);
			if (m - a < b - m)
			{
				quicksort_insercao(v, a, m-1, m);
				a = m + 1;
			}
			else
			{
				quicksort_insercao(v, m+1, b, m);
  				b = m - 1;
  			}
  		}
  	}
  	return v;
}
