#include "funcionario.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/escolha.h"
#include "../../designer/tela.h"
#include "../../headers/structs.h"

void registrarFunc(){
	//Struct login
	LOGIN lgn;
	
	//Char para identificar a letra de escolhe do COMFIRMAR
	char cEscolha;

	//Variaveis para confirmar o NUMERO de nivel de acesso do funcionario
	char cnumero[50];
	char numero;
	int num = 0;
	
	//Variaveis para limitar o tamalho do TELEFONE, e digitiar apenas numero
	char telefone;
	int tel = 0;

	//Variaveis para limitar o tamalho do CPF, e digitiar apenas numero
	char ncpf;
	int cpf = 0;
	
	//Variaveis para digitar * na senha
	char senha[256] = {0};
	char buffer[256] = {0};
	char c;
    int pos = 0;
	
	//Escrever informações no funcionario.dat
	FILE* fp;
	fp = fopen("database/funcionario.dat", "ab");
	
	//cor
	system("color 0F"); // Preto
		
	//Cabecalho 
	system("cls");
	cabecalho("Cadastrar funcionário");
		
	//Definir acesso do funcionario
	fflush(stdin);
	printf("\n Digite o nível de acesso [1] - Administrativo  [2] - Atendente: ");
	do{
		numero = getch();
		if(isdigit(numero) != 0){
			cnumero[num] = numero;
			num++;
			printf("%c", numero);
		} else if ( numero == 8 && num){
			cnumero[num] = '\0';
			num--;
			printf("\b \b");
			}
		} while ( numero != 13);
		cnumero[num] = '\0';
		lgn.acesso = atoi(cnumero);
		
		if ( lgn.acesso == 1 || lgn.acesso == 2){
		//Definir Nome
		fflush(stdin);
		printf("\n Nome: ");
		gets(lgn.nameUser);
			
		//Definir cpf
		fflush(stdin);
		printf(" CPF: ");
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
			
		//Definir login
		fflush(stdin);
		printf(" Digite o login: ");
		gets(lgn.loginUser);
				
		//Digite a sua senha
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
		
		//Espaco
		printf("\n");
			
		if ( tel < 10 || cpf < 11 ){
			cabecalhoFlista();
			system("color 04"); // Errou
			printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
			getch();
			registrarFunc();				
		} else {
			int senhaCompare = strcmp(lgn.passUser, buffer);
			if( senhaCompare == 0){
				cabecalhoFlista();
				system("color 01"); // Acertou
				printf("\n\n\t\t\t\t\t\t\t\tCadastro efetuado com sucesso...\n");
				printf("\n\n\t\t\t\t\t\t\t\t\tSalvando dados...\n");
				Sleep(1600);
				printf("\n\n\t\t\t\t\t\t\t\t\tDados salvos...\n");
				fwrite(&lgn, sizeof(LOGIN), 1, fp);
				fclose(fp);
			} else {
				system("color 04"); // Errou
				printf("\n\n\t\t\t\t\t\t\t\tSenha incompatível!\n");
				telaTentar();
				registrarFunc();
			}
		}
	} else {
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tOpção Inválida!");
		telaTentar();
		registrarFunc();
	}
}

void listarFunc(){
	//Struct login
	LOGIN lgn;
	
	//Abrir users.dat
	FILE* fp;
	fp = fopen("database/funcionario.dat", "rb");
	
	//telefone
	char telefone;
	int tel = 0;
	
	//Variaveis para limitar o tamalho do CPF, e digitiar apenas numero
	char ncpf;
	int cpf = 0;
	
	//cor
	system("color 0F"); // Preto
	
	//Cabecalho
	system("cls");
	cabecalho("Lista de funcionários");
	
	while(fread(&lgn, sizeof(LOGIN), 1, fp) == 1){
		printf("\n Nome: %s\n Cpf: ", lgn.nameUser);
		for( cpf=0; cpf<strlen(lgn.cfpUser); cpf++){
			if ( cpf == 3 || cpf == 6 || cpf == 9){
				printf(".");
				printf("%c", lgn.cfpUser[cpf]);
			} else {
				printf("%c", lgn.cfpUser[cpf]);
			} 
		}
		printf("\n Email: %s\n login: %s\n", lgn.emailUser, lgn.loginUser);
		printf(" Telefone:");
		for( tel=0; tel < strlen(lgn.telefoneUser); tel++){
			if ( tel == 2){
				printf("-");
				printf("%c", lgn.telefoneUser[tel]);
			} else {
				printf("%c", lgn.telefoneUser[tel]);
			}
		}
		printf("\n Endereço: %s\n", lgn.enderecoUser);
		cabecalhoFlista();
	}
	fclose(fp);
	printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
	getch();
}

void procurarFunc(){
	//struct Login
	LOGIN lgn;
	
	//Abrir funcionario.dat
	FILE* fp;
	fp = fopen("database/funcionario.dat", "rb");
	
	//User
	int userValido = 0;
	
	//telefone
	char telefone;
	int tel = 0;
	
	//Variaveis para limitar o tamalho do CPF, e digitiar apenas numero
	char ncpf;
	int cpf = 0;
	
	//cor
	system("color 0F"); // Preto
	
	//Cabecalho
	system("cls");
	cabecalho("Procurar funcionário");
	
	//temp char
	char nome[101];
	
	//Definir nome do funcionario
	fflush(stdin);
	printf("\n Informe no campo abaixo, o nome do funcionário.\n");
	printf(" Nome: ");
	gets(nome);
	
	//While
	while(fread(&lgn, sizeof(LOGIN), 1, fp) == 1){
		if( !strcmp(nome, lgn.nameUser)){
			userValido = 1;
			break;
		} else {
			userValido = 0;
		}
	}
	
	if ( userValido == 1){
		//Cabecalho
		system("cls");
		cabecalho("Procurar funcionário");
			
		//Dados do funcionario
		printf("\n Nome: %s\n Cpf: ", lgn.nameUser, lgn.cfpUser);
		for( cpf=0; cpf<strlen(lgn.cfpUser); cpf++){
			if ( cpf == 3 || cpf == 6 || cpf == 9){
				printf(".");
				printf("%c", lgn.cfpUser[cpf]);
			} else {
				printf("%c", lgn.cfpUser[cpf]);
			} 
		}
		printf("\n Email: %s\n login: %s\n", lgn.emailUser, lgn.loginUser);
		printf(" Telefone: ", lgn.telefoneUser);
		for( tel=0; tel < strlen(lgn.telefoneUser); tel++){
			if ( tel == 2){
				printf("-");
				printf("%c", lgn.telefoneUser[tel]);
			} else {
				printf("%c", lgn.telefoneUser[tel]);
			}
		}
		printf("\n Endereço: %s\n", lgn.enderecoUser);
		cabecalhoFlista();
		
	} else if ( userValido == 0){
		cabecalhoFlista();
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuConfigFuncionario();
	}
	
	fclose(fp);
	printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para voltar para o menu!\n");
	getch();
}
