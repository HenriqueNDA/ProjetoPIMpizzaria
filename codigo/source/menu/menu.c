#include "menu.h"
#include "../designer/cabecalhos.h"
#include "../designer/tela.h"
#include "../funcoes/cliente/cliente.h"
#include "../funcoes/cliente/editarcliente.h"
#include "../funcoes/estoque/addestoque.h"
#include "../funcoes/estoque/estoque.h"
#include "../funcoes/funcionario/funcionario.h"
#include "../funcoes/funcionario/editarfunc.h"
#include "../funcoes/pedidos/cadastrarpedido.h"
#include "../funcoes/pedidos/pedido.h"
#include "../funcoes/relatorios/relatorios.h"
#include "../headers/structs.h"
#include "../login/verificarsenha.h"
#include "../login/logar.h"

void menuPrincipal(){
	//Usado no switch case
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto
		
		//Cabecalho
		system("cls");
		cabecalho("Menu Principal");
		
		//Menu principal
		printf("\n 0 | Fazer Log off.\n");
		printf(" 1 | Pedido\n");
		printf(" 2 | Estoque\n");
		printf(" 3 | Relatórios\n");
		printf(" 4 | Configurações\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				verificarConfig();
				break;
			case 1:
				menuPedido();
				break;
			case 2 :
				menuEstoque();
				break;
			case 3:
				verificarRSenha();
				break;
			case 4 :
				menuConfig();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuPedido(){
	int opcao;
	do {
		//Cabecalho
		system("cls");
		cabecalho("Menu de pedidos");
		
		//Cor
		system("color 0F"); // Preto
		
		//Menu configuracoes
		printf("\n 0 | Voltar\n");
		printf(" 1 | Cadastrar\n");
		printf(" 3 | Listar\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuPrincipal();
				break;
			case 1 : 
				cadastrarPedido();
				break;
			case 3:
				listarPedidos();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuEstoque(){
	//Usado no switch case
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto
		
		//Cabecalho
		system("cls");
		cabecalho("Configurações estoque");
		
		//Menu principal
		printf("\n 0 | Voltar\n");
		printf(" 1 | Adicionar\n");
		printf(" 3 | Listar\n");
		printf(" 4 | Atualizar\n");
		printf(" 5 | Deletar\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuPrincipal();
				break;
			case 1 : 
				cadastrarEstoque();
				break;
			case 3 :
				listarEstoque();
				break;
			case 4 :
				atualizarEstoque();
				break;
			case 5 :
				removerEstoque();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuRelatorio(){
	//Cor
	system("color 0F"); // Preto
	
	listarRelatorios();
}

void menuConfig(){
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto

		//Cabecalho
		system("cls");
		cabecalho("Menu configurações");
		
		//Menu configuracoes
		printf("\n 0 | Voltar\n");
		printf(" 1 | Configurações do sistema\n");
		printf(" 2 | Informações do sistema\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuPrincipal();
				break;
			case 1 : 
				menuConfigSistema();
				break;
			case 2 :
				menuInfoSistema();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuConfigSistema(){
	//Opcao swithcase
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto
		
		//Cabecalho
		system("cls");
		cabecalho("Configurações do sistema");
		
		//Menu Configuracoes do sistema
		printf("\n 0 | Voltar\n");
		printf(" 1 | Funcionarios\n");
		printf(" 2 | Clientes\n");
		printf(" 3 | Cardapio\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuPrincipal();
				break;
			case 1 : 
				verificarFSenha();
				break;
			case 2 :
				menuConfigCliente();
				break;
			case 3:
				menuConfigCardapio();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuConfigFuncionario(){
	//Usado no switch case
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto
		
		//Cabecalho
		system("cls");
		cabecalho("Configurações funcionário");
		
		//Menu principal
		printf("\n 0 | Voltar\n");
		printf(" 1 | Adicionar\n");
		printf(" 2 | Procurar\n");
		printf(" 3 | Listar\n");
		printf(" 5 | Deletar\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuConfigSistema();
				break;
			case 1 : 
				registrarFunc();
				break;
			case 2 :
				procurarFunc();
				break;
			case 3 :
				listarFunc();
				break;
			case 5 :
				removerFunc();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuConfigCliente(){
	//Usado no switch case
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto

		//Cabecalho
		system("cls");
		cabecalho("Configurações cliente");
		
		//Menu principal
		printf("\n 0 | Voltar\n");
		printf(" 1 | Adicionar\n");
		printf(" 4 | Alterar informações\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuConfigSistema();
				break;
			case 1 :
				cadastrarCT();
				break;
			case 4 :
				editarCT();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
	} while (opcao != 0);
}

void menuConfigCardapio(){
	//Usado no switch case
	int opcao;
	do {
		//Cor
		system("color 0F"); // Preto

		//Cabecalho
		system("cls");
		cabecalho("Configurações cardápio");
		
		//Menu principal
		printf("\n 0 | Voltar\n");
		printf(" 1 | Adicionar\n");
		printf(" 3 | Lista\n");
		printf(" 4 | Editar\n");
		printf(" 5 | Remover\n");
		cabecalhoFinal();
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 0 :
				menuConfigSistema();
				break;
			case 1 : 
				cadastrarCdp();
				break;
			case 3 :
				listarCdp();
				break;
			case 4 :
				editarCdp();
				break;
			case 5 :
				removerCdp();
				break;
			default :
				system("color 04"); // Errou
				printf("\n\t\t\t\t\t\t\t\t\tOpção Inválida!\n");
				getch();
				break;
		}
		
	} while (opcao != 0);
}

void menuInfoSistema(){
	//Cabecalho
	system("cls");
	cabecalho("Informações do sistema");	
	printf("\n Sistema para pizzaria\n");
	printf("\n Número da versão: 1.0.0");
	printf("\n Release: 1.0.1\n");
	printf("\n Analista técnico: ");
	printf("\n  Paloma Santos Holanda da Silva\t\t\tRA: N439416");
	printf("\n  Ronny Cristian de Souza Silva \t\t\tRA: N422CD9\n");
	printf("\n Desenvolvedores:");
	printf("\n  Henrique Nascimento de Almeida\t\t\tRA: N4092B2\n");
	printf("\n Gestor de redes:");
	printf("\n  Matheus Vila Nova\t\t\t\t\tRA: N4435F0\n");
	printf("\n Suporte técnico: ");
	printf("\n  www.hasistemas.com.br/suporte");
	printf("\n  Número: 11 - 982805038\n");
	printf("\n Unip - Universidade paulista");
	printf("\n São Paulo, 2019 ");
	getch();
}

