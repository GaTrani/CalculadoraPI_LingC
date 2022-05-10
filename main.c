#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <stdarg.h>

int main()
{
    //DIFININDO A LINGUAGEM
    setlocale(LC_ALL, "Portuguese");        /* para a utilização de acentos */
    int x,y;
    HWND cW = GetConsoleWindow();
    x = GetSystemMetrics(SM_CXSCREEN);      /* quantidade de pixel por linhas da tela  */
    y = GetSystemMetrics(SM_CYSCREEN);      /* quantidade de pixel por coluna da tela  */

    //Posicao onde sera aberta a calculadora
    SetWindowPos( cW, 0, x/2-(7.5*45/2), y/2-(7.5*35), 0, 0, SWP_NOSIZE | SWP_NOZORDER );

    //Titulo e parametros da calculadora.
    system("title Calculadora FatecCalc");  /* Titulo da janela */
    system("mode con:cols=45 lines=30");    /* tamanho da calculadora */

    //Chamando o menu principal
    menu_principal();

    return 0;
}
