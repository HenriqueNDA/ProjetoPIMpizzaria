#include "addestoque.h"
#include "estoque.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/escolha.h"
#include "../../designer/tela.h"
#include "../cardapio/cardapio.h"
#include "../gerarid/gerarid.h"
#include "../pedidos/cadastrarpedido.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

void cadastrarEstoque(){
	//Struct
	ESTOQUE etq;
	CARDAPIO cdp;
	
	//Escrever no estoque.dat
	FILE* fp;
	fp = fopen("database/estoque.dat", "ab");
	
	//Ler cardapio.dat
	FILE* fp1;
	fp1 = fopen("database/cardapio.dat", "rb");
	
	//Variaveis
	int confirm;
	
	//Cabecalho
	system("cls");
	cabecalho("Adiocionar bebida ao estoque");
	
	//Perguntar o nome do produto
	fflush(stdin);
	printf("\n informe o id da bebida: ");
	scanf("%d", &etq.iEstoque);
	
	int estoqueValido = 0;
	
	if ( fp1 == NULL){
		printf("\n\n\t\t\t\t\t\t\t\t  Erro na leitura do arquivo!");	
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");	
		getch();
		menuPrincipal();
	} else {
		while(fread(&cdp, sizeof(CARDAPIO), 1, fp1) == 1){
			if( cdp.cProduto == 1){
				if ( etq.iEstoque == cdp.iProduto){
					cabecalhoInfo();
					printf("\n Nome da bebida: %s", cdp.nProduto);
					printf("\n Descrição: %s\n", cdp.dProduto);
					cabecalhoFlista();
					printf("\n Deseja confirmar o cadastro da bebida ? [1] - Sim | [0] - Não: ");
					scanf("%d", &confirm);
							
					if( confirm == 1){
						//Definir variaives
						etq.iEstoque = cdp.iProduto;
						strcpy(etq.nEstoque, cdp.nProduto);
									
						//Cabecalho
						system("cls");
						cabecalho(" Cadastrar bebida ao estoque");
								
						//Mostrar informacoes
						printf("\n Informações: \n");
						printf(" Id: %d", etq.iEstoque);
						printf("\n Nome: %s\n", etq.nEstoque);
								
						//Texto 
						cabecalhoFlista();
						printf("\n\t\t\t\t\t\t\t\tNova bebida cadastrada ao estoque!\n");
						printf("\n\n\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para continuar com o cadastro!");	
						getch();
								
						//Salvando dadoos
						system("color 01"); // Acertou
						fwrite(&etq, sizeof(ESTOQUE), 1, fp);
						printf("\n\n\t\t\t\t\t\t\t\t\tSalvando informações...\n");
						Sleep(1600);
						fclose(fp);
						fclose(fp1);
						atualizarEstoque();
					}
				} else {
					cabecalhoFlista();
					system("color 04"); // Errou
					printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
					printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
					getch();
					menuEstoque();
				}
			} else {
				cabecalhoFlista();
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tProduto inválido!\n");
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
				getch();
				menuEstoque();
			}
		}
	}
}

