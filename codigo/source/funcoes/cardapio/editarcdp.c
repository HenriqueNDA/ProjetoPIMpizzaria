#include "cardapio.h"
#include "editarcdp.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/tela.h"
#include "../gerarid/gerarid.h"
#include "../pedidos/cadastrarpedido.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

char dbCardapio[]={"database/cardapio.dat"}; 

void editarCdp(){
	//Files
	FILE *fp, *fp1;
	fp = fopen(dbCardapio, "rb");
	fp1 = fopen("database/temp.dat", "wb");
	
	//Struct
	CARDAPIO cdp;
	
	//cor
	system("color 0F"); // Preto
	
	//Int
	int id;
	int found = 0;
	int count = 0;
	int reme = 0;
	
	//Cabecalho
	system("cls");
	cabecalho("Editar cardápio");
	
	//Definir id do cardapio
	printf("\n Digite o id: ");
	scanf("%d", &id);
	
	while(1){
		fread(&cdp, sizeof(CARDAPIO),1 , fp);
		if(feof(fp)){
			break;
		}
		if(cdp.iProduto==id){
			reme = 1;
			found = 1;
			//Cabecalho
			system("cls");
			cabecalho("Editar cardápio");
			
			//Tabela
			printf("\n Nome: %s\n", cdp.nProduto);
			printf(" Valor: %.2f\n", cdp.vProduto);
			printf(" Descrição: %s\n", cdp.dProduto);
			cabecalhoFlista();
			
			//Definir nome
			fflush(stdin);
			printf("\n Digite o novo nome: ");
			gets(cdp.nProduto);
			
			//Definir preço
			fflush(stdin);
			printf(" Digite o novo valor: R$ ");
			scanf("%f", &cdp.vProduto);
			
			//Definir Descrição
			fflush(stdin);
			printf(" Digite a nova descrição: ");
			gets(cdp.dProduto);
			
			if ( cdp.vProduto < 1) {
				cabecalhoFlista();
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
				printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
				getch();
				editarCdp();
			} else {
				cabecalhoFlista();
				//Escrever informações no cardapio.dat
				system("color 01"); // Acertou
				printf("\n\n\t\t\t\t\t\t\t\tEdição efetuado com sucesso...\n");
				printf("\n\n\t\t\t\t\t\t\t\t   Salvando dados...\n");
				Sleep(1600);
				printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
				fwrite(&cdp, sizeof(CARDAPIO), 1, fp1);
			}
		} else {
			fwrite(&cdp, sizeof(CARDAPIO), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if(found == 0){
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuConfigCardapio();
	} else {
		fp = fopen(dbCardapio, "wb");
		fp1 = fopen("database/temp.dat", "rb");
		
		while(1){
			fread(&cdp, sizeof(CARDAPIO), 1, fp1);
			if(feof(fp1)){
				break;
			}
			fwrite(&cdp, sizeof(CARDAPIO), 1, fp);
		}
	fclose(fp);
	fclose(fp1);
	}
	//Apagar o funcionario.dat, e renomear o tempFuncionario.dat
	if(reme == 1 ){
		remove("database/cardapio.dat");
		rename("database/temp.dat", "database/cardapio.dat");
	}
}

void removerCdp(){
	//Files
	FILE *fp, *fp1;
	fp = fopen(dbCardapio, "rb");
	fp1 = fopen("database/temp.dat", "wb");
	
	//Struct
	CARDAPIO cdp;
	
	//cor
	system("color 0F"); // Preto
	
	//Cabecalho
	system("cls");
	cabecalho("Remover item do cárdapio");
	
	//Temp
	int idCardapio;
	
	//Int
	int found = 0;
	int count = 0;
	int reme = 1;
	
	//Teste
	fflush(stdin);
	printf("\n Informe o id: ");
	scanf("%d", &idCardapio);
	
	while(1){
		fread(&cdp, sizeof(CARDAPIO), 1, fp);
		if(feof(fp)){
			break;
		}
		if(cdp.iProduto == idCardapio){
			reme = 1;
			found = 1;
		} else {
			fwrite(&cdp, sizeof(CARDAPIO), 1, fp1);
		}
	} 
	fclose(fp);
	fclose(fp1);
	
	if(found==0){
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuConfigCardapio();
	} else {
		fp = fopen(dbCardapio, "wb");
		fp1= fopen("database/temp.dat", "rb");
		
		while(1){
			fread(&cdp, sizeof(CARDAPIO), 1, fp1);
			if(feof(fp1)){
				break;
			}
			fwrite(&cdp, sizeof(CARDAPIO), 1, fp);
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
		remove("database/cardapio.dat");
		rename("database/temp.dat", "database/cardapio.dat");
	}
}
