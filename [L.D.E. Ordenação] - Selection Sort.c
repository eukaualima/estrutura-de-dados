/*
=---------------=
=-> Cabeçalho <-=
=---------------=
*/
/**
 * @author Kauã dos Santos Lima
 * @since 03/06/2023
 * @details Lista Duplamente Encadeada: Ordenação Dinâmica e Estática, com método Selection Sort
 * @note Exercício individual para Estrutura de Dados / IFBA 2º Semestre de Computação
**/ 
/*
=--------------=
=-> Includes <-=
=--------------=
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
=----------------=
=-> Estruturas <-=
=----------------=
*/
struct no_dinamica
{
	int elemento;
	struct no_dinamica *prox;
	struct no_dinamica *ant;
};

/// @brief Estrutura do tipo *No_din para nós da lista duplamente encadeada em ordenação dinâmica.
typedef struct no_dinamica *No_din;

struct no_estatica
{
	int elemento;
	struct no_estatica *prox;
	struct no_estatica *ant;
};

/// @brief Estrutura do tipo *No_est para nós da lista duplamente encadeada em ordenação estática.
typedef struct no_estatica *No_est;

struct lista_din
{
	No_din inicio, fim;
};

/// @brief Estrutura do tipo *Lista_din para início e fim da lista duplamente encadeada em ordenação dinâmica.
typedef struct lista_din *Lista_din;

struct lista_est
{
	No_est inicio, fim;
};

/// @brief Estrutura do tipo *Lista_est para início e fim da lista duplamente encadeada em ordenação estática.
typedef struct lista_est *Lista_est;

/*
=------------------=
=-> Subprogramas <-=
=------------------=
*/
/// @brief Sub-rotina para criar a Lista Duplamente Encadeada para a ordenação dinâmica.
/// @param n Recebe um valor inteiro informado pelo usuário.
/// @param lista Recebe a lista dinâmica atual.
/// @return Cria uma lista duplamente encadeada ou adiciona um nó a uma já existente.
void criaNoLista_din(int n, Lista_din lista)
{ 
    No_din l; 
    
    l = (No_din) malloc(sizeof(struct no_dinamica));
    l->elemento = n;
    
    if (lista->inicio == NULL)
    {
        l->prox = NULL;
        l->ant = NULL;
        lista->inicio = l;
        lista->fim = l;
    }
    else
    {
        l->prox = lista->inicio;
        l->ant = NULL;
        lista->inicio->ant = l;
        lista->inicio = l;
    }
}
/// @brief Sub-rotina para criar a Lista Duplamente Encadeada para a ordenação estática.
/// @param n Recebe um valor inteiro informado pelo usuário.
/// @param lista Recebe a lista dinâmica atual.
/// @return Cria uma lista duplamente encadeada ou adiciona um nó a uma já existente.
void criaNoLista_est(int n, Lista_est lista)
{ 
	No_est l; 
	
	l = (No_est)malloc(sizeof(struct no_estatica));
	l->elemento = n;
	
	if(lista->inicio == NULL)
	{
		l->prox = NULL;
		l->ant = NULL;
		lista->inicio = l;
		lista->fim = l;
	}
	else
	{
		l->prox = lista->inicio;
		l->ant = NULL;
		lista->inicio->ant = l;
		lista->inicio = l;
	}
}

