#include "logar.h"
#include "registro.h"
#include "../headers/structs.h"

void registrarADM(){
	//Struct
	LOGIN lgn;
	
	//Variaveis para limitar o tamalho do CPF, e digitiar apenas numero
	char ncpf;
	int cpf = 0;
	
	//Variaveis para limitar o tamalho do TELEFONE, e digitiar apenas numero
	char telefone;
	int tel = 0;
	
	//Variaveis para digitar * na senha
	char senha[256] = {0};
	char buffer[256] = {0};
	char c;
    int pos = 0;
	
	//Escrever no arquivo funcionario.dat
	FILE* fp;
	fp = fopen("database/funcionario.dat", "ab");
	
	//cor
	system("color 0F"); // Preto
	
	//Cabecalho
	system("cls");
	cabecalho("CADASTRO DE FUNCIONÁRIOS");
	
	//Texto informativo 1
	telaRegistrarFunc();
	
	//Cabecalho
	system("cls");
	cabecalho("CADASTRO DE FUNCIONÁRIOS");
		
	//Escolha
	char cEscolha;
	
	do{
		//Cabecalho
		system("cls");
		cabecalho("CADASTRO DE FUNCIONÁRIOS");
		
		//Definir nome
		fflush(stdin);
		printf("\n Nome: ");
		gets(lgn.nameUser);
		
		//Definir cpf
		fflush(stdin);
		printf(" Cpf: ");
		do{
			ncpf = getch();
			if(isdigit(ncpf) != 0){
				if( cpf < 11){
					lgn.cfpUser[cpf] = ncpf;
					cpf++;
					printf("%c", ncpf);
					if ( cpf == 3 || cpf == 6){
						printf(".");
					}
					if ( cpf  == 9){
						printf("-");
					}
				}
			} else if ( ncpf == 8 && cpf){
				if ( cpf == 3 || cpf == 6 || cpf == 9){
					printf("\b \b");
					lgn.cfpUser[cpf] = '\0';
					cpf--;
					printf("\b \b");
				} else {
					lgn.cfpUser[cpf] = '\0'; 
					cpf--;
					printf("\b \b");
				}
			}
		} while ( ncpf != 13);
		lgn.cfpUser[cpf] = '\0';
		
		//Definir Email
		fflush(stdin);
		printf("\n Email: ");
		gets(lgn.emailUser);
		 
		//Definir telefone
		fflush(stdin);
		printf(" Telefone: ");
			do{
			telefone = getch();
			if(isdigit(telefone) != 0){
				if( tel < 11){
					lgn.telefoneUser[tel] = telefone;
					tel++;
					printf("%c", telefone);
					if ( tel  == 2){
						printf("-");
					}
				}
			} else if ( telefone == 8 && tel){
				if ( tel == 2){
					printf("\b \b");
					lgn.telefoneUser[tel] = '\0';
					tel--;
					printf("\b \b");
				} else {
					lgn.telefoneUser[tel] = '\0'; 
					tel--;
					printf("\b \b");
				}
			} 
		} while ( telefone != 13);
		lgn.telefoneUser[tel] = '\0';
				
		//Definir Endereço
		fflush(stdin);
		printf("\n Endereço: ");
		gets(lgn.enderecoUser);
		
		//Definir acesso
		/* 
		 1 - DONO/GERENTE
		 2 - Atendente
		*/
		lgn.acesso = 1;
	
		//Definir login
		fflush(stdin);
		printf(" Digite o login: ");
		gets(lgn.loginUser);
		
		//Definir senhas
		fflush(stdin);
		printf(" Digite a senha: ");
		do {
			c = getch();
			if ( isprint(c)){
				senha[ pos++ ] = c;
				printf("%c", '*');
			} else if ( c == 8 && pos){
				senha[ pos-- ] = '\0';
				printf("%s", "\b \b");
			}
		} while ( c != 13);
		strcpy(lgn.passUser, senha);

		//Pos 0
		pos = 0;
		
		//Definir novamente a senha
		fflush(stdin);
		printf("\n Digite novamente a senha: ");
		do {
			c = getch();
			if ( isprint(c)) {
				buffer[ pos++] = c;
				printf("%c", '*');
			} else if ( c == 8 && pos ){
				buffer[ pos-- ] = '\0';
				printf("%s", "\b \b");
			}
		} while ( c != 13);
		
		printf("\n");
		cabecalhoFlista();
		cEscolha = escolhaConfimar();
	} while(cEscolha != 's'); 
	
	if ( tel < 10 || cpf < 11){
		system("color 04"); // Errou
		cabecalhoFlista();
		printf("\n\n\t\t\t\t\t\t\t\t\tDados inválido");
		printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
		getch();
		registrarADM();
	} else {
		if ( !strcmp(lgn.passUser, buffer)){
			system("color 01"); // Acertou
			cabecalhoFlista();
			fwrite(&lgn, sizeof(LOGIN), 1, fp);
			printf("\n\n\t\t\t\t\t\t\t\tCadastro efetuado com sucesso...\n");
			printf("\n\n\t\t\t\t\t\t\t\t   Entrando na tela de login...");
			Sleep(1600);
			fclose(fp);
			logar();
		} else {
			system("color 04"); // Errou
			printf("\n\n\t\t\t\t\t\t\t\tSenha incompatível!\n\n");
			telaTentar();
			registrarADM();	
		}
	}
}

