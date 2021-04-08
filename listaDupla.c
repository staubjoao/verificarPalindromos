#include <stdio.h>
#include <stdlib.h>

typedef struct palindromo Palindromo;
struct palindromo {
	char wr;
	Palindromo *proximo;
	Palindromo *anterior;
};

Palindromo *inicio;
Palindromo *fim;
int len;

void criaLista();
Palindromo *aloca(char wr);
void insereInicio(char wr);
void imprimeLista();
void imprimeListaContrario();

void criaLista()
{
	inicio = NULL;
	fim = NULL;
	len = 0;
}

Palindromo *aloca(char wr)
{
	Palindromo *novo = (Palindromo*)malloc(sizeof(Palindromo));
	novo-> wr = wr;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}

void insereInicio(char wr)
{
	Palindromo *novo = aloca(wr);
	if(inicio==NULL)
    {
		inicio = novo;
		fim = novo;
	}else
	{
		Palindromo *atual;
		atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
	}
	len++;
}

void imprimeLista() {
	Palindromo *atual;
	atual = inicio;
	while(atual){
		printf("%d\n",atual->wr);
		atual = atual->proximo;
	}
}
