#ifndef STRUCTS_H
#define STRUCTS_H


/***************************************************
 * Structs                                         *
 * ************************************************/

typedef struct local LOCAL;
struct local{
	char endereco[150];
	char cep[50];
	char bairro[500];
	char numero[10];
};

typedef struct system SYSTEM;
struct system{
  char 	namePizzaria[50];
  char*  endServidor;
  int configurado;
  char telefone[20];
  int 	idFranquia;
  LOCAL end;
};

typedef struct login LOGIN;
struct login{
  char nameUser[101];
  char cfpUser[15];
  char emailUser[101];
  char telefoneUser[14];
  char enderecoUser[101];
  char loginUser[27];
  char passUser[256];
  int acesso;
};

typedef struct endereco ENDERECO;
struct endereco{
	char endereco[100];
	char cep[20];
	char numero[10];
};

typedef struct cliente CLIENTE;
struct cliente{
  char nome[50];
  char telefone[20];
  char cpf[30];
  ENDERECO loc;
};

typedef struct produto PRODUTO;
struct produto{
	//ID do cardapio do produto
 	int icId;
 	//Nome do cardapio do produto
 	char icNome[50];
	//Valor do cardapio do produto
 	float icValor;
	//Descrição do cardapio do produto
 	char icDescricao[100];
 	//Categoria do produto
 	int tcType;
};

typedef struct pedido PEDIDO;
struct pedido{
	//Tipo do pedido ( MESA, DELIVERY )
 	int tPedido;
 	//ID do pedido 
 	int iPedido;
 	//ID mesa do Estabelecimento 
 	int mPedido;
 	//Valor total
 	float vPedido;
 	//Status
 	int sPedido;
 	//Dado, nome do cliente
 	char dnPedido[50];
 	//Dado, telefone do cliente
 	char dtPedido[13];
};

typedef struct cardapio CARDAPIO;
struct cardapio{
	//Identificao do produto
	int iProduto;
	//Nome do produto
	char nProduto[50];
	//categoria do produto
	int cProduto;
	//valor do produto
	float vProduto;
	//char descricao do produto
	char dProduto[100];
};

typedef struct estoque ESTOQUE;
struct estoque{
	//Identificacao do estoque
	int iEstoque;
	//Nome do estoque
	char nEstoque[100];
	//Quantudade 
	int qEstoque;
	//Data
	char dEstoque[100];
};

typedef struct relatorio RELATORIO;
struct relatorio{
	//Valor total
	float vRelatorio;
	//Pedidos processados
	int pRelatorio;
	//Pedidos cancelados
	int cRelatorio;
};


#endif

