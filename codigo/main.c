/***************************************************
 * Bibliotecas                                     *
 * ************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <dir.h>

/***************************************************
 * Cabecalhos                                      *
 * ************************************************/
 
#include "source/config/sistema.h"
#include "source/config/registrar.h"
#include "source/designer/cabecalhos.h"
#include "source/designer/tela.h"
#include "source/funcoes/cliente/cliente.h"
#include "source/funcoes/cliente/editarcliente.h"
#include "source/funcoes/funcionario/funcionario.h"
#include "source/funcoes/pedidos/pedido.h"
#include "source/headers/structs.h"
#include "source/login/logar.h"
#include "source/menu/menu.h"
 
 /***************************************************
 * Inicio	                                        *
 * ************************************************/
 
 int main(){
 	setlocale(LC_ALL, "Portuguese");
 	SetConsoleTitle("Sistema - Pizzaria");
 	fullscreen();
 	verificarConfig();
 	return 0;
 }
