#include "estoque.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/escolha.h"
#include "../../designer/tela.h"
#include "../cardapio/cardapio.h"
#include "../gerarid/gerarid.h"
#include "../pedidos/cadastrarpedido.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

void listarEstoque(){
	//struct
	ESTOQUE etq;
	
	//File
	FILE* fp;
	fp = fopen("database/estoque.dat", "rb");
	
	//data
	char ndata;
	int data = 0;
	int opcao;
	
	//Goto
	ESCOLHA: 
	
	//cor
	system("color 0F"); // Preto
	
	//cabecalho
	system("cls");
	cabecalho("Listar estoque");
	
	printf("\n 1 | Estoque disponível");
	printf("\n 2 | Estoque indisponível\n");
	cabecalhoFinal();
	scanf("%d", &opcao);
	
	switch (opcao){
		case 1 :
			//Cabecalho
			system("cls");
			cabecalho("Estoque disponível"); 
			
			//Espaco
			printf("\n");
			
			while( fread(&etq, sizeof(ESTOQUE), 1, fp) == 1){
				if ( etq.qEstoque >= 1 ){
					printf(" | Id: %d |\t | Nome: %s |\t | Quantidade: %d |\t | Data de entrega: ", etq.iEstoque, etq.nEstoque, etq.qEstoque);
					for( data=0; data < strlen(etq.dEstoque); data++){
						if ( data == 2 || data == 4){
							printf("/");
							printf("%c", etq.dEstoque[data]);
						} else {
							printf("%c", etq.dEstoque[data]);
						}
					}
				}
			printf("| \n");
			}
			cabecalhoFlista();
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
			getch();
			break;
			
		case 2:
			//Cabecalho
			system("cls");
			cabecalho("Estoque indisponível"); 
			
			//Espaco
			printf("\n");
			
			while( fread(&etq, sizeof(ESTOQUE), 1, fp) == 1){
				if ( etq.qEstoque <= 0 ){
					printf(" | Id: %d |\t | Nome: %s |\t | Quantidade: %d |\t | Data de entrega: ", etq.iEstoque, etq.nEstoque, etq.qEstoque);
					for( data=0; data < strlen(etq.dEstoque); data++){
						if ( data == 2 || data == 4){
							printf("/");
							printf("%c", etq.dEstoque[data]);
						} else {
							printf("%c", etq.dEstoque[data]);
						}
					}
				}
			printf("| \n");
			}
			cabecalhoFlista();
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
			getch();
			break;
			
		default :
			system("color 04"); // Errou
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			goto ESCOLHA;
			break;
	}
	fclose(fp);
}