/// @brief Sub-rotina para todas as mensagens que serão utilizadas no programa.
/// @param p Recebe um valor inteiro relacionado ao código da mensagem.
/// @return Mensagem no terminal.
void mensagem(int p)
{
	switch(p)
	{
		case 0: 
            printf(">------------------<[ Ordenação Dinâmica & Estática ]>------------------<\n| Escolha abaixo a opção que deseja acessar.\n| [1]: Ordenação Dinâmica\n| \t=> Lista de números crescentes, atualizada a cada nova inserção.\n| [2]: Ordenação Estática\n| \t=> Lista de números decrescentes, atualizada a cada 5 inserções.\n| [0]: Sair do programa.\n| \t=> Finaliza imediatamente o programa.\n>-----------------------------------------------------------------------<\n| Acessar a opção: "); 
            break;
		case 1: 
            printf("| [!] Programa encerrado com sucesso."); 
            break;
		case 2: 
            printf(">-----------------------------------------------------------------------------------<\n|\n"); 
            break;
		case 3: 
            printf(">------------------<[ Menu: Ordenação Dinâmica ]>------------------<\n| Escolha abaixo a opção que deseja acessar.\n| [1]: Inserir um novo número na lista\n| \t=> Adicione números na lista de forma crescente.\n| [2]: Deletar um número existente\n| \t=> Remova da sua lista um número específico, que exista.\n| [0]: Retornar ao menu principal.\n| \t=> Retorna você ao início do programa.\n>-----------------------------------------------------------------------<\n| Acessar a opção: "); 
            break;
		case 4: 
            printf(">------------------<[ Menu: Ordenação Estática ]>------------------<\n| Escolha abaixo a opção que deseja acessar.\n| [1]: Inserir um novo número na lista\n| \t=> Adicione números na lista de forma decrescente.\n| [2]: Deletar um número existente\n| \t=> Remova da sua lista um número específico, que exista.\n| [0]: Retornar ao menu principal.\n| \t=> Retorna você ao início do programa.\n>-----------------------------------------------------------------------<\n| Acessar a opção: "); 
            break;
		case 5: 
            printf("| Número a ser inserido: "); 
            break;
		case 6: 
            printf("| Número a ser deletado: "); 
            break;
		case 7: 
            printf("| Deseja continuar adicionando? >1< para NÃO, >qualquer valor< para SIM: "); 
            break;
		case 8: 
            printf("| Deseja continuar removendo? >1< para NÃO, >qualquer valor< para SIM: "); 
            break;
        case 9:
            printf("| [!] Lista atualizada.\n");
            break;
	}
}

/// @brief Sub-rotina para impressão da Lista Duplamente Encadeada na ordenação dinâmica.
/// @param aux Recebe um valor do tipo No_din, que conterá o início da lista.
/// @return Lista completa no terminal.
void imprimeInicioLista_din(No_din aux)
{
	if (aux == NULL) 
    {
		printf("<-> NULL");
	}
	else
	{
		if (aux->ant == NULL) 
        {
			printf(" NULL <-> %i ",aux->elemento);
		}
		else
		{
			printf("<-> %i ",aux->elemento);
		}
		imprimeInicioLista_din(aux->prox);
	}
}

/// @brief Sub-rotina para impressão da Lista Duplamente Encadeada na ordenação estática.
/// @param aux Recebe um valor do tipo No_est, que conterá o início da lista.
/// @return Lista completa no terminal.
void imprimeInicioLista_est(No_est aux)
{
	if (aux == NULL) 
    {
		printf("<-> NULL");
	}
	else
	{
		if (aux->ant == NULL) {
			printf(" NULL <-> %i ",aux->elemento);
		}
		else
		{
			printf("<-> %i ",aux->elemento);
		}
		imprimeInicioLista_est(aux->prox);
	}
}

/// @brief Sub-rotina para formatação da impressão da Lista Duplamente Encadeada na ordenação dinâmica.
/// @param lista Recebe um valor do tipo Lista_din, que conterá o início e o fim da lista.
/// @return Lista completa no terminal.
void printl_din(Lista_din lista)
{
	printf(">------------------<[ Ordenação Dinâmica: Lista ]>------------------<\n");
	imprimeInicioLista_din(lista->inicio);
	printf("\n>-------------------------------------------------------------------<\n|\n");
}

/// @brief Sub-rotina para formatação da impressão da Lista Duplamente Encadeada na ordenação estática.
/// @param lista Recebe um valor do tipo Lista_est, que conterá o início e o fim da lista.
/// @return Lista completa no terminal.
void printl_est(Lista_est lista)
{
	printf(">------------------<[ Ordenação Estática: Lista ]>------------------<\n");
	imprimeInicioLista_est(lista->inicio);
	printf("\n>-------------------------------------------------------------------<\n|\n");
}

/// @brief Sub-rotina para atualização da Lista Duplamente Encadeada na ordenação dinâmica.
/// @param lista Recebe um valor do tipo Lista_din, que conterá o início e o fim da lista.
/// @return Ordena os valores da lista em ordem crescente.
void updateCrescente(Lista_din lista)
{
    No_din aux = lista->inicio;
    while (aux != NULL) 
    {
        No_din valorMin = aux; // menor valor da lista
        No_din proximo = aux->prox; // valor depois do valor mínimo
        
        while (proximo != NULL) 
        {
            if (proximo->elemento < valorMin->elemento)
            {
                valorMin = proximo;
            }
            else
            {
                proximo = proximo->prox;
            }
        }
        
        if (valorMin != aux)
        {
            int salvarAuxValor = aux->elemento;
            aux->elemento = valorMin->elemento;
            valorMin->elemento = salvarAuxValor;
        }
        else
        {
            aux = aux->prox;
        }
    }
}

