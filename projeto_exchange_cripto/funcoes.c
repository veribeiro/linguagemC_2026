#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

//Começo atualizar cotação (nao esta completo)
void atualizarCotacao(void){
    printf("=== ATUALIZAR COTACAO ===\n");
    printf("Cotacao atual:\n\n");
    //Aqui é para mostrar para o usuario a cotacao do Bitcoin, Ethereum e Ripple. Vai pegar do arquivo cotacao.txt
    FILE *arquivo;
    arquivo = fopen("cotacao.txt", "r");
    if(arquivo==NULL){
        printf("Nao foi possivel abrir o arquivo.");
        return;
    }
    char linha[25];
    char nomeCripto[9];
    float valorCripto;
    while(fgets(linha, sizeof(linha), arquivo)!= NULL){
        if (sscanf(linha, "%s %f", nomeCripto, &valorCripto) == 2){  //==2 porque sao duas variaveis
        printf("%s: %.2f\n", nomeCripto, valorCripto);
        }
    }
    fclose(arquivo);

    short int opcao_atualizar;
    while(1){
    printf("\n\nO que voce deseja fazer?\n");
    printf("1 - Atualizar\n");
    printf("2 - Sair\n");
    scanf("%hd", &opcao_atualizar);
    while (getchar() != '\n'); // Limpa o buffer do teclado, porque está dando problema pro usuario sair dessa pagina
        if(opcao_atualizar==2){
            //Estava dando problema quando o usuario saisse
            printf("Opcao desejada: Sair\n");
            return;
        }
        else if(opcao_atualizar==1){
            FILE *arquivo;
            arquivo = fopen("cotacao.txt", "r");
            if (arquivo==NULL){
                printf("Nao foi possivel abrir o arquivo.");
                continue;
            }
            if(arquivo!=NULL){
                srand(time(NULL));
                char nomes[3][18] = {"BITCOIN", "ETHEREUM", "RIPPLE"};
                float valor[3] = {42500000.00, 120000000.00, 6.00}; //Valores fixos de inicio
                float variacao = (float)(rand() % 11 - 5)/100.0; //A conta pode ficar entre -5, 0 e 5 e depois vira 0.05 pois foi dividido por 10
                int i=0;     
                while (fgets(linha, sizeof(linha), arquivo)!= NULL && i<3){
                    if(sscanf(linha, "%s %f", nomes[i], &valor[i]) ==2){
                        i++;
                    }
                }
                fclose(arquivo);

                arquivo = fopen("cotacao.txt", "w");
                for(i=0; i<3; i++){
                    fprintf(arquivo, "%s %.2f\n", nomes[i], valor[i]*(1+variacao));
                }
                fclose(arquivo);          
                printf("Cotacao atualizada com sucesso!\n");
                printf("Nova cotacao:\n");
                arquivo = fopen("cotacao.txt", "r");
                if(arquivo!=NULL){
                    char nomeCripto[18];
                    float valorCripto;
                    while(fgets(linha, sizeof(linha), arquivo)!= NULL){
                    if(sscanf(linha, "%s %f", nomeCripto, &valorCripto) == 2){
                        printf("%s: %.2f\n", nomeCripto, valorCripto);
                    }
                    }
                    fclose(arquivo);
                }
            }
        }
        else{
        printf("Opcao invalida");
        }
    }
}

//Fim atualizar cotação
// -------------------------------------------------------------------------------------

//Comeco inicializar cotação
void inicializarCotacao(void){
    FILE *arquivo;
    arquivo = fopen("cotacao.txt", "r");
    if(arquivo==NULL){
        arquivo = fopen("cotacao.txt", "w");
        if(arquivo!=NULL){
            fprintf(arquivo, "BITCOIN 42500000.00\n");
            fprintf(arquivo, "ETHEREUM 120000000.00\n");
            fprintf(arquivo, "RIPPLE 6.00\n");
            fclose(arquivo);
        }
    }else{
        fclose(arquivo);
    }
}
//Fim inicializar cotação
// -------------------------------------------------------------------------------------

