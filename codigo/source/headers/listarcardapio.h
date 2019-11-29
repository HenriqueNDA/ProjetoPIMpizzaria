#include "structs.h"

void lercdp( char titulo[10], int category ){
	//Struct
	CARDAPIO cdp;
	
	//Ler cardapio.dat
    FILE *fp;
    fp = fopen("database/cardapio.dat", "rb");

    printf("\n============================================================================== %s ==============================================================================\n", titulo);
    while(fread(&cdp, sizeof(CARDAPIO), 1, fp)){
        if(cdp.cProduto == category){
            printf("\n | ID = %d |\t\t\t\t\t| NOME = %s\t\t\t\t\t| VALOR = %.2f |", cdp.iProduto, cdp.nProduto, cdp.vProduto);
        }
    };

    fclose (fp);
}
