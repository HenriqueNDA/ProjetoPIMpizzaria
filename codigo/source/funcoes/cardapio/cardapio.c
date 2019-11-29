#include "cardapio.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/tela.h"
#include "../gerarid/gerarid.h"
#include "../pedidos/cadastrarpedido.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

void cadastrarCdp(){
	//int opcao
	int opcao;
	
	//Struct
	CARDAPIO cdp;
	
	//cabecalho
	system("cls");
	cabecalho("Cadastrar item ao cardápio");
	
	//Escrever no cardapiob.dat
	FILE* fp;
	fp = fopen("database/cardapio.dat", "ab");
	
	//Escolha
	char cEscolha;
	
	//Cor
	system("color 0F"); // Preto
	
	//cabecalho
	system("cls");
	cabecalho("Cadastrar item ao cardápio");		
		
	//char
	char digitado[50];
	char c;
	int i = 0;
		
	//Teste
	fflush(stdin);
	printf("\n Pressione '0' para voltar para o menu\n");
	printf("\n Informe a categoria do produto: \n\n [1] - Bebida \n [2] - Pizza \n [3] - Promoções  \n");
	cabecalhoFinal();
	scanf("%d", &cdp.cProduto);
	opcao = cdp.cProduto;
		
	switch (opcao){
		case 1 : 
			system("cls");
			cabecalho("Cadastrar bebidas ao cardápio");
			
			//Definir o nome do produto
			fflush(stdin);
			printf("\n Informe o nome da bebida: ");
			gets(cdp.nProduto);	
					
			//Definir o valor do produto
			fflush(stdin);
			printf(" Informe o valor da bebida R$: ");
			scanf("%f", &cdp.vProduto);
					
			//Definir a descricao do produto
			fflush(stdin);
			printf(" Informe a descricao da bebida: ");
			gets(cdp.dProduto);
				
			//Definir id
			cdp.iProduto = idCardapio();
			
			cabecalhoFlista();
			
			//Salvar informacoes, e proseguir com o cadastro
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para salvar as informações!\n");
			getch();
			
			if ( cdp.vProduto = 0){
				cabecalhoFlista();
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
				getch();
				cadastrarCdp();
			} else {
				system("color 01"); // Acertou
				//Escrever informações no cardapio.dat
				printf("\n\n\t\t\t\t\t\t\tCadastro efetuado com sucesso...\n");
				printf("\n\n\t\t\t\t\t\t\t\t  Salvando dados...\n");
				Sleep(1600);
				printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
				fwrite(&cdp, sizeof(CARDAPIO), 1, fp);
				break;
			}
		case 2 :
			//cabecalho
			system("cls");
			cabecalho("Cadastrar pizzas ao cardápio");
				
			//Definir o nome do produto
			fflush(stdin);
			printf("\n Informe o nome da pizza: ");
			gets(cdp.nProduto);	
					
			//Definir o valor do produto
			fflush(stdin);
			printf(" Informe o valor da pizza R$ ");
			scanf("%f", &cdp.vProduto);
					
			//Definir a descricao do produto
			fflush(stdin);
			printf(" Informe a descricao da pizza: ");
			gets(cdp.dProduto);
					
			//Definir id
			cdp.iProduto = idCardapio();
				
			cabecalhoFlista();
			
			//Salvar informacoes, e proseguir com o cadastro
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para salvar as informações!\n");
			getch();
				
			if ( cdp.vProduto < 0){
				cabecalhoFlista();
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
				getch();
				cadastrarCdp();
			} else {
				system("color 01"); // Acertou
				//Escrever informações no cardapio.dat
				printf("\n\n\t\t\t\t\t\t\tCadastro efetuado com sucesso...\n");
				printf("\n\n\t\t\t\t\t\t\t\t  Salvando dados...\n");
				Sleep(1600);
				printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
				fwrite(&cdp, sizeof(CARDAPIO), 1, fp);
				break;
			}
		case 3:
			//cabecalho
			system("cls");
			cabecalho(" Cadastrar promoção ao cardápio");
			
			//Definir o nome do produto
			fflush(stdin);
			printf("\n Informe o nome da promoção : ");
			gets(cdp.nProduto);	
					
			//Definir o valor do produto
			fflush(stdin);
			printf(" Informe o valor da promoção  R$ ");
			scanf("%f", &cdp.vProduto);
					
			//Definir a descricao do produto
			fflush(stdin);
			printf(" Informe a descricao do produto: ");
			gets(cdp.dProduto);
					
			//Definir id
			cdp.iProduto = idCardapio();
			
			cabecalhoFlista();
				
			//Salvar informacoes, e proseguir com o cadastro
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para salvar as informações!\n");
			getch();
				
			if ( cdp.vProduto < 0){
				cabecalhoFlista();
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
				getch();
				cadastrarCdp();
			} else {
				system("color 01"); // Acertou
				//Escrever informações no cardapio.dat
				printf("\n\n\t\t\t\t\t\t\tCadastro efetuado com sucesso...\n");
				printf("\n\n\t\t\t\t\t\t\t\t  Salvando dados...\n");
				Sleep(1600);
				printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
				fwrite(&cdp, sizeof(CARDAPIO), 1, fp);
				break;
			}
			case 0 :
				menuConfigCardapio();
				break;
		default :
			system("color 04"); // Errou
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			break;
		}
	fclose(fp);
}

