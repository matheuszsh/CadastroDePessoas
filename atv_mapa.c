#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho do Array para pessoas
#define arrayP 150

//Struct para dados da pessoa
struct Pessoa
{
    int id;

    char nome[100];
    char cpf[14];

    char tipoAtendimento[50];
    int idSetor;
};

typedef struct Pessoa Pessoa;

//prototype
void menuInicial(Pessoa pessoa[], int novaPessoa);
void menuAtendimento();

void solicitarAtendimento(Pessoa pessoa[], int novaPessoa);
void listarAtenRegistrados(Pessoa pessoa[], int novaPessoa);

void pulaLinhas();

typedef struct Pessoa Pessoa;

int main(){

    Pessoa pessoa[arrayP];//33.000 - cada 220 unidade 
    int novaPessoa = 1;

    menuInicial(pessoa, novaPessoa);
    
}

void menuInicial(Pessoa pessoa[], int novaPessoa){
    
    int opcao = 0;

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
        //avaliar a necessidade de criar função para acessar e editar a pessoa dentro do array de pessoas
        /* Soliciatar Atendimento*/

        solicitarAtendimento(pessoa, novaPessoa);
        novaPessoa++;
        menuInicial(pessoa, novaPessoa);
        break;
    case 2:
        /* Listar Atendimentos Registrados */

        listarAtenRegistrados(pessoa, novaPessoa);
        menuInicial(pessoa, novaPessoa);
        break;
    case 3:
        /* Listar Atendimento por Setor */


        break;
    case 4:
        /* Sair */
        printf("Fim da sessão. Até logo.\n")
        break; 
    
    
    default:
        printf("Opção inválida!\n\n");
        menuInicial(pessoa, novaPessoa);
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

void solicitarAtendimento(Pessoa pessoa[], int novaPessoa){

    char nome[100];
    char cpf[14];
    char tipoAtendimento[50];
    int idSetor;

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
    
    //verificar a necessidade de transforma em função separada, para em caso de entrada inválida criar loop
    switch (selecaoAtendimento)
    {
    case 1:
        strcpy(tipoAtendimento, "1 - Abertura de Conta");
        idSetor = 1;
        break;

    case 2:
        strcpy(tipoAtendimento, "2 - Caixa");
        idSetor = 2;
        break;
    case 3:
        strcpy(tipoAtendimento, "3 - Gerente Pessoa Física");
        idSetor = 3;
        break;

    case 4:
        strcpy(tipoAtendimento, "4 - Gerente Pessoa Jurídica");
        idSetor = 4;
        break;

    default:
        printf("Opção inválida!\n");
        break;
    }

    //Definindo dados da pessoa
    pessoa[novaPessoa].id = novaPessoa;
    strcpy(pessoa[novaPessoa].nome, nome);
    strcpy(pessoa[novaPessoa].cpf, cpf);
    strcpy(pessoa[novaPessoa].tipoAtendimento, tipoAtendimento);
    pessoa[novaPessoa].idSetor = idSetor;

    //Exibição de dados da pessoa

    printf("<----| Pessoa %d Cadastrada |---->\n\n", pessoa[novaPessoa].id);

    printf("Identificador: %d\n", pessoa[novaPessoa].id);
    printf("Nome: %s", pessoa[novaPessoa].nome);
    printf("CPF: %s\n", pessoa[novaPessoa].cpf);
    printf("Tipo de atendimento: %s\n", pessoa[novaPessoa].tipoAtendimento);

    printf("\nPresione ENTER para retornar ao menu\n");
    char enter[30];
    fgets(enter, 30, stdin);
    pulaLinhas();
    
}

void listarAtenRegistrados(Pessoa pessoa[], int novaPessoa){
    

    printf("Lista de Pessoas Registradas: \n\n");
    for (int i = 1; i < novaPessoa; i++)
    {
        printf("Identificador: %d\n", pessoa[i].id);
        printf("Nome: %s", pessoa[i].nome);
        printf("CPF: %s\n", pessoa[i].cpf);
        printf("Tipo de atendimento: %s\n", pessoa[i].tipoAtendimento);
        printf("<--------------------------------------------------->\n");
    }

    printf("\nPresione ENTER para retornar ao menu\n");
    char enter[30];
    fgets(enter, 30, stdin);
    pulaLinhas();
}

void listarAtenPorSetor(Pessoa pessoa[], int novaPessoa){

   printf("Lista de Pessoas Registradas Por Setor: \n\n");
    for (int i = 1; i < novaPessoa; i++)
    {
        printf("Identificador: %d\n", pessoa[i].id);
        printf("Nome: %s", pessoa[i].nome);
        printf("CPF: %s\n", pessoa[i].cpf);
        printf("Tipo de atendimento: %s\n", pessoa[i].tipoAtendimento);
        printf("<--------------------------------------------------->\n");
    }

    printf("\nPresione ENTER para retornar ao menu\n");
    char enter[30];
    fgets(enter, 30, stdin);
    pulaLinhas();
    
}

void pulaLinhas(){
    for (size_t i = 0; i < 30; i++)
    {
        printf(">\n");
    }
    

}