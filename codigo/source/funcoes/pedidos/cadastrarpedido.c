#include "cadastrarpedido.h"
#include "pedido.h"
#include "header.h"
#include "../../designer/cabecalhos.h"
#include "../../designer/tela.h"
#include "../cliente/cliente.h"
#include "../estoque/addestoque.h"
#include "../estoque/estoque.h"
#include "../gerarid/gerarid.h"
#include "../cardapio/cardapio.h"
#include "../relatorios/relatorios.h"
#include "../../headers/listarcardapio.h"
#include "../../headers/structs.h"
#include "../../menu/menu.h"


void cadastrarPedido(){
	//Char
	int type;
	
	//Cabecalho
	system("cls");
	cabecalho("Cadastrar novo pedido");
	
	//Tipo do pedido
	fflush(stdin);
	printf("\nInforme o tipo do pedido [1] - Delivery | [2] - Mesa: ");
	scanf("%d", &type);
	
	//swtich
	switch (type){
		case 1:
			pedidoDelivery();
			break;
		case 2:
			pedidoMesa();
			break;
		default:
			printf("Opção Inválida!\n");
			getch();
			break;
	}
}

void pedidoDelivery(){
	//Structs
	CLIENTE ct;
	PEDIDO pdd;
	CARDAPIO cdp;
	PRODUTO pdt;
	
	//Escrever no carinho.dat
	FILE* carrinho;
	carrinho = fopen("database/carrinho.dat", "ab");
	
	//Ler o carinho.dat
	FILE* lcarrinho;
	lcarrinho = fopen("database/carrinho.dat", "rb");
	
	//Escrever no pedidos.dat
	FILE* pedidos;
	pedidos = fopen("database/pedidos.dat", "ab");
	
	//Ler arquivo cliente.dat
	FILE* lcliente;
	lcliente = fopen("database/cliente.dat", "rb");
	
	//Cliente
	int client = 0;
	
	//variaveis
	int confirm;
	
	//Cor
	system("color 0F"); // Preto
	
	//Char
	char tels[20];

	int cliente = 0;

	//telefone
	char telefone;
	int tel = 0;
	
	//Cabecalho
	system("cls");
	cabecalho("Novo pedido");
	
	//Informar numero da mesa
	fflush(stdin);
	printf("\n Informe o numero do cliente: ");
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
	
	//While
	while(fread(&ct, sizeof(CLIENTE), 1, lcliente) == 1){
		int telCompare = strcmp(tels, ct.telefone);
		if( telCompare == 0){
			cliente = 1;
			//Cabecalho
			system("cls");
			cabecalho("Novo pedido Delivery");
			
			printf("\nDados do cliente:");
			printf("\nNome: %s\nEndereco: %s, numero: %s\n", ct.nome , ct.loc.endereco, ct.loc.numero);
			cabecalhoFlista();
			printf("\nPressione 'ENTER' ou 'QUALQUER' tecla para continuar com o cadastro!\n");
			getch();
		}
	}
	
	if(cliente == 0){
		printf("\n\n\t\t\t\tNenhum cliente encontrado com esse telefone...\n");
		printf("\n\n\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para cadastrar um novo cliente!\n");
		getch();
		cadastrarCT();
	} else {
	}
	fclose(lcliente);
	
	//Goto
	ESCOLHA:
	
	//Limpar dados
	fflush(stdin);
		
	//Ler cardapio
	FILE* cardapio;
	cardapio = fopen("database/cardapio.dat", "rb");
	
	
	//Perguntar categoria do produto
	cabecalhoFlista();
	fflush(stdin);
	printf("\n Informe a categoria do produto: \n\n [1] - Bebida \n [2] - Pizza \n [3] - Promoções  \n");
	cabecalhoFinal();
	scanf("%d", &pdt.tcType);
	
	//Listar Pedidos
	switch (pdt.tcType){
		case 1 :
			lercdp( "Bebidas", 1);
			break;
		case 2 :
			lercdp( "Pizza", 2);
			break;
		case 3 :
			lercdp( "Promoções", 3);
			break;
		default :
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			goto ESCOLHA;
			break;
	}
	
	//Cabecalho
	printf("\n");
	cabecalhoFlista();
	
	//Perguntar qual id deseja incluir no carinho
	fflush(stdin);
	printf("\n Informe o id do item que deseja adicionar: ");
	scanf("%d", &pdt.icId);
	
	//Variavel
	int produtoValido = 0;
	
	//cabecalho
	cabecalhoInfo();
	printf("\n");
	
	while(fread(&cdp, sizeof(CARDAPIO), 1, cardapio) == 1){
		if( pdt.tcType == cdp.cProduto){
			if ( pdt.icId == cdp.iProduto){
				printf(" Nome: %s\n", cdp.nProduto);
				printf(" Valor: %.2f\n", cdp.vProduto);
				printf(" Descrição: %s", cdp.dProduto);
				produtoValido = 1;
				pdt.icValor = cdp.vProduto;
				strcpy(pdt.icNome, cdp.nProduto);
				break;
			}
		} 
	}
	
	if ( produtoValido == 0){
		//Informar que o id nao eh valido
		printf("\n\t\t\t\t\t\t\t\t\t ID inválido!\n\n");
		//texto informativo
		telaTentar();
		//Voltar para o comeco
		pedidoMesa();
	} else {
		printf("\n");
		cabecalhoFlista();
		printf("\n Deseja confirmar o pedido ? [1] - Sim | [0] - Não: ");
		scanf("%d", &confirm);
		if ( confirm != 1){
			system("color 04"); // Errou
			//Informar que a compra foi cancelada
			printf("\n\n\t\t\t\t\t\t\t\t\t Compra cancelada");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
			getch();
			//Cabecalho
			system("cls");
			cabecalho("Novo pedido");
			//Voltar para o comeco
			pedidoMesa();
			//Fechar
			fclose(cardapio);
		} else {
			confirm = 0;
			//Salva o item adicionado no carrinho.dat
			fwrite(&pdt, sizeof(PRODUTO), 1, carrinho);
		}
	}
	
	ADICIONAR:
		
	//Cabecalho
	system("cls");
	cabecalho("Novo pedido");	
	
	//Pergunta se deseja adicionar mais produtos ao carrinho
	printf("\n Deseja adicionar a produtos ao carrinho ? [1] - Sim | [0] - Não: ");
	scanf("%d", &confirm);
	
	if ( confirm == 1){
		confirm = 0;
		goto ESCOLHA;
	} else {
		fclose(carrinho);
		fclose(cardapio);
		
		//Mostra o carrinho
		float total = 0.00;
	
		//Inicio
		cabecalhoCarrinho();
		printf("\n");
		while(fread(&pdt, sizeof(PRODUTO), 1, lcarrinho) == 1){
			printf(" Produto: %s\n", pdt.icNome);
			printf(" Valor: %.2f\n", pdt.icValor);
			total += pdt.icValor;
		}
		cabecalhoFlista();
		printf("\n Total: %.2f\n\n", total);
		cabecalhoFlista();
		fclose(lcarrinho);
		
		PAGAMENTO:
			
		printf("\n Deseja confirmar o pagamento ? [1] - Sim | [0] - Não: ");
		scanf("%d", &confirm);
		
		if( confirm == 1){
			system("color 01"); // Acertou
			printf("\n\n\t\t\t\t\t\t\tPedido efetuado com sucesso...\n");
			printf("\n\n\t\t\t\t\t\t\t\t  Salvando dados...\n");
			Sleep(1600);
			printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
			pdd.sPedido = 1;
			pdd.tPedido = 1;
			strcpy(pdd.dnPedido, ct.nome);
			strcpy(pdd.dtPedido, ct.telefone);
			pdd.vPedido = total;
			pdd.iPedido = idPedido();
			fwrite(&pdd, sizeof(PEDIDO), 1, pedidos);
			fclose(pedidos);
			fclose(carrinho);
			fclose(lcarrinho);
			fclose(cardapio);
			apagarCarrinho();
		} else if ( confirm == 0){
			fclose(pedidos);
			fclose(carrinho);
			fclose(lcarrinho);
			fclose(cardapio);
			system("color 04"); // Errou
			apagarCarrinho();
			printf("\n\n\t\t\t\t\t\t\t\t\t Compra cancelada");
			printf("\n\n\t\t\t\t\t\t\t\t\t Voltando para o menu!");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla voltar para o menu!\n");
			getch();
			menuPrincipal();
		} else {
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			goto PAGAMENTO;
		}	
	} 
}

