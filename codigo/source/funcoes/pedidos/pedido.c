#include "pedido.h"
#include "cadastrarpedido.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/tela.h"
#include "../cliente/cliente.h"
#include "../gerarid/gerarid.h"
#include "../cardapio/cardapio.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

void listarPedidos(){
	//STRUCT
	PEDIDO pdd;
	
	//file
	FILE* fp;
	fp = fopen("database/pedidos.dat", "rb");
	
	//Cabecalho
	system("cls");
	cabecalho("Lista de pedidos");
	
	//int
	int opcao;
	
	//Cor
	system("color 0F"); // Preto
	
	//printf
	printf("\n 0 | Voltar\n");
	printf(" 1 | Delivery\n");
	printf(" 2 | Restaurante\n");
	printf(" 3 | Cancelados\n");
	cabecalhoFinal();
	scanf("%d", &opcao);	
	switch(opcao){
		case 0 :
			menuPedido();
			break;
		case 1 :
			//Cabecalho
			system("cls");
			cabecalho("Lista de pedidos");
		
			while(fread(&pdd, sizeof(PEDIDO), 1, fp) == 1){
				if ( pdd.tPedido == 1){
					printf("\n | ID: %d |\t| CLIENTE: %s |\t| VALOR: %.2f\t|", pdd.iPedido, pdd.dnPedido, pdd.vPedido);
				}
			}
			printf("\n");
			cabecalhoFlista();
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
			getch();
			break;
		case 2 :
			//Cabecalho
			system("cls");
			cabecalho("Lista de pedidos");
			
			while(fread(&pdd, sizeof(PEDIDO), 1, fp) == 1){
				if ( pdd.tPedido == 2){
					printf("\n | ID: %d |\t| MESA: %d |\t| VALOR: %.2f\t|", pdd.iPedido, pdd.mPedido, pdd.vPedido);
				}
			}
			printf("\n");
			cabecalhoFlista();
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
			getch();
			break;
		case 3 :
			//cancelado
			break;
		default :
			system("color 04"); // Errou
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			break;
	}
	fclose(fp);
}

void procurarPedido(){
	//STRUCT
	PEDIDO pdd;
	
	//file
	FILE* fp;
	fp = fopen("database/pedidos.dat", "rb");
	
	//Cabecalho
	system("cls");
	cabecalho("Procurar pedido");
	
	//temp id
	int tempId;
	
	//Perguntar id do pedido
	fflush(stdin);
	printf("\n Digite o ID: ");
	scanf("%d", &tempId);
	
	while(fread(&pdd, sizeof(PEDIDO), 1, fp) == 1){
		if ( tempId == pdd.iPedido){
			if ( pdd.tPedido == 1){
				printf("\n | ID: %d |\t| CLIENTE: %s |\t| VALOR: %.2f\t|", pdd.iPedido, pdd.dnPedido, pdd.vPedido);
			} else if ( pdd.tPedido == 2){
				printf("\n | ID: %d |\t| Mesa: %d |\t| VALOR: %.2f\t|", pdd.iPedido, pdd.mPedido, pdd.vPedido);
			}
		}
	}
	fclose(fp);
}
