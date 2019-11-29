#include "cliente.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/tela.h"
#include "../../designer/escolha.h"
#include "../../headers/structs.h"
#include "../pedidos/cadastrarpedido.h"
#include "../../menu/menu.h"

char dbCliente[]={"database/cliente.dat"};

void cadastrarCT(){
	//Struct
	CLIENTE ct;
	
	//Escrever no clientes.dat
	FILE* fp;
	fp = fopen(dbCliente, "ab");
	
	//cor
	system("color 0F"); // Preto
	
	//Escolha
	char cEscolha;
	
	//telefone
	char telefone;
	int tel = 0;
	
	//cpf
	char ncpf;
	int cpf = 0;
	
	//cep
	char ncep;
	int cep = 0;

	//Numero
	char numero;
	int num = 0;
	
	
	do{	
		//Cabecalho
		system("cls");
		cabecalho("Cadastrar cliente");
		
		//Limpar dados
		num = 0;
		cep = 0;
		tel = 0;
		cpf = 0;
		
		//Definir nome do cliente
		fflush(stdin);
		printf("\n Informe o nome do cliente: ");
		gets(ct.nome);
			
		//Definir telefone do cliente
		fflush(stdin);
		printf(" Informe o telefone: ");
		do{
			telefone = getch();
			if(isdigit(telefone) != 0){
				if( tel < 11){
					ct.telefone[tel] = telefone;
					tel++;
					printf("%c", telefone);
					if ( tel  == 2){
						printf("-");
					}
				}
			} else if ( telefone == 8 && tel){
				if ( tel == 2){
					printf("\b \b");
					ct.telefone[tel] = '\0';
					tel--;
					printf("\b \b");
				} else {
					ct.telefone[tel] = '\0'; 
					tel--;
					printf("\b \b");
				}
			} 
		} while ( telefone != 13);
		ct.telefone[tel] = '\0';
			
			
		//Definir o cfp do cliente
		fflush(stdin);
		printf("\n Informe o cfp: ");
		do{
			ncpf = getch();
			if(isdigit(ncpf) != 0){
				if( cpf < 11){
					ct.cpf[cpf] = ncpf;
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
					ct.cpf[cpf] = '\0';
					cpf--;
					printf("\b \b");
				} else {
					ct.cpf[cpf] = '\0'; 
					cpf--;
					printf("\b \b");
				}
			}
		} while ( ncpf != 13);
		ct.cpf[cpf] = '\0';
			
		//Definir endereco do cliente
		fflush(stdin);
		printf("\n Informe o cep: ");
		do{
			ncep = getch();
			if(isdigit(ncep) != 0){
				if( cep < 8){
					ct.loc.cep[cep] = ncep;
					cep++;
					printf("%c", ncep);
					if ( cep  == 5){
						printf("-");
					}
				}
			} else if ( ncep == 8 && cep){
				if ( cep == 5){
					printf("\b \b");
					ct.loc.cep[cep] = '\0';
					cep--;
					printf("\b \b");
				} else {
					ct.loc.cep[cep] = '\0'; 
					cep--;
					printf("\b \b");
				}
			} 
		} while ( ncep != 13);
		ct.loc.cep[cep] = '\0';
			
		fflush(stdin);
		printf("\n Informe o endereço: ");
		gets(ct.loc.endereco);
			
		//Numero da casa
		fflush(stdin);
		printf(" Informe o número da casa/apartamento: ");
		do{
			numero = getch();
			if(isdigit(numero) != 0){
				if( num < 6){
					ct.loc.numero[num] = numero;
					num++;
					printf("%c", numero);
				}
			} else if ( numero == 8 && num){
				ct.loc.numero[num] = '\0';
				num--;
				printf("\b \b");
			} 
		} while ( numero != 13);
		ct.loc.numero[num] = '\0';
		
		printf("\n");
		cabecalhoFlista();
		cEscolha = escolhaConfimar();
	} while(cEscolha != 's'); 
	
	//Confirmar dados
	if ( tel < 10 || cpf < 11 || cep < 8 || num < 1){
		cabecalhoFlista();
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
		printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
		getch();
		cadastrarCT();
	} else {
		//Informativo e salvar dados
		system("color 01"); // Acertou
		printf("\n\n\t\t\t\t\t\t\tCadastro efetuado com sucesso...\n");
		printf("\n\n\t\t\t\t\t\t\t\tSalvando dados...\n");
		Sleep(1600);
		fwrite(&ct, sizeof(CLIENTE), 1, fp);
	}
	//Fechar cliente.dat
	fclose(fp);
}






