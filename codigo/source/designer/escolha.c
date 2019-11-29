#include "escolha.h"

char escolhaConfimar(){
    char cEscolha = 's';
    do{
    	printf("\n Deseja Confirmar ?(s/n): ");
    	scanf("%c", &cEscolha);
    	if(cEscolha == 's' || cEscolha == 'S' || cEscolha == 'n' || cEscolha == 'N') break;
	}while(cEscolha != 's' || cEscolha == 'S' || cEscolha != 'n' || cEscolha != 'N');

    return cEscolha;
}

char escolhaCadastro(){
    char cEscolha = 'n';
    do{
    	printf("\n Deseja realizar um novo cadastro ?(s/n): ");
    	scanf("%c", &cEscolha);
    	if(cEscolha == 's' || cEscolha == 'S' || cEscolha == 'n' || cEscolha == 'N') break;
	}while(cEscolha != 's' || cEscolha == 'S' || cEscolha != 'n' || cEscolha != 'N');

    return cEscolha;
}
