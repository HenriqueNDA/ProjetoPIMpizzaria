#include "logar.h"
#include "registro.h"
#include "../headers/structs.h"
#include "../menu/menu.h"

void logar(){
	//Struct
	LOGIN lgn;
	
	//temp
	char loginUser[27];
	
	//Validar 
	int userValido = 0;
	int passValido = 0;
	
	//Char e int senha
    char senha[256] = {0};
    char c;
    int pos = 0;
    
	//Abrir funcionarios.dat
	FILE* fp;
	fp = fopen("database/funcionario.dat", "rb");
	
	//color
	system("color 0F");
	//Cabecalho
	system("cls");
	cabecalho("FAÇA SEU LOGIN: ");
	
	//Entrar com ususario
	fflush(stdin);
	printf("\n Entre com o seu login: ");
	gets(loginUser);
	
	//Entrar com a senha
	fflush(stdin);
	printf(" Entre com a sua senha: ");
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
		if( !strcmp(loginUser, lgn.loginUser)){
			userValido = 1;
			if( !strcmp(senha, lgn.passUser)){
				passValido = 1;
				break;
			} else {
				passValido = 0;
			}
		}  else {
			userValido = 0;
		}
	}
	
	if(userValido==1){
		if(passValido==1){
			system("color 01");
			cabecalhoFlista();
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\tEntrando...\n");
			Sleep(500);
			fclose(fp);
			menuPrincipal();
		} else if(passValido==0){ 
			cabecalhoFlista();
			printf("\n\n\t\t\t\t\t\t\t\t    Senha inválida!\n");
			userValido = 0;
		}
	} else	if(userValido== 0) {
		cabecalhoFlista();
		printf("\n\n\t\t\t\t\t\t\t\t    Login inválido!\n");
	}
	
	
	if(userValido == 0 && passValido == 0){
		printf("\n\n\t\t\t\t\t\t\t\tUsuário não encontrado!\n");
		system("color 04");
		telaTentar();
		logar();
	} 
}

	