void atualizarEstoque(){
	//struct
	ESTOQUE etq;
	
	//files
	FILE *fp, *fp1;
	fp = fopen("database/estoque.dat", "rb");
	fp1 = fopen("database/temp.dat", "wb");
	
	//Int
	int id;
	int found = 0;
	int count = 0;
	int reme = 0;
	
	//data
	char ndata;
	int data = 0;
		
	//cor
	system("color 0F"); // Preto
		
	//Cabecalho
	system("cls");
	cabecalho("Atualizar estoque");
	
	//Perguntar id do estoque
	printf("\n Digite o id bebida que deseja atualizar: ");
	scanf("%d", &id);
	
	while(1){
		fread(&etq, sizeof(ESTOQUE), 1, fp);
		if(feof(fp)){
			break;
		}
		if(etq.iEstoque == id){
			reme = 1;
			found = 1;
			
			//Cabecalho
			system("cls");
			cabecalho("Atualizar estoque");
			
			//Mostrar informacoes
			printf("\n Nome: %s\n", etq.nEstoque);
			printf(" Quantidade: %d\n", etq.qEstoque);
			cabecalhoFlista();
			
			//Perguntar quantidade
			printf("\n Informe a quantidade do produto: ");
			scanf("%d", &etq.qEstoque);
			
			//Perguntar data
			printf(" Informe a data de entrada (00/00/00): ");
			do{
				ndata = getch();
				if(isdigit(ndata) != 0){
					if( data < 6){
						etq.dEstoque[data] = ndata;
						data++;
						printf("%c", ndata);
						if ( data == 2 || data == 4){
							printf("/");
						}
					}
				} else if ( ndata == 8 && data){
					if ( data == 2 || data == 4 ){
						printf("\b \b");
						etq.dEstoque[data] = '\0';
						data--;
						printf("\b \b");
					} else {
						etq.dEstoque[data] = '\0'; 
						data--;
						printf("\b \b");
					}
				}
			} while ( ndata != 13);
			etq.dEstoque[data] = '\0';
			
			if( data < 6){
				cabecalhoFlista();
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
				getch();
				atualizarEstoque();
			} else {
				//Escrever informações no estoque.dat
				system("color 01"); // Acertou
				printf("\n\n\t\t\t\t\t\t\t\tEdição efetuado com sucesso...\n");
				printf("\n\n\t\t\t\t\t\t\t\t   Salvando dados...\n");
				Sleep(1600);
				printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
				fwrite(&etq, sizeof(ESTOQUE), 1, fp1);
			}	
		} else {
			fwrite(&etq, sizeof(ESTOQUE), 1, fp1);
		}
	}
	
	fclose(fp);
	fclose(fp1);
	
	if(found == 0){
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuEstoque();
	} else {
		fp = fopen("database/estoque.dat", "wb");
		fp1 = fopen("database/temp.dat", "rb");
		
		while(1){
			fread(&etq, sizeof(ESTOQUE), 1, fp1);
			if(feof(fp1)){
				break;
			}
			fwrite(&etq, sizeof(ESTOQUE), 1, fp);
		}
	fclose(fp);
	fclose(fp1);
	}
	
	//Apagar o funcionario.dat, e renomear o tempFuncionario.dat
	if(reme == 1 ){
		remove("database/estoque.dat");
		rename("database/temp.dat", "database/estoque.dat");
	}
}

void removerEstoque(){
	//Files
	FILE *fp, *fp1;
	fp = fopen("database/estoque.dat", "rb");
	fp1 = fopen("database/temp.dat", "wb");
	
	//Structs
	ESTOQUE etq;
	
	//Cor
	system("color 0F"); // Preto
	
	//Temp
	int teste;
	
	//Int
	int found = 0;
	int count = 0;
	int reme = 0;
	
	//Cabecalho
	system("cls");
	cabecalho("Remover estoque");
	
	//Perguntar o nome do produto
	fflush(stdin);
	printf("\n informe o id da bebida: ");
	scanf("%d", &teste);
	
	while(1){
		fread(&etq, sizeof(ESTOQUE), 1, fp);
		if(feof(fp)){
			break;
		}
		if( teste == etq.iEstoque){
			reme = 1;
			found = 1;
		} else {
			fwrite(&etq, sizeof(ESTOQUE), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if( found == 0){
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuEstoque();
	} else {
		fp = fopen("database/estoque.dat", "wb");
		fp1 = fopen("database/temp.dat", "rb");
		
		while(1){
			fread(&etq, sizeof(ESTOQUE), 1, fp1);
			if(feof(fp1)){
				break;
			}
			fwrite(&etq, sizeof(ESTOQUE), 1, fp);
		}
		system("color 01"); // Acertou
		printf("\n\n\t\t\t\t\t\t\t\tItem removido com sucesso...\n");
		printf("\n\n\t\t\t\t\t\t\t\t   Salvando dados...\n");
		Sleep(1600);
		printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
	}
	fclose(fp);
	fclose(fp1);
	//Apagar o funcionario.dat, e renomear o tempFuncionario.dat
	if(reme == 1 ){
		remove("database/estoque.dat");
		rename("database/temp.dat", "database/estoque.dat");
	}	
}
