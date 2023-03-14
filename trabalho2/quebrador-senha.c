#include "biblioteca.h"
#include "quebrador-senha.h"

int eh_igual(char vetor_senha[], int indice)
/*verifica se o item adicionado a senha nao tem um correspondente anterior a ele*/
{
	for (int cont = 0; cont < indice; cont++)
	{
		if (vetor_senha[indice] == vetor_senha[cont])
		{
			return 1;
		}
	}
	return 0;
}

void preenche_vetor_caractere(char vetor_caractere[])
/*preenche um vetor com as possibilidades para a senha*/
{
	int cont = 0;
	for (int caracter = 48; caracter <= 122; caracter++)
	{
		if (caracter == 58)
		/*se acabar os numeros, pula para as letras*/
		{
			caracter = 97;
		}
		vetor_caractere[cont] = caracter;
		cont += 1;
	}
}

void remover(char vetor_senha[], int indice)
/*Remove o elemento da senha*/
{
	vetor_senha[indice] = 0;
}

int valor_valido(char vetor_senha[], int indice)
/*verifica se o item adicionado a senha atende as regras para vazer parte da possivel senha*/
{
	int qtd_num, qtd_letra;
	qtd_num = 0;
	qtd_letra = 0;
	if (vetor_senha[indice] >= 'a' && vetor_senha[indice] <= 'z')
	/*se for letra: */
	{
		qtd_letra = 1;
	}
	else if (vetor_senha[indice] >= '0' && vetor_senha[indice] <= '9')
	/*se for numero: */
	{ 
		qtd_num = 1;
	}
	if (eh_igual(vetor_senha, indice))
	/*se forem iguais retorna 0 para a função*/
	{
		return 0;
	}
	for (int cont = 0; cont < indice; cont++)
	{
		if(vetor_senha[cont] >= 'a' && vetor_senha[cont] <= 'z')
		{
			qtd_letra++;
			if (qtd_letra > 4)
			/*se a senha que esta sendo criada tiver mais que 4 letras, retorna 0 para a função*/
			{
				qtd_letra--;
				return 0;
			}
		}
		else if (vetor_senha[cont] >= '0' && vetor_senha[cont] <= '9')
		{
			qtd_num++;
			if (qtd_num > 4)
			/*se a senha que esta sendo criada tiver mais que 4 numeros, retorna 0 para a função*/
			{
				qtd_num--;
				return 0;
			}
		}
	}
	return 1;
}

int busca_senha_backtracking(char vetor_senha[], int indice, int tamanho_senha, char vetor_possibilidade[])
/*aqui fica a recursividade do backtracking*/
{	
	if (indice >= tamanho_senha)
	/*se a senha chegar ao sexto digito, testa o login*/
	{
		if (login(vetor_senha))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		for (int cont = 0; cont <= 35; cont++)
		/*testa todas as possibilidades de caracteres para a senha*/
		{	
			vetor_senha[indice] = vetor_possibilidade[cont];
			if (valor_valido(vetor_senha, indice))
			/*se o caracter adicionado for valido, chama a função de forma recursiva*/
			{
				if (busca_senha_backtracking(vetor_senha, indice+1, tamanho_senha, vetor_possibilidade))
				/*se a senha passar no teste, retorna 1 para a função*/
				{
					return 1;
				}
			}
			else
			/*BACKTRACK*/
			/*se o caracter nao passar no teste de validade, retiara ele e testa outro valor*/
			{
				remover(vetor_senha, indice);
			}
		}		
	}
	return 0;
}

int busca_senha_exaustiva(char vetor_senha[], char vetor_possibilidade[], int indice, int tamanho_senha)
/*aqui fica a recursividade do força bruta*/
{
	if (indice >= tamanho_senha)
	/*se a senha chegar ao sexto digito, testa o login*/
	{
		if (login(vetor_senha))
		{
			return 1;
		}
	}
	else
	{
		for (int cont = 0; cont <= 35; cont++)
		/*testa todas as possibilidades de caracteres para a senha*/
		{
			vetor_senha[indice] = vetor_possibilidade[cont];
			
			if (busca_senha_exaustiva(vetor_senha, vetor_possibilidade, indice+1, tamanho_senha))
			/*se a senha passar no teste, retorna 1 para a função*/
			{
				return 1;
			}
		}
	}
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_backtracking(){
	char vetor_senha[7];
	char vetor_possibilidade[37];
	int indice = 0;
	int tamanho_senha = 6;
	
	preenche_vetor_caractere(vetor_possibilidade);
		
	if (busca_senha_backtracking(vetor_senha, indice, tamanho_senha, vetor_possibilidade))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrario */
int quebrador_senha_exaustivo(){
	char vetor_possibilidade[37];
	char vetor_senha[7];
	int tamanho_senha = 6;
	int indice = 0;
	
	preenche_vetor_caractere(vetor_possibilidade);
	
	if (busca_senha_exaustiva(vetor_senha, vetor_possibilidade, indice, tamanho_senha))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
