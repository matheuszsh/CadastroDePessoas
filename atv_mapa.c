#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho do Array para pessoas
#define arrayP 150

//prototype
void menuInicial();
void menuAtendimento();
void solicitarAtendimento();

//Struct para dados da pessoa
struct Pessoa
{
    int id;
    char nome[100];
    char cpf[14];
    char tipoAtendimento[100];
};

typedef struct Pessoa Pessoa;

int main(){

    Pessoa pessoa[arrayP];//33.000 - cada 220 unidade 
    menuInicial();

}

void menuInicial(){
    int opcao = 0;
    int novaPessoa = 0;

    printf("-----| Bem-vindo ao sistema de atendimento |-----\n\n");
    printf("1 - Solicitar Atendimento\n");
    printf("2 - Listar Atendimentos Registrados\n");
    printf("3 - Listar Atendimento por Setor\n");
    printf("4 - Sair\n");
    printf(">>>:");

    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

    switch (opcao)
    {
    case 1:
        solicitarAtendimento();
        novaPessoa++;
        //novaPessoa++;
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

void menuAtendimento(){
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    printf(">>>: ");
}

void solicitarAtendimento(){

    char *nome;
    char *cpf;
    char *tipoAtendimento;

    int selecaoAtendimento = 0;

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