//Começo menu usuário
void menuUsuario(void){
    short int opcao_menu_usuario;
    while(1){
    printf("\n===MENU USUARIO===\n");
    printf("O que voce deseja fazer? \n\n");
    printf("1 - Consultar saldo\n");
    printf("2 - Consultar extrato\n");
    printf("3 - Depositar\n");
    printf("4 - Sacar\n");
    printf("5 - Comprar criptomoedas\n");
    printf("6 - Vender criptomoedas\n");
    printf("7 - Atualizar cotacao\n");
    printf("8 - Sair\n");

    scanf("%hd", &opcao_menu_usuario);

        if(opcao_menu_usuario==8){
            printf("Opcao desejada: Sair");
            break;
        }
        else if(opcao_menu_usuario==1){
            printf("Navegacao: Menu Usuario >> Consultar saldo\n\n");
            return;
        }
        else if(opcao_menu_usuario==2){
            printf("Navegacao: Menu Usuario >> Consultar extrato\n\n");
            return;
        }
        else if(opcao_menu_usuario==3){
            printf("Navegacao: Menu Usuario >> Depositar\n\n");
            return;
        }
        else if(opcao_menu_usuario==4){
            printf("Navegacao: Menu Usuario >> Sacar\n\n");
            return;
        }
        else if(opcao_menu_usuario==5){
            printf("Navegacao: Menu Usuario >> Comprar criptomoedas\n\n");
            return;
        }
        else if(opcao_menu_usuario==6){
            printf("Navegacao: Menu Usuario >> Vender criptomoedas\n\n");
            return;
        }
        else if(opcao_menu_usuario==7){
            printf("Navegacao: Menu Usuario >> Atualizar cotacao\n\n");
            atualizarCotacao();
        }
        else{
            printf("Opcao invalida. Tente novamente.");
            return;
        }
    }
}
// Fim menu usuário
// -------------------------------------------------------------------------------------

//Começo cadastro de usuário
void cadastroUsuario(void)
    {
        //Adicionar usuários
        FILE *arquivo;
        arquivo = fopen("cadastro.txt", "a");
        if (arquivo == NULL)
        {
            printf("Não foi possível abrir o arquivo.");
            return;
        }
        char cpf[12];
        printf("=== Cadastro de usuario ===\n");
        printf("Digite o CPF (0 para sair): \n");
        scanf("%s", cpf);
        if (strcmp(cpf, "0") == 0)
        {
            return;
        }
        while (strlen(cpf) != 11 || strcmp(cpf, "0") == 0)
        {
            printf("CPF incorreto. Digite novamente.\n");
            scanf("%s", cpf);
        }
        //Verificar se o CPF existe ou não
            FILE *arquivo_ler;
            arquivo_ler = fopen("cadastro.txt", "r");
            if(arquivo_ler == NULL){
                printf("Não foi possível abrir o arquivo.");
                return;
            }
            char linha[20];
            while(fgets(linha, sizeof(linha), arquivo_ler)!= NULL){
                char cpf_ler[12];
                sscanf(linha, "%s", cpf_ler);
                if(strcmp(cpf, cpf_ler) == 0){
                    printf("CPF existe. Digite outro CPF ou faça login. \n");
                    fclose(arquivo_ler);
                    return;
                    //Se não existir para o codigo
                }
                continue;
            }
            
        char senha[7];
        printf("Digite a senha(Precisa ter 6 digitos): \n");
        scanf("%s", senha);
        while (strlen(senha) !=6)
        {
            printf("Senha incorreta. Digite novamente: \n");
            scanf("%s", senha);
        }
        fprintf(arquivo, "%s %s\n", cpf, senha); //Adiciona para o arquivo, CPF e senha
        fclose(arquivo);
        printf("Cadastro realizado com sucesso!");
        return;
    }

    //Fim cadastro de usuário
    // -------------------------------------------------------------------------------------
    
    //Começo login
    void login(void){
        char cpf[12];
        int encontrado = 0;
        FILE *arquivo_ler;
            arquivo_ler = fopen("cadastro.txt", "r");
            if(arquivo_ler == NULL){
                printf("Não foi possível abrir o arquivo.");
                return;
            }
        printf("=== Login usuario ===\n");
        printf("Digite seu CPF: (Digite 0 para sair) \n");
        scanf("%s", cpf);
        if(strcmp(cpf, "0") == 0){
            return;
        }
        while (strlen(cpf) != 11 || strcmp(cpf, "0") == 0)
        {
            printf("CPF incorreto. Digite novamente: \n");
            scanf("%s", cpf);
        }
        char senha[7];
        printf("Digite sua senha: \n");
        scanf("%s", senha);
    while (strlen(senha) !=6)
        {
            printf("Senha incorreta. Digite novamente: \n");
            scanf("%s", senha);
        }
        char linha[20];
        while(fgets(linha, sizeof(linha), arquivo_ler)!=NULL){
            char cpf_ler[12], senha_ler[7];
            sscanf(linha, "%s %s", cpf_ler, senha_ler);
            if(strcmp(cpf, cpf_ler)== 0 && strcmp(senha, senha_ler)==0){
                encontrado = 1;
                printf("Login feito com sucesso!\n");
                menuUsuario();
                fclose(arquivo_ler);
            }
        }
        if(!encontrado){
            printf("CPF ou senha incorretos. Tente novamente.\n");
        }
        return;
        fclose(arquivo_ler);
}

//Fim login
// -------------------------------------------------------------------------------------