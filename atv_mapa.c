#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Tamanho do Array para pessoas
#define arrayP 100

//Struct para dados da pessoa
struct Pessoa
{
    int id;

    char nome[100];
    char cpf[15];

    char tipoAtendimento[50];
    int idSetor;


};

typedef struct Pessoa Pessoa;

//prototype
void menuInicial(Pessoa pessoa[], int novaPessoa);
void menuAtendimento();

void solicitarAtendimento(Pessoa pessoa[], int novaPessoa);
void editarAtendimento(Pessoa pessoa[], int novaPessoa);

void listarAtenRegistrados(Pessoa pessoa[], int novaPessoa);
void listarAtenPorSetor(Pessoa pessoa[], int novaPessoa);
void pulaLinhas();

typedef struct Pessoa Pessoa;

int main(){
    setlocale(LC_ALL, "pt_BR_utf8");//Adicionando caracteres UTF-8 

    Pessoa pessoa[arrayP];

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
        //Soliciatar Atendimento ou editar atendimento

        printf("Para:\n\nSolicitar atendimento(1)\nEditar atendimento(2)\n\n>>>:");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");

        if (opcao == 1)
        {
            solicitarAtendimento(pessoa, novaPessoa);
            novaPessoa++;
        }
        else if (opcao == 2)
        {
            editarAtendimento(pessoa, novaPessoa);
        }
        else
        {
            printf("Opção Inválida.\n");
            printf("\nPresione ENTER para retornar ao menu\n");
            system("pause");
            system("cls");
        }
       
        menuInicial(pessoa, novaPessoa);
        break;
    case 2:
        //Listar Atendimentos Registrados

        listarAtenRegistrados(pessoa, novaPessoa);
        menuInicial(pessoa, novaPessoa);
        break;
    case 3:
        // Listar Atendimento por Setor
        listarAtenPorSetor(pessoa, novaPessoa);
        menuInicial(pessoa, novaPessoa);
        break;
    case 4:
        //Sair
        printf("Fim da sessão. Até logo.\n");
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

//Função para solicitar atendimento
void solicitarAtendimento(Pessoa pessoa[], int novaPessoa){

    char nome[100];
    char cpf[15];
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

    do{
    printf("Selecione a opção de atendimento:\n\n");
    menuAtendimento();
    scanf("%d", &selecaoAtendimento);
    fflush(stdin);
    system("cls");

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
        printf("\nPresione ENTER para escolher novamente.\n");
        system("pause");
        system("cls");
        selecaoAtendimento = 0;
        break;
    }
    }while (selecaoAtendimento == 0);
    
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

//Função para editar atendimento
void editarAtendimento(Pessoa pessoa[], int novaPessoa){
    int idEdit = -1;

    printf("Indique o id da pessoa:  ");
    scanf("%d", &idEdit);
    fflush(stdin);
    system("cls");

    if (idEdit >= 0 && idEdit < novaPessoa){
        for (int p = 0; p < novaPessoa; p++)
        {
            if(pessoa[p].id == idEdit){
                solicitarAtendimento(pessoa, idEdit);
            }
        }
    }
    else{
        printf("Id inexistente.\n");
        printf("\nPresione ENTER para retornar ao menu\n");
        system("pause");
        system("cls");
    }   
}

//Função pra listar todos atendimentos registrados.
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

//Função para listar somente por setor
void listarAtenPorSetor(Pessoa pessoa[], int novaPessoa){

    int opcao = 0;

    do{
    printf("Insira a opção do setor que deseja listar:\n\n");
    
    menuAtendimento();
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

    if(opcao > 0 && opcao <= 4){
        
        switch (opcao)
        {
        case 1:
            printf("Setor %d: Abertura de Conta\n", opcao);
            break;
        case 2:
            printf("Setor %d: Caixa\n", opcao);
            break;
        case 3:
            printf("Setor %d: Gerente Pessoa Física\n", opcao);
            break;
        case 4:
            printf("Setor %d: Gerente Pessoa Jurídica\n", opcao);
            break;
        
        default:
            break;
        }
        
        for (int i = 1; i < novaPessoa; i++)
        {
            if(pessoa[i].idSetor == opcao){
                printf("Identificador: %d\n", pessoa[i].id);
                printf("Nome: %s", pessoa[i].nome);
                printf("CPF: %s\n", pessoa[i].cpf);
                printf("Tipo de atendimento: %s\n", pessoa[i].tipoAtendimento);
                printf("<--------------------------------------------------->\n");
            }
        }
    }
    else{
        printf("Opção Inválida.\n");
        printf("\nPresione ENTER para retornar ao menu de listagem\n");
        system("pause");
        system("cls");
        opcao = 0;
    }
    }while (opcao == 0);  
    

    printf("\nPresione ENTER para retornar ao menu\n");
    system("pause");
    pulaLinhas();
}

//Mantém o histórico da atividade gerada anteriormente para cima de 30 linhas
void pulaLinhas(){
    for (size_t i = 0; i < 30; i++)
    {
        printf(">\n");
    }
    

}