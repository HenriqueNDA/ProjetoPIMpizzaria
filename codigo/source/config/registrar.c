#include "sistema.h"
#include "registrar.h"
#include "../headers/structs.h"
#include "../designer/cabecalhos.h"
#include "../designer/escolha.h"
#include "../designer/tela.h"
#include "../login/registro.h"
#define SIZE 25

void registrarInf(){
	//Struct
	SYSTEM syt;
	
	//Criar pasta database
	mkdir("database");
	
	//telefone
	char telefone;
	int tel = 0;
	
	//cep
	char ncep;
	int cep = 0;
	
	//Numero
	char numero;
	int num = 0;
	
	//Escrever no arquivo sistema.dat
	FILE* fp;
	fp = fopen("database/sistema.dat", "ab");
	
	//Cabecalho
	system("cls");
	cabecalho("Cadastrar informações");
	
	//cor
	system("color 0F");
	
	//Texto informativo
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t A partir de agora, iremos configurar toda as informações a da pizzaria.\n");
	printf("\t\t\t\t\t\t\t Pressione 'ENTER' ou 'QUALQUER' tecla para proseguir...\n");
	getch();
	Sleep(600);
	
	//Escolha
	char cEscolha;
	
	do {
		//Cabecalho
		system("cls");
		cabecalho("Cadastrar informações");
		
		//Cadastrar nome da pizzaria;
		printf("\n No Campo abaixo, você deve informar qual é o NOME da pizzaria!\n");
		fflush(stdin);
		printf(" Nome: ");
		gets(syt.namePizzaria);
	
		//Cadastrar telefone da pizzaria
		printf("\n No Campo Abaixo, você deve informar qual é o TELEFONE da pizzaria!\n");
		fflush(stdin);
		printf(" Telefone: ");
		do{
			telefone = getch();
			if(isdigit(telefone) != 0){
				if( tel < 11){
					syt.telefone[tel] = telefone;
					tel++;
					printf("%c", telefone);
					if ( tel  == 2){
						printf("-");
					}
				}
			} else if ( telefone == 8 && tel){
				if ( tel == 2){
					printf("\b \b");
					syt.telefone[tel] = '\0';
					tel--;
					printf("\b \b");
				} else {
					syt.telefone[tel] = '\0'; 
					tel--;
					printf("\b \b");
				}
			} 
		} while ( telefone != 13);
		syt.telefone[tel] = '\0';
		
		//Cadastrar endereço da pizzaria:
		printf("\n\n No campo abaixo, você deve informar o ENDEREÇO da pizzaria!\n");
		fflush(stdin);
		printf(" CEP: ");
		do{
			ncep = getch();
			if(isdigit(ncep) != 0){
				if( cep < 8){
					syt.end.cep[cep] = ncep;
					cep++;
					printf("%c", ncep);
					if ( cep  == 5){
						printf("-");
					}
				}
			} else if ( ncep == 8 && cep){
				if ( cep == 5){
					printf("\b \b");
					syt.end.cep[cep] = '\0';
					cep--;
					printf("\b \b");
				} else {
					syt.end.cep[cep] = '\0'; 
					cep--;
					printf("\b \b");
				}
			} 
		} while ( ncep != 13);
		syt.end.cep[cep] = '\0';
		
		
		fflush(stdin);
		printf("\n Bairro: ");
		gets(syt.end.bairro);
		fflush(stdin);
		printf(" Endereço: ");
		gets(syt.end.endereco);
		fflush(stdin);
		printf(" Numero: ");
		do{
			numero = getch();
			if(isdigit(numero) != 0){
				if( num < 6){
					syt.end.numero[num] = numero;
					num++;
					printf("%c", numero);
				}
			} else if ( numero == 8 && num){
				syt.end.numero[num] = '\0';
				num--;
				printf("\b \b");
			} 
		} while ( numero != 13);
		syt.end.numero[num] = '\0';
		
		//Configurar pasta do servidor
		int check; 
		syt.endServidor = malloc(SIZE*sizeof(char));
		printf("\n\n No campo abaixo, você deve informar o ENDEREÇO da pasta do servidor!");
		printf("\n Endereço: ");
		gets(syt.endServidor);
		check = mkdir(syt.endServidor);
		
		cabecalhoFlista();
		cEscolha = escolhaConfimar();
	} while(cEscolha != 's');
	cabecalhoFlista();
	//Salvar informacoes, e proseguir com o cadastro
	printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para salvar as informações!\n");
	getch();
	
	if ( tel < 10 || cep < 8 || num < 1){
		system("color 04");
		cabecalhoFlista();
		printf("\n\n\t\t\t\t\t\t\t\t\tDados inválido");
		printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
		getch();
		registrarInf();
	} else {
		//Salvando informacoes
		system("color 01");
		syt.configurado = 1;
		fwrite(&syt, sizeof(SYSTEM), 1, fp);
		printf("\n\n\t\t\t\t\t\t\t\tSalvando informações...\n");
		Sleep(1600);
		fclose(fp);
		
		//Gerar id
		syt.idFranquia = idServidor();
		
		
		//Registrar ADMINISTRADOR
		registrarADM();
	}
}



