#include "tela.h"

void fullscreen(){
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void cabecalho(char cabecalho[]){
	//Data
	struct tm agora_data= {0};
    time_t tempo_data;
    time(&tempo_data);
    agora_data = *localtime(&tempo_data);
    
    //Cabecalho
	printf("======================================================================================================================================================================\n");
	printf("\n");
	printf("\t\t\t\t\t\t\t###################################################\n");
    printf("\t\t\t\t\t\t\t\t\t%s\n", cabecalho);
    printf("\t\t\t\t\t\t\t###################################################\n");
    printf("\t\t\t\t\t\t\t\t\tData: %d/%d/%d\n", agora_data.tm_mday, agora_data.tm_mon+1, agora_data.tm_year+1900);
	printf("======================================================================================================================================================================\n");
}

void telaRegistrarConfig(){
	printf("\n\n\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para proseguir com o cadastro do sistema!!");
	getch();
}

void telaRegistrarFunc(){
	printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para proseguir com o seu cadastro!!");
	getch();
}

void telaLogar(){
	printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para ir para a tela de login!!");
	getch();
}

void telaTentar(){
	printf("\n\n\t\t\t\t\t\tPressione 'ENTER' ou 'QUALQUER' tecla para tentar novamente!!");
	getch();
}