void pedidoMesa(){
	//Structs
	PEDIDO pdd;
	CARDAPIO cdp;
	PRODUTO pdt;
	
	//Escrever no carinho.dat
	FILE* carrinho;
	carrinho = fopen("database/carrinho.dat", "ab");
	
	//Ler o carinho.dat
	FILE* lcarrinho;
	lcarrinho = fopen("database/carrinho.dat", "rb");
	
	//Escrever no pedidos.dat
	FILE* pedidos;
	pedidos = fopen("database/pedidos.dat", "ab");
	
	//variaveis
	int confirm;
	
	//Cor
	system("color 0F"); // Preto
	
	//Cabecalho
	system("cls");
	cabecalho("Novo pedido");
	
	//Informar numero da mesa
	fflush(stdin);
	printf("\n Informe o numero da mesa: ");
	scanf("%d", &pdd.mPedido);

	//Goto
	ESCOLHA:
	
	
	fflush(stdin);
		
	//Ler cardapio
	FILE* cardapio;
	cardapio = fopen("database/cardapio.dat", "rb");
	
	
	//Perguntar categoria do produto
	cabecalhoFlista();
	fflush(stdin);
	printf("\n Informe a categoria do produto: \n\n [1] - Bebida \n [2] - Pizza \n [3] - Promoções  \n");
	cabecalhoFinal();
	scanf("%d", &pdt.tcType);
	
	//Listar Pedidos
	switch (pdt.tcType){
		case 1 :
			lercdp( "Bebidas", 1);
			break;
		case 2 :
			lercdp( "Pizza", 2);
			break;
		case 3 :
			lercdp( "Promoções", 3);
			break;
		default :
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			goto ESCOLHA;
			break;
	}
	
	//Cabecalho
	printf("\n");
	cabecalhoFlista();
	
	//Perguntar qual id deseja incluir no carinho
	fflush(stdin);
	printf("\n Informe o id do item que deseja adicionar: ");
	scanf("%d", &pdt.icId);
	
	//Variavel
	int produtoValido = 0;
	
	//cabecalho
	cabecalhoInfo();
	printf("\n");
	
	while(fread(&cdp, sizeof(CARDAPIO), 1, cardapio) == 1){
		if( pdt.tcType == cdp.cProduto){
			if ( pdt.icId == cdp.iProduto){
				printf(" Nome: %s\n", cdp.nProduto);
				printf(" Valor: %.2f\n", cdp.vProduto);
				printf(" Descrição: %s", cdp.dProduto);
				produtoValido = 1;
				pdt.icValor = cdp.vProduto;
				strcpy(pdt.icNome, cdp.nProduto);
				break;
			}
		} 
	}
	
	if ( produtoValido == 0){
		//Informar que o id nao eh valido
		printf("\n\t\t\t\t\t\t\t\t\t ID inválido!\n\n");
		//texto informativo
		telaTentar();
		//Voltar para o comeco
		pedidoMesa();
	} else {
		printf("\n");
		cabecalhoFlista();
		printf("\n Deseja confirmar o pedido ? [1] - Sim | [0] - Não: ");
		scanf("%d", &confirm);
		if ( confirm != 1){
			system("color 04"); // Errou
			//Informar que a compra foi cancelada
			printf("\n\n\t\t\t\t\t\t\t\t\t Compra cancelada");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!\n");
			getch();
			//Cabecalho
			system("cls");
			cabecalho("Novo pedido");
			//Voltar para o comeco
			pedidoMesa();
			//Fechar
			fclose(cardapio);
		} else {
			confirm = 0;
			//Salva o item adicionado no carrinho.dat
			fwrite(&pdt, sizeof(PRODUTO), 1, carrinho);
		}
	}
	
	ADICIONAR:
		
	//Cabecalho
	system("cls");
	cabecalho("Novo pedido");	
	
	//Pergunta se deseja adicionar mais produtos ao carrinho
	printf("\n Deseja adicionar a produtos ao carrinho ? [1] - Sim | [0] - Não: ");
	scanf("%d", &confirm);
	
	if ( confirm == 1){
		confirm = 0;
		goto ESCOLHA;
	} else {
		fclose(carrinho);
		fclose(cardapio);
		
		//Mostra o carrinho
		float total = 0.00;
	
		//Inicio
		cabecalhoCarrinho();
		printf("\n");
		while(fread(&pdt, sizeof(PRODUTO), 1, lcarrinho) == 1){
			printf(" Produto: %s\n", pdt.icNome);
			printf(" Valor: %.2f\n", pdt.icValor);
			total += pdt.icValor;
		}
		cabecalhoFlista();
		printf("\n Total: %.2f\n\n", total);
		cabecalhoFlista();
		fclose(lcarrinho);
		
		PAGAMENTO:
			
		printf("\n Deseja confirmar o pagamento ? [1] - Sim | [0] - Não: ");
		scanf("%d", &confirm);
		
		if( confirm == 1){
			system("color 01"); // Acertou
			printf("\n\n\t\t\t\t\t\t\tPedido efetuado com sucesso...\n");
			printf("\n\n\t\t\t\t\t\t\t\t  Salvando dados...\n");
			Sleep(1600);
			printf("\n\n\t\t\t\t\t\t\t\t  Dados salvos...\n");
			pdd.sPedido = 1;
			pdd.tPedido = 2;
			pdd.vPedido = total;
			pdd.iPedido = idPedido();
			fwrite(&pdd, sizeof(PEDIDO), 1, pedidos);
			fclose(pedidos);
			fclose(carrinho);
			fclose(lcarrinho);
			fclose(cardapio);
			apagarCarrinho();
		} else if ( confirm == 0){
			fclose(pedidos);
			fclose(carrinho);
			fclose(lcarrinho);
			fclose(cardapio);
			system("color 04"); // Errou
			apagarCarrinho();
			printf("\n\n\t\t\t\t\t\t\t\t\t Compra cancelada");
			printf("\n\n\t\t\t\t\t\t\t\t\t Voltando para o menu!");
			printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla voltar para o menu!\n");
			getch();
			menuPrincipal();
		} else {
			printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
			getch();
			goto PAGAMENTO;
		}	
	} 
}