/// @brief Sub-rotina para atualização da Lista Duplamente Encadeada na ordenação estática.
/// @param lista Recebe um valor do tipo Lista_est, que conterá o início e o fim da lista.
/// @return Ordena os valores da lista em ordem decrescente.
void updateDecrescente(Lista_est lista)
{
    No_est aux = lista->inicio;

    while (aux != NULL) 
    {
        No_est valorMax = aux; // maior valor da lista
        No_est proximo = aux->prox; // valor depois do valor máximo
        
        while (proximo != NULL) 
        {
            if (proximo->elemento > valorMax->elemento)
            {
                valorMax = proximo;
            }
            else
            {
                proximo = proximo->prox;
            }
        }
        
        if (valorMax != aux)
        {
            int salvarAuxValor = aux->elemento;
            aux->elemento = valorMax->elemento;
            valorMax->elemento = salvarAuxValor;
        }
        else
        {
            aux = aux->prox;
        }
    }
    mensagem(9);
}

/// @brief Sub-rotina para inserção de valores na Lista Duplamente Encadeada na ordenação dinâmica.
/// @param lista Recebe um valor do tipo Lista_din, que conterá o início e o fim da lista.
/// @return Novo valor na lista.
void inserirDinamica(Lista_din lista)
{
	int n,resp;
	
	do
	{
		printl_din(lista);
		
		mensagem(5);
		scanf("%i",&n);
		
		criaNoLista_din(n,lista);
		
		updateCrescente(lista);
		
		printl_din(lista);
		
		mensagem(7);
		scanf("%i",&resp);

	} while (resp != 1);
}

/// @brief Sub-rotina para inserção de valores na Lista Duplamente Encadeada na ordenação estática.
/// @param lista Recebe um valor do tipo Lista_est, que conterá o início e o fim da lista.
/// @return Novo valor na lista.
void inserirEstatica(Lista_est lista)
{
	int n,resp,c=0;
	
	do
	{
		printl_est(lista);
		
		mensagem(5);
		scanf("%i",&n);
		
		criaNoLista_est(n,lista);
		
        c++;

        if (c == 5) 
        {
            updateDecrescente(lista);
            c = 0;
        }
        else
        {
            int insercoes = (5 - c);
            printf("| [!] Restam %i inserções para a lista ser atualizada.\n", insercoes);
        }

		printl_est(lista);	

        mensagem(7);
		scanf("%i",&resp);

	} while (resp != 1);
    
    if (c < 5)
    {
        updateDecrescente(lista);
        
        printl_est(lista);
    }
}

/// @brief Sub-rotina para deleção de valores na Lista Duplamente Encadeada na ordenação dinâmica.
/// @param lista Recebe um valor do tipo Lista_din, que conterá o início e o fim da lista.
/// @return Remoção de um valor da lista.
void deletarDinamica(Lista_din lista)
{
	int resp,v,flagAchou=0;

	do
    {
		printl_din(lista);

		mensagem(6);
		scanf("%i", &v);
		
        No_din aux = lista->inicio;
		
        while (aux != NULL)
        {
			if (v == aux->elemento)
            {
				if (aux == lista->inicio && aux == lista->fim)
                {
					flagAchou = 1;

					lista->inicio = NULL;
					
                    lista->fim = NULL;
				}
                else if (aux == lista->inicio)
                {
					flagAchou = 1;

					lista->inicio = aux->prox;
					
                    aux->prox->ant = NULL;
				}
                else if (aux == lista->fim)
                {
					flagAchou = 1;
				
                	lista->fim = aux->ant;
				
                	aux->ant->prox = NULL;
				}
                else
                {
					flagAchou = 1;
					
                    aux->ant->prox = aux->prox;
					
                    aux->prox->ant = aux->ant;
				}
				
                free(aux);
				
                updateCrescente(lista);

                printl_din(lista);
				
                break;
			}
            else
            {
				aux = aux->prox;
			}
		}

		if (flagAchou == 0)
        {
			printf("| %i não é um número da sua lista.\n",v);
		}

		flagAchou = 0;
		
        printl_din(lista);
		
        mensagem(8);
		scanf("%i", &resp);

	} while (resp != 1);
}

