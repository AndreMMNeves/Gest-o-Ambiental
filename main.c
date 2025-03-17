#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Informações dos Clientes

typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
} Cliente;

// Estrutura Funcionários 

typedef struct {
    int id;
    char nome[50];
    char cargo[30];
    float salario;
} Funcionario;

// Funções para o sistema

void login();
void menu();
void cadastrarCliente();
void cadastrarFuncionario();
void gerarRelatorioClientes();
void gerarRelatorioFuncionarios();

// Dados Temporarios
Cliente clientes[100];
Funcionario funcionarios[100];
int clienteCount = 0;
int funcionarioCount = 0;

int main() {
    login();
    menu();
    return 0;
}

// Função de login Basico
void login() {
    char username[20], password[20];
    printf("=== Sistema de Gerenciamento ===\n");
    printf("Usuário: ");
    scanf("%s", username);
    printf("Senha: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
        printf("Login bem-sucedido!\n\n");
    } else {
        printf("Usuário ou senha incorretos!\n");
        exit(1);
    }
}

// Função de menu principal
void menu() {
    int opcao;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Funcionário\n");
        printf("3. Relatório de Clientes\n");
        printf("4. Relatório de Funcionários\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarFuncionario();
                break;
            case 3:
                gerarRelatorioClientes();
                break;
            case 4:
                gerarRelatorioFuncionarios();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

// Função para cadastrar clientes
void cadastrarCliente() {
    printf("\n--- Cadastro de Cliente ---\n");
    clientes[clienteCount].id = clienteCount + 1;
    printf("Nome: ");
    scanf(" %[^\n]s", clientes[clienteCount].nome);
    printf("Endereço: ");
    scanf(" %[^\n]s", clientes[clienteCount].endereco);
    printf("Telefone: ");
    scanf(" %[^\n]s", clientes[clienteCount].telefone);
    clienteCount++;
    printf("Cliente cadastrado com sucesso!\n");
}

// Função para cadastrar funcionários
void cadastrarFuncionario() {
    printf("\n--- Cadastro de Funcionário ---\n");
    funcionarios[funcionarioCount].id = funcionarioCount + 1;
    printf("Nome: ");
    scanf(" %[^\n]s", funcionarios[funcionarioCount].nome);
    printf("Cargo: ");
    scanf(" %[^\n]s", funcionarios[funcionarioCount].cargo);
    printf("Salário: ");
    scanf("%f", &funcionarios[funcionarioCount].salario);
    funcionarioCount++;
    printf("Funcionário cadastrado com sucesso!\n");
}

// Função para gerar relatório de clientes
void gerarRelatorioClientes() {
    FILE *file = fopen("relatorio_clientes.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }

    printf("\n--- Relatório de Clientes ---\n");
    fprintf(file, "--- Relatório de Clientes ---\n");
    for (int i = 0; i < clienteCount; i++) {
        printf("ID: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n\n",
               clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
        fprintf(file, "ID: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n\n",
                clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
    }
    fclose(file);
    printf("Relatório de clientes gerado com sucesso! (relatorio_clientes.txt)\n");
}

// Função para gerar relatório de funcionários
void gerarRelatorioFuncionarios() {
    FILE *file = fopen("relatorio_funcionarios.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de relatório.\n");
        return;
    }

    printf("\n--- Relatório de Funcionários ---\n");
    fprintf(file, "--- Relatório de Funcionários ---\n");
    for (int i = 0; i < funcionarioCount; i++) {
        printf("ID: %d\nNome: %s\nCargo: %s\nSalário: %.2f\n\n",
               funcionarios[i].id, funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
        fprintf(file, "ID: %d\nNome: %s\nCargo: %s\nSalário: %.2f\n\n",
                funcionarios[i].id, funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
    }
    fclose(file);
    printf("Relatório de funcionários gerado com sucesso! (relatorio_funcionarios.txt)\n");
}
