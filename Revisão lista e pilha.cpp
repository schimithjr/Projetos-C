#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#define RANDOM(x) rand() %(x)
//estruturas
typedef struct dados dadosLista;
struct dados{
	int codigo;
	dadosLista *proximo;
};
//prototipos
void menu();
dadosLista* pushPilha(dadosLista *pilha);
dadosLista* pop(dadosLista *inicio);
void imprimir(dadosLista *pilha);
dadosLista* pushFila(dados *fila);
//principal
int main(){
	setlocale(LC_ALL, "");
	menu();
	return 0;
}
//funções
void menu(){
	char menu;
	dadosLista *pilha= NULL;
	dadosLista *fila= NULL;
	
	do{
		printf("\nA- PUSH PILHA \nB- POP PILHA\nC- EXIBIR PILHA\nD- PUSH FILA\nE- POP FILA\nF- EXIBIR FILA\nG- FINALIZAR\n ");
		scanf("%c", &menu);
		menu= toupper(menu);
		
		switch(menu){
			case 'A':
				printf("Push pilha");
				pilha= pushPilha(pilha);
				break;
			case 'B':
				printf("Pop pilha\n");
				pilha= pop(pilha);
				break;
			case 'C':
				printf("Exibição\n");
				imprimir(pilha);
				break;
			case 'D':
				printf("Push fila\n");
				fila= pushFila(fila);
				break;
			case 'E':
				printf("Pop fila\n");
				fila= pop(fila);
				break;
			case 'F':
				printf("\nExibição\n\n");
				imprimir(fila);
				break;
			case 'G':
				printf("PROGRAMA FINALIZADO.");
				break;
			default:
				printf("Opção inválida.\n");
		}
	}while (menu!='G');
}

dadosLista* pushPilha(dadosLista *pilha){
	dadosLista *novo= (dadosLista*) malloc(sizeof(dadosLista));
	
	novo->codigo= RANDOM(1000);
	
	novo->proximo= pilha;
	
	return novo;
}

void imprimir(dadosLista *pilha){
	if(pilha!=NULL){
		printf("\nEndereço %p  Código %i  Próximo %p", pilha, pilha->codigo, pilha->proximo);
		imprimir(pilha->proximo);
	}
}

dadosLista* pop(dadosLista *inicio){
	dadosLista *tmp= inicio->proximo; //guarda a segunda posição
	free(inicio); //apaga o primeiro elemento
	return tmp;//retorna o segundo como primeiro
}

dadosLista* pushFila(dados *fila){
	dadosLista *novo= (dadosLista*)malloc(sizeof(dadosLista));
	
	novo->codigo= RANDOM(1000);
	novo->proximo=NULL;
	
	if(fila==NULL){
		return novo;
	} else {
		dadosLista *tmp =fila;
		while(tmp->proximo!=NULL){
			tmp= tmp->proximo;
		}
		tmp->proximo= novo;
	}
	return fila;
}
