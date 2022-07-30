#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Fila {
	int num;
	struct Fila* prox;
};

typedef struct Fila Fila; // troca "struct Fila" por "Fila"
typedef Fila* FilaPtr; // é um ponteiro de Fila, ao invés de escrever Fila* so escrever FilaPtr

void menu();
void inserirPilha(FilaPtr*,FilaPtr*, int);
void imprimePilha(FilaPtr);
void removePilha(FilaPtr*);

int main() {
	
	int escolha, numero, qntd;
	FilaPtr fimFila= NULL;
	FilaPtr inicioFila= NULL;
	
	menu();

	do {
		printf("\nEntre sua opcao: ");
		scanf("%d", &escolha);
		switch (escolha) {
			case 1:
				printf("Quantos numeros deseja adicionar na fila: ");
				scanf("%d", &qntd);
				for (int i=0 ; i<qntd ; i++) {
				printf("Entre com o numero: ");
				scanf("%d", &numero);
				inserirPilha(&fimFila, &inicioFila, numero);	
				}
				imprimePilha(inicioFila);
				break;
			case 2: 
				removePilha(&inicioFila);                                                                                                                                                                                                                                                                                   
				break;
			case 3:
				imprimePilha(inicioFila);
				break;
			case 4: 
				printf("\nSaindo...");
				break;
		}
	} while(escolha != 4);
}

void menu() {
	printf("Bem-vindo ao sistema de fila");
	printf("\n1 - Adicionar Elemento");
	printf("\n2 - Remover Elemento da fila");
	printf("\n3 - Mostrar fila");
	printf("\n4 - Sair");
}

void inserirPilha(FilaPtr *fimFila, FilaPtr *inicioFila ,int valor) {
	FilaPtr novo = (FilaPtr) malloc(sizeof(Fila));
	
	if (*fimFila == NULL) {
		novo->num = valor;
		novo->prox = NULL;
		*fimFila = novo;
		*inicioFila = novo;	
	} else {
		novo->num = valor;
		novo->prox = NULL;
		(*fimFila)->prox = novo;
		*fimFila = novo;
	}
}

void imprimePilha(FilaPtr aux){
	printf("\n");
	if (aux == NULL) {
		printf("A fila esta vazia.\n");
		puts("\nPressione enter para voltar ao menu.");
		getch();
		system("cls");
		menu();
	} else {
		puts("Fila:");
		while(aux != NULL){
			printf("%i--> ",aux->num);
			aux = aux->prox;
		}
		puts("NULL\n");
		puts("\nPressione enter para voltar ao menu.");
		getch();
		system("cls");
		menu();
	}
}

void removePilha(FilaPtr *inicioFila) {
	if (*inicioFila == NULL) {
		printf("Fila Vazia!");
		return;
	}
	FilaPtr aux = *inicioFila;
	*inicioFila = (*inicioFila)->prox;
	aux->prox = NULL;
	printf("Excluido com sucesso!");  
}

