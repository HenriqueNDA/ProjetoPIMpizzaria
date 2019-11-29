#include "sistema.h"
#include "registrar.h"
#include "../headers/structs.h"

void verificarConfig(){
	//Struct
	SYSTEM syt;
	
	//Definir destino sistema.dat
	FILE* fp;
	fp = fopen("database/sistema.dat", "rb");
	fread(&syt, sizeof(SYSTEM),1 , fp);

	//Apagar temp.dat
	remove("database/temp.dat");
	
	//Checker configuracao inicial
	if( syt.configurado == 1){
		system("cls");
		cabecalho("SEJA BEM VINDO!");
		fclose(fp);
		telaLogar();
		logar();
		
	} else {
		system("cls");
		cabecalho("SEJA BEM VINDO!");
		telaRegistrarConfig();
		fclose(fp);
		registrarInf();
	}
}

