#include "relatorios.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/escolha.h"
#include "../../designer/tela.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

void listarRelatorios(){
	//Struct
	RELATORIO rltr;
	SYSTEM syt;	


	//Cabecalho
	system("cls");
	cabecalho("Relatorios");
	
	//Criar relatorios.dat
	FILE* fp;
	fp = fopen("relatorios.dat", "rb");
	
	//Ler sistema.dat
	FILE* fp1;
	fp1 = fopen("sistema.dat", "rb");
	fread(&syt, sizeof(SYSTEM), 1, fp1);
		
	//
	if( fp == NULL){
		printf("\n\n\t\t\t\t\t\t\t\t  Erro na leitura do arquivo!");	
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");	
		getch();
		menuPrincipal();
	} else {
		printf("\n Nome da pizzaria: %s", &syt.namePizzaria);
		while(fread(&rltr, sizeof(RELATORIO), 1, fp) == 1){
			printf("\n Pedidos processados: %s", rltr.pRelatorio);
		}
	}
	fclose(fp);
	fclose(fp1);
	getch();
}
