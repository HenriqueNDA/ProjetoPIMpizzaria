#ifndef MENU_H
#define MENU_H

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
 
 //Menu principal
void menuPrincipal();

//Menu Pedido
void menuPedido();

//Menu Estoque
void menuEstoque();

//menu Relatorio
void menuRelatorio();

//Menu Configuração
void menuConfig();
void menuConfigSistema();
void menuConfigFuncionario();
void menuConfigCliente();
void menuConfigCardapio();

//Menu Info
void menuInfoSistema();

#endif