void listarCdp(){
	//int opcao
	int opcao;
	
	//Struct
	CARDAPIO cdp;
	
	//cor
	system("color 0F"); // Preto
	
	//Escrever no cardapio.dat
	FILE* fp;
	fp = fopen("database/cardapio.dat", "rb");

	
	if ( fp == NULL){
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNenhum item cadastrado...\n");
		printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para cadastrar um novo item!\n");
		getch();
		cadastrarCdp();
	} else {
		//Cabecalho
		system("cls");
		cabecalho("Lista cardápio");
		
		//Checar existencia do cardaio.dat
		printf("\n 0 | Voltar\n");
		printf(" 1 | Listar bebidas\n");
		printf(" 2 | Listar pizzas\n");
		printf(" 3 | Promoções\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		switch (opcao){
			case 0 :
				menuConfigCardapio();
				break;
			case 1 :
				//Cabecalho
				system("cls");
				cabecalho("Cardápio Bebidas");
				
				//Espaco
				printf("\n");
					
				while(fread(&cdp, sizeof(CARDAPIO), 1, fp) == 1){
					if(opcao == cdp.cProduto){
						printf("| ID: %d\t| Nome: %s\t | Valor: R$ %.2f\t |Descrição: %s |\n", cdp.iProduto, cdp.nProduto, cdp.vProduto, cdp.dProduto);
					}
				}
				cabecalhoFlista();
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
				getch();
				break;
			case 2 :
				//Cabecalho
				system("cls");
				cabecalho("Cardápio Pizzas");
				
				//Espaco
				printf("\n");
				
				while(fread(&cdp, sizeof(CARDAPIO), 1, fp) == 1){
					if(opcao == cdp.cProduto){
						printf("| ID: %d\t| Nome: %s\t | Valor: R$ %.2f\t |Descrição: %s |\n", cdp.iProduto, cdp.nProduto, cdp.vProduto, cdp.dProduto);
					}
				}
				cabecalhoFlista();
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
				getch();
				break;
			case 3 :
				//Cabecalho
				system("cls");
				cabecalho("Cardápio Promoções");
					
				//Espaco
				printf("\n");
				
				while(fread(&cdp, sizeof(CARDAPIO), 1, fp) == 1){
					if(opcao == cdp.cProduto){
						printf("| ID: %d\t| Nome: %s\t | Valor: R$ %.2f\t |Descrição: %s |\n", cdp.iProduto, cdp.nProduto, cdp.vProduto, cdp.dProduto);
					}
				}
				cabecalhoFlista();
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
				getch();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		fclose(fp);
	}
}