/// @brief Sub-rotina para deleção de valores na Lista Duplamente Encadeada na ordenação estática.
/// @param lista Recebe um valor do tipo Lista_est, que conterá o início e o fim da lista.
/// @return Remoção de um valor da lista.
void deletarEstatica(Lista_est lista)
{
	int resp,v,flagAchou=0;

	do
    {
		printl_est(lista);

		mensagem(6);
		scanf("%i", &v);
		
        No_est aux = lista->inicio;
		
        while (aux != NULL)
        {
			if (v == aux->elemento)
            {
				if (aux == lista->inicio && aux == lista->fim)
                {
					flagAchou = 1;

					lista->inicio = NULL;
					
                    lista->fim = NULL;
				}
                else if (aux == lista->inicio)
                {
					flagAchou = 1;

					lista->inicio = aux->prox;
					
                    aux->prox->ant = NULL;
				}
                else if (aux == lista->fim)
                {
					flagAchou = 1;
				
                	lista->fim = aux->ant;
				
                	aux->ant->prox = NULL;
				}
                else
                {
					flagAchou = 1;
					
                    aux->ant->prox = aux->prox;
					
                    aux->prox->ant = aux->ant;
				}
				
                free(aux);
				
                updateDecrescente(lista);

                printl_est(lista);
				
                break;
			}
            else
            {
				aux = aux->prox;
			}
		}

		if (flagAchou == 0)
        {
			printf("| %i não é um número da sua lista.\n",v);
		}

		flagAchou = 0;
		
        printl_est(lista);
		
        mensagem(8);
		scanf("%i", &resp);

	} while (resp != 1);
}

/// @brief Sub-rotina para o menu de seleção da Lista Duplamente Encadeada na ordenação dinâmica.
/// @param lista Recebe um valor do tipo Lista_din, que conterá o início e o fim da lista.
/// @return Navegação pelo subprograma da ordenação dinâmica.
void menuDinamica(Lista_din lista)
{
	int v;
	
	do
	{
		mensagem(3);
		scanf("%i",&v);
		system("cls || clear");
		
		switch(v)
		{
			case 0: 
                break; // quebra o loop
                break; // finaliza o case
			case 1: 
                inserirDinamica(lista); 
                break;
			case 2: 
                deletarDinamica(lista); 
                break;
		}

	} while (v != 0);
}

/// @brief Sub-rotina para o menu de seleção da Lista Duplamente Encadeada na ordenação estática.
/// @param lista Recebe um valor do tipo Lista_est, que conterá o início e o fim da lista.
/// @return Navegação pelo subprograma da ordenação estática.
void menuEstatica(Lista_est lista) 
{
	int v;
	
	do
	{
		mensagem(4);
		scanf("%i",&v);
		system("cls || clear");
		
		switch(v)
		{
			case 0: 
                break; //quebra o loop
                break; // finaliza o case
			case 1: 
                inserirEstatica(lista); 
                break;
			case 2: 
                deletarEstatica(lista); 
                break;
		}
	} while(v != 0);
}

/// @brief Sub-rotina para o menu de seleção da Lista Duplamente Encadeada nas ordenações dinâmica e estática.
/// @return Navegação pelo subprograma da ordenação dinâmica.
void menu()
{
    int v;

    Lista_din lista_din;
    Lista_est lista_est;

    lista_din = (Lista_din) malloc(sizeof(struct lista_din));
    lista_din->inicio = NULL;
    lista_din->fim = NULL;

    lista_est = (Lista_est) malloc(sizeof(struct lista_est));
    lista_est->inicio = NULL;
    lista_est->fim = NULL;

    do
    {
        mensagem(0);
        scanf("%i", &v);
        mensagem(2);

        switch (v)
        {
            case 0:
                system("cls || clear");
                mensagem(1);
                exit(0);
                break;
            case 1:
                system("cls || clear");
                menuDinamica(lista_din);
                break;
            case 2:
                system("cls || clear");
                menuEstatica(lista_est);
                break;
        }
    } while (v != 0);
}

/*
=------------------------=
=-> Programa Principal <-=
=------------------------=
*/
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	 
	menu();	
	
	return 0;
}