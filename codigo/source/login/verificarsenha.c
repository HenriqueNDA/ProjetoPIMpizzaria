#include "verificarsenha.h"
#include "../headers/structs.h"
#include "../menu/menu.h"

void verificarRSenha(){
	//Cabecalho
	system("cls");
	cabecalho("Relatorios");
	
	//Struct loginm
	LOGIN lgn;
	
	//ints
	int acessoValido = 0;
	int senhaValido = 0;
		
	//File
	FILE* fp;
	fp = fopen("database/funcionario.dat", "rb");
		
	//cor
	system("color 0F"); // Preto
	
	//Char e int senha
    char senha[256] = {0};
    char c;
    int pos = 0;
	
	//Digite a senha
	fflush(stdin);
	printf("\n Digite a sua senha: ");
	do {
        c = getch();
        
        if( isprint(c) ) 
        {
            senha[ pos++ ] = c;
            printf("%c", '*');
        }
        else if( c == 8 && pos )
        {
            senha[ pos-- ] = '\0';
            printf("%s", "\b \b");
        }
    } while( c != 13 );
	printf("\n");
	
	//While
	while(fread(&lgn, sizeof(LOGIN), 1, fp) == 1){
		if ( lgn.acesso == 1){
			acessoValido = 1;
			if ( !strcmp(lgn.passUser, senha)){
				senhaValido = 1;
				break;
			} else {
				senhaValido = 0;
			}
		} else {
			acessoValido = 0;
		}
	}
	
	if ( acessoValido == 1){
		if ( senhaValido == 1){
			system("color 01");
			cabecalhoFlista();
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\tEntrando...\n");
			Sleep(500);
			fclose(fp);
			menuRelatorio();
		} else if ( senhaValido == 0){
			cabecalhoFlista();
			system("color 04"); // Errou
			printf("\n\n\t\t\t\t\t\t\t\t    Senha inválida!\n");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
			getch(); 
		}
	} else if ( acessoValido == 0){
		cabecalhoFlista();
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\t\tAcesso não permitido\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
		getch();
	}
}

void verificarFSenha(){
	//Cabecalho
	system("cls");
	cabecalho("Funcionario");
	
	//Struct loginm
	LOGIN lgn;
	
	//ints
	int acessoValido = 0;
	int senhaValido = 0;
		
	//File
	FILE* fp;
	fp = fopen("database/funcionario.dat", "rb");
		
	//cor
	system("color 0F"); // Preto
	
	//Char e int senha
    char senha[256] = {0};
    char c;
    int pos = 0;
	
	//Digite a senha
	fflush(stdin);
	printf("\n Digite a sua senha: ");
	do {
        c = getch();
        
        if( isprint(c) ) 
        {
            senha[ pos++ ] = c;
            printf("%c", '*');
        }
        else if( c == 8 && pos )
        {
            senha[ pos-- ] = '\0';
            printf("%s", "\b \b");
        }
    } while( c != 13 );
	printf("\n");
	
	//While
	while(fread(&lgn, sizeof(LOGIN), 1, fp) == 1){
		if ( lgn.acesso == 1){
			acessoValido = 1;
			if ( !strcmp(lgn.passUser, senha)){
				senhaValido = 1;
				break;
			} else {
				senhaValido = 0;
			}
		} else {
			acessoValido = 0;
		}
	}
	
	if ( acessoValido == 1){
		if ( senhaValido == 1){
			system("color 01"); // Acertou
			cabecalhoFlista();
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\tEntrando...\n");
			Sleep(500);
			fclose(fp);
			menuConfigFuncionario();
		} else if ( senhaValido == 0){
			cabecalhoFlista();
			system("color 04"); // Errou
			printf("\n\n\t\t\t\t\t\t\t\t    Senha inválida!\n");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
			getch(); 
		}
	} else if ( acessoValido == 0){
		cabecalhoFlista();
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\t\tAcesso não permitido\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
		getch();
	}
}
