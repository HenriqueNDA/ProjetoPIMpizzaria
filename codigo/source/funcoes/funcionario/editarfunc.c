#include "editarfunc.h"
#include "funcionario.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/escolha.h"
#include "../../designer/tela.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

char dbFunc[]={"database/funcionario.dat"};

void removerFunc(){
	//Files
	FILE *fp, *fp1;
	fp = fopen(dbFunc, "rb");
	fp1 = fopen("database/temp.dat", "wb");
	
	//Struct
	LOGIN lgn;
	
	//cor
	system("color 0F"); // Preto
	
	//Informar login
	system("cls");
	cabecalho("Remover funcionário");
	
	//Temp
	char tempLogin[27];
	
	//Int
	int found = 0;
	int count = 0;
	int reme = 1;
	
	fflush(stdin);
	printf("\n Entre com o login: ");
	gets(tempLogin);
	
	while(1){
		fread(&lgn, sizeof(LOGIN), 1, fp);
		if(feof(fp)){
			break;
		}
		if(strcmp(tempLogin, lgn.loginUser) == 0){
			reme = 1;
			found = 1;
		} else {
			fwrite(&lgn, sizeof(LOGIN), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	if(found == 0){
		cabecalhoFlista();
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuConfigFuncionario();
	} else {
		fp = fopen(dbFunc, "wb");
		fp1 = fopen("database/temp.dat", "rb");
		
		while(1){
			fread(&lgn, sizeof(LOGIN), 1, fp1);
			if(feof(fp1)){
				break;
			}
			fwrite(&lgn, sizeof(LOGIN), 1, fp);
		}
		cabecalhoFlista();
		system("color 01"); // Acertou
		printf("\n\n\t\t\t\t\t\t\t\tFuncionário removido com sucesso...\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tSalvando dados...\n");
		Sleep(1600);
		printf("\n\n\t\t\t\t\t\t\t\t\tDados salvos...\n");
	}
	fclose(fp);
	fclose(fp1);
	
	//Apagar o funcionario.dat, e renomear o tempFuncionario.dat
	if(reme == 1 ){
		remove("database/funcionario.dat");
		rename("database/temp.dat", "database/funcionario.dat");
	}
}


