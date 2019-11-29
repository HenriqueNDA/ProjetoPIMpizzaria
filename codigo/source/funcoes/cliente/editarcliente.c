#include "editarcliente.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/tela.h"
#include "../cliente/cliente.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"

char cliente[]={"database/cliente.dat"};
char temp[]={"database/temp.dat"};

void editarCT(){
	//Struct
	CLIENTE ct;
	
	//Char
	char tels[20];
	
	//telefone
	char telefone;
	int tel = 0;
	
	//cep
	char ncep;
	int cep = 0;
	
	//Numero
	char numero;
	int num = 0;
	
	//Variaveis
	int found = 0;
	int reme = 0;

	//opcao
	int opcao;
	
	//Ler arquivo cliente.dat
	FILE* fp;
	fp = fopen(cliente, "rb");
	
	//Escrever arquivo temp.dat
	FILE* fp1;
	fp1 = fopen(temp, "wb");
	
	//cor
	system("color 0F"); // Preto
	
	//Cabecalho
	system("cls");
	cabecalho("Editar informa");
		
	//Definir numero de telefone
	fflush(stdin);
	printf("\n Informe o numero de telefone do cliente: ");
	do{
		telefone = getch();
		if(isdigit(telefone) != 0){
			if( tel < 11){
				tels[tel] = telefone;
				tel++;
				printf("%c", telefone);
				if ( tel  == 2){
					printf("-");
				}
			}
		} else if ( telefone == 8 && tel){
			if ( tel == 2){
				printf("\b \b");
				tels[tel] = '\0';
				tel--;
				printf("\b \b");
			} else {
				tels[tel] = '\0'; 
				tel--;
				printf("\b \b");
			}
		}
	} while ( telefone != 13);
	tels[tel] = '\0';
		
	//Escrever,e procurar o numero
	while ( fread(&	ct, sizeof(CLIENTE),1 , fp)==1){
		int telCompare = strcmp(tels, ct.telefone);
		if(telCompare == 0){
			found = 1;	
			tel = 0;
			
			ESCOLHA:
				
			//cor
			system("color 0F"); // Preto
			
			//Cabecalho
			system("cls");
			cabecalho("Alterar informações");
			
			//Informações do cliente
			printf("\n Dados do cliente: \n");
			printf(" Nome: %s\n", ct.nome);
			printf(" Telefone: ");
			for( tel=0; tel < strlen(ct.telefone); tel++){
				if (tel == 2){
					printf("-");
					printf("%c", ct.telefone[tel]);
				} else {
					printf("%c", ct.telefone[tel]);
				}
			}
			printf("\n Cep: ");
			for( cep=0; cep < strlen(ct.loc.cep); cep++){
				if( cep == 5){
					printf("-");
					printf("%c", ct.loc.cep[cep]);
				} else {
					printf("%c", ct.loc.cep[cep]);
				}
			}
			printf("\n Endereço: %s\t\tNumero: %s", ct.loc.endereco, ct.loc.numero);
			
			printf("\n");
			cabecalhoFlista();
			
			printf("\n 0 | Voltar\n");
			printf(" 1 | Alterar telefone\n");
			printf(" 2 | Alterar Endereço\n");
			cabecalhoFinal();
			scanf("%d", &opcao);
			
			switch (opcao){
				case 1:
					tel = 0;
					//Cabecalho
					system("cls");
					cabecalho(" Alterar telefone do cliente");
					
					//Telefone
					fflush(stdin);
					printf("\n Informe o novo telefone: ");
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
					printf("\n");
					
					if( tel < 10 ){
						cabecalhoFlista();
						system("color 04"); // Errou
						printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
						printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
						getch();
						goto ESCOLHA;
					} else {
						//Informativo para salvar os dados
						printf("\n");
						cabecalhoFlista();
						printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para salvar as informações!\n");
						getch();
						system("color 01"); // Acertou
						printf("\n\n\t\t\t\t\t\t\t\tEdição efetuado com sucesso...\n");
						printf("\n\n\t\t\t\t\t\t\t\t   Salvando dados...\n");
						Sleep(1600);
						fwrite(&ct, sizeof(CLIENTE),1 , fp1);
						printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...");
						reme = 1; 
						break;	
					}
				case 2:
					//Cabecalho
					system("cls");
					cabecalho(" Alterar endereço", ct.nome);
					
					//apagar o que esta escrito no cep
					cep = 0;
					
					//Digitar novo cep
					fflush(stdin);
					printf("\n Informe o novo cep: ");
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
						
					//Digitar novo endereço
					fflush(stdin);
					printf("\n Informe o endereço: ");
					gets(ct.loc.endereco);
						
						
					//Digitar novo numero
					fflush(stdin);
					printf(" Informe o novo n°: ");
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
					
					if( cep < 8 || num < 1){
						cabecalhoFlista();
						system("color 04"); // Errou
						printf("\n\n\t\t\t\t\t\t\t\tDados inválido");
						printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
						getch();
						goto ESCOLHA;
					} else {					
						//Informativo para salvar os dados
						printf("\n");
						cabecalhoFlista();
						printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para salvar as informações!\n");
						getch();
						system("color 01"); // Acertou
						printf("\n\n\t\t\t\t\t\t\t\tEdição efetuado com sucesso...\n");
						printf("\n\n\t\t\t\t\t\t\t\t   Salvando dados...\n");
						Sleep(1600);
						fwrite(&ct, sizeof(CLIENTE),1 , fp1);
						printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...");
						reme = 1; 
						break;
					}
				case 0:
					fclose(fp);
					fclose(fp1);
					menuConfigCliente();
					break;
				default :
					printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
					getch();
					break;
			}
		} else {
			fwrite(&ct, sizeof(CLIENTE),1 , fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	//Caso nao encontre
	if(found == 0){
		printf("\n");
		cabecalhoFlista();
		system("color 04"); // Errou
		printf("\n\n\t\t\t\t\t\t\t\tNão foi possivel encontrar o cadastro!\n");
		printf("\n\n\t\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' para voltar ao menu!\n");
		getch();
		menuConfigCliente();
	} else {
		fp = fopen(cliente, "wb");
		fp1 = fopen(temp, "rb");
		
		while(fread(&ct, sizeof(CLIENTE),1 , fp) == 1){
			if(feof(fp1)){
				break;
			}
			fwrite(&ct, sizeof(CLIENTE), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	
	//Apagar o cliente.dat antigo, e renomear o temp.dat
	if(reme == 1){
		remove("database/cliente.dat");
		rename("database/temp.dat", "database/cliente.dat");
	}
}
