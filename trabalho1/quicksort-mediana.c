#include "particiona.h"
#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */


/* Calcula a mediana dos valores a, b e c */
static int mediana(int a, int b, int c) 
{
	int medi;
	if (a < b)
	{
		if (b < c)
			medi = b;
		else
		{
			if (a < c) 
				medi = c;
			else
				medi = a;
		}
	}
	else
	{
		if (c < b)
			medi = b;
		else
		{
			if (c < a) 
				medi = c;
			else
				medi = a;
		}
	}
	return medi;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b) 
{
/* tivemos que incluir a biblioteca.h aqui para usar a funcao sorteia */
  	int m, valMedian1, valMedian2, valmedian3, posMediana;
	if (a >= b)
		return v;
	/* Sorteia 3 valores entre a e b e depois calcula a mediana deles */
	valMedian1 = sorteia(a, b);
	valMedian2 = sorteia(a, b); 
	valmedian3 = sorteia(a, b);
	posMediana = mediana(valMedian1, valMedian2, valmedian3);
	troca(v, posMediana, b);
	/* Transforma o posMediana em pivo e particiona o vetor a partir dele */
	m = particiona(v, a, b, v[b]);
	quicksort_mediana(v, m+1, b);
	quicksort_mediana(v, a, m-1);
	return v;
}
