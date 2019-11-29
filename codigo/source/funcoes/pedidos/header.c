#include "header.h"
#include "pedido.h"
#include "cadastrarpedido.h"
#include "../../headers/structs.h"

void lerVendas(){
	//Struct
	PRODUTO pdt;
	
	//Ler pedidos.dat
	FILE* fp;
	fp = fopen("database/carrinho.dat", "rb");
	
	//Escre
	
	//Variaveis
	float total = 0.00;
	
	//Inicio
	cabecalhoCarrinho();
	printf("\n");
	while(fread(&pdt, sizeof(PRODUTO), 1, fp) == 1){
		printf(" Produto: %s\n", pdt.icNome);
		printf(" Valor: %.2f\n", pdt.icValor);
		total += pdt.icValor;
	}
	cabecalhoFlista();
	printf("\n Total: %.2f\n\n", total);
	fclose(fp);
}

void apagarCarrinho(){
	remove("database/carrinho.dat");
}

