#include "gerarid.h"
#include "../pedidos/cadastrarpedido.h"
#include "../../headers/structs.h"

int idCardapio(){
	//Struct
	CARDAPIO cdp;
	
	//contador
	int contador = 200;
	
	//Definir produtos
	FILE* fp;
	fp = fopen("database/cardapio.dat", "rb");
	
	//While
	while(fread(&cdp, sizeof(CARDAPIO),1 , fp) == 1){
		contador++;
	}
	fclose(fp);
	return contador;
}

int idPedido(){
	//Struct
	PEDIDO pdd;
	
	//Contador
	int contador = 101;
	
	//Definir pedidos
	FILE* fp;
	fp = fopen("database/pedidos.dat", "rb");
	
	//While
	while(fread(&pdd, sizeof(PEDIDO), 1, fp) == 1){
		contador++;
	}
	fclose(fp);
	return contador;
}

int idEstoque(){
	//Struct
	ESTOQUE etq;
	
	//Contador
	int contador = 300;
	
	//Definir pedidos
	FILE* fp;
	fp = fopen("database/estoque.dat", "rb");
	
	//While
	while(fread(&etq, sizeof(ESTOQUE), 1, fp) == 1){
		contador++;
	}
	fclose(fp);
	return contador;
}

int idServidor(){
	/* //Struct
	SYSTEM syt;
	
	//Contador
	int contador = 1;
	
	//Definir pedidos
	FILE* fp;
	fp = fopen("database/estoque.dat", "rb");
	
	//While
	while(fread(&etq, sizeof(ESTOQUE), 1, fp) == 1){
		contador++;
	}
	fclose(fp);
	return contador; */
	
}
	
	

