#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototype
void menuInicial();
void menuAtendimento();
void solicitarAtendimento();

struct Pessoa
{
    
};


int main(){

    int opcao = 0;

    menuInicial();
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

    switch (opcao)
    {
    case 1:
        solicitarAtendimento();
        break;
    case 2:
        /* Listar Atendimentos Registrados */
        break;
    case 3:
        /* Listar Atendimento por Setor */
        break;
    case 4:
        /* Sair */
        break; 
    
    
    default:
        break;
    }

}

void menuInicial(){
    printf("-----| Bem-vindo ao sistema de atendimento |-----\n\n");
    printf("1 - Solicitar Atendimento\n");
    printf("2 - Listar Atendimentos Registrados\n");
    printf("3 - Listar Atendimento por Setor\n");
    printf("4 - Sair\n");
    printf(">>>:");
}

void menuAtendimento(){
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    printf(">>>: ");
}

void solicitarAtendimento(){
    char nome[100];
    char cpf[14];

    int selecaoAtendimento = 0;
    char tipoAtendimento[100];

    printf("Digite nome: ");
    fgets(nome, sizeof(nome), stdin);
    fflush(stdin);
    system("cls");

    printf("Digite CPF(inclua '.' e '-'): ");
    fgets(cpf, sizeof(cpf), stdin);
    fflush(stdin);
    system("cls");

    printf("Selecione a opção de atendimento:\n\n");
    menuAtendimento();
    scanf("%d", &selecaoAtendimento);
    fflush(stdin);
    system("cls");

    switch (selecaoAtendimento)
    {
    case 1:
        strcpy(tipoAtendimento, "1 - Abertura de Conta");
        printf("1 - Abertura de conta\n");
        break;

    case 2:
        strcpy(tipoAtendimento, "2 - Caixa");
        printf("2 - Caixa\n");
        break;

    case 3:
        strcpy(tipoAtendimento, "3 - Gerente Pessoa Física");
        printf("3 - Gerente Pessoa Física\n");
        break;

    case 4:
        strcpy(tipoAtendimento, "4 - Gerente Pessoa Jurídica");
        printf("4 - Gerente Pessoa Jurídica\n");
        break;

    default:
        printf("Opção inválida!\n");
        break;
    }

}