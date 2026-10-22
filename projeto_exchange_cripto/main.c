#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

    //Começo login

int main()
{
    inicializarCotacao();
    short int opcao_inicial;

    printf("==Bem-vindo ao Exchange Criptomoedas FEI ==\n");
    printf("O que voce deseja fazer? \n\n");
    printf("1 - Cadastrar usuario\n");
    printf("2 - Ja possui uma conta? Faca login\n");
    printf("3 - Entrar como administrador\n");
    scanf("%hd", &opcao_inicial);
    if (opcao_inicial == 1)
    {
        cadastroUsuario();
    }
    else if(opcao_inicial == 2){
        login();
    }
    else
    {
        printf("A opção não existe.");
    }

    return 0;
}
