#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CONTATOS 255
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_EMAIL 50
#define TAM_TELEFONE 20

struct ContatoPessoal {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
};

struct ContatoTrabalho {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
};

struct ContatoPessoal listaContatosPessoais[MAX_CONTATOS];
struct ContatoTrabalho listaContatosTrabalho[MAX_CONTATOS];
int numContatosPessoais = 0;
int numContatosTrabalho = 0;

void extermina_linha(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int validaEmail(const char *email) {
    int tam = strlen(email);
    int temArroba = 0;
    int temPonto = 0;
    int posArroba = 0;

    for (int i = 0; i < tam; i++) {
        if (email[i] == '@') {
            temArroba = 1;
            posArroba = i;
        }
        if (email[i] == '.' && i > posArroba) {
            temPonto = 1;
        }
    }
    return temArroba && temPonto;
}

int verificaTelefoneUnico(const char *telefone, struct ContatoPessoal lista[], int numContatos, int indiceContatoAtual) {
    for (int i = 0; i < numContatos; i++) {
        if (i != indiceContatoAtual && strcmp(lista[i].telefone, telefone) == 0) {
            return 0;
        }
    }
    return 1;
}

void adicionarContatoPessoal() {
    if (numContatosPessoais < MAX_CONTATOS) {
        printf("Digite o seu nome: ");
        fgets(listaContatosPessoais[numContatosPessoais].nome, TAM_NOME, stdin);
        extermina_linha(listaContatosPessoais[numContatosPessoais].nome);

        printf("Digite o seu sobrenome: ");
        fgets(listaContatosPessoais[numContatosPessoais].sobrenome, TAM_SOBRENOME, stdin);
        extermina_linha(listaContatosPessoais[numContatosPessoais].sobrenome);

        printf("Digite o seu email: ");
        fgets(listaContatosPessoais[numContatosPessoais].email, TAM_EMAIL, stdin);
        extermina_linha(listaContatosPessoais[numContatosPessoais].email);

        while (!validaEmail(listaContatosPessoais[numContatosPessoais].email)) {
            printf("Email inválido! Digite novamente: ");
            fgets(listaContatosPessoais[numContatosPessoais].email, TAM_EMAIL, stdin);
            extermina_linha(listaContatosPessoais[numContatosPessoais].email);
        }

        printf("Digite o seu telefone: ");
        fgets(listaContatosPessoais[numContatosPessoais].telefone, TAM_TELEFONE, stdin);
        extermina_linha(listaContatosPessoais[numContatosPessoais].telefone);

        while (!verificaTelefoneUnico(listaContatosPessoais[numContatosPessoais].telefone, listaContatosPessoais, numContatosPessoais, numContatosPessoais)) {
            printf("Telefone já existente! Digite novamente: ");
            fgets(listaContatosPessoais[numContatosPessoais].telefone, TAM_TELEFONE, stdin);
            extermina_linha(listaContatosPessoais[numContatosPessoais].telefone);
        }

        numContatosPessoais++;
    } else {
        printf("Lista de contatos pessoais cheia!\n");
    }
}

void adicionarContatoTrabalho() {
    if (numContatosTrabalho < MAX_CONTATOS) {
        printf("Digite o nome do contato de trabalho: ");
        fgets(listaContatosTrabalho[numContatosTrabalho].nome, TAM_NOME, stdin);
        extermina_linha(listaContatosTrabalho[numContatosTrabalho].nome);

        printf("Digite o sobrenome do contato de trabalho: ");
        fgets(listaContatosTrabalho[numContatosTrabalho].sobrenome, TAM_SOBRENOME, stdin);
        extermina_linha(listaContatosTrabalho[numContatosTrabalho].sobrenome);

        printf("Digite o email do contato de trabalho: ");
        fgets(listaContatosTrabalho[numContatosTrabalho].email, TAM_EMAIL, stdin);
        extermina_linha(listaContatosTrabalho[numContatosTrabalho].email);

        printf("Digite o telefone do contato de trabalho: ");
        fgets(listaContatosTrabalho[numContatosTrabalho].telefone, TAM_TELEFONE, stdin);
        extermina_linha(listaContatosTrabalho[numContatosTrabalho].telefone);

        numContatosTrabalho++;
    } else {
        printf("Lista de contatos de trabalho cheia!\n");
    }
}

void listarContatosPessoais() {
    if (numContatosPessoais == 0) {
        printf("Nenhum contato pessoal cadastrado.\n");
        return;
    }

    printf("Lista de Contatos Pessoais:\n");
    for (int i = 0; i < numContatosPessoais; i++) {
        printf("NOME: %s %s\n", listaContatosPessoais[i].nome, listaContatosPessoais[i].sobrenome);
        printf("EMAIL: %s\n", listaContatosPessoais[i].email);
        printf("TELEFONE: %s\n", listaContatosPessoais[i].telefone);
        printf("\n");
    }
}

void listarContatosTrabalho() {
    if (numContatosTrabalho == 0) {
        printf("Nenhum contato de trabalho cadastrado.\n");
        return;
    }

    printf("Lista de Contatos de Trabalho:\n");
    for (int i = 0; i < numContatosTrabalho; i++) {
        printf("NOME: %s %s\n", listaContatosTrabalho[i].nome, listaContatosTrabalho[i].sobrenome);
        printf("EMAIL: %s\n", listaContatosTrabalho[i].email);
        printf("TELEFONE: %s\n", listaContatosTrabalho[i].telefone);
        printf("\n");
    }
}

void deletarContatoPessoal() {
    if (numContatosPessoais == 0) {
        printf("Não há contatos pessoais para deletar!\n");
        return;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o telefone do contato pessoal a ser deletado: ");
    fgets(telefone, TAM_TELEFONE, stdin);
    extermina_linha(telefone);

    int encontrado = 0;
    for (int i = 0; i < numContatosPessoais; i++) {
        if (strcmp(listaContatosPessoais[i].telefone, telefone) == 0) {
            encontrado = 1;
            numContatosPessoais--;
            listaContatosPessoais[i] = listaContatosPessoais[numContatosPessoais];
            printf("O contato pessoal foi deletado!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("O contato pessoal não foi encontrado!\n");
    }
}

void deletarContatoTrabalho() {
    if (numContatosTrabalho == 0) {
        printf("Não há contatos de trabalho para deletar!\n");
        return;
    }

    char email[TAM_EMAIL];
    printf("Digite o email do contato de trabalho a ser deletado: ");
    fgets(email, TAM_EMAIL, stdin);
    extermina_linha(email);

    int encontrado = 0;
    for (int i = 0; i < numContatosTrabalho; i++) {
        if (strcmp(listaContatosTrabalho[i].email, email) == 0) {
            encontrado = 1;
            numContatosTrabalho--;
            listaContatosTrabalho[i] = listaContatosTrabalho[numContatosTrabalho];
            printf("O contato de trabalho foi deletado!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("O contato de trabalho não foi encontrado!\n");
    }
}

void alterarContatoPessoal() {
    if (numContatosPessoais == 0) {
        printf("Não há contatos pessoais para alterar!\n");
        return;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o telefone do contato pessoal a ser alterado: ");
    fgets(telefone, TAM_TELEFONE, stdin);
    extermina_linha(telefone);

    int encontrado = 0;
    for (int i = 0; i < numContatosPessoais; i++) {
        if (strcmp(listaContatosPessoais[i].telefone, telefone) == 0) {
            encontrado = 1;

            printf("Novo email: ");
            fgets(listaContatosPessoais[i].email, TAM_EMAIL, stdin);
            extermina_linha(listaContatosPessoais[i].email);

            while (!validaEmail(listaContatosPessoais[i].email)) {
                printf("Email inválido! Digite novamente: ");
                fgets(listaContatosPessoais[i].email, TAM_EMAIL, stdin);
                extermina_linha(listaContatosPessoais[i].email);
            }

            printf("Novo telefone: ");
            fgets(listaContatosPessoais[i].telefone, TAM_TELEFONE, stdin);
            extermina_linha(listaContatosPessoais[i].telefone);

            while (!verificaTelefoneUnico(listaContatosPessoais[i].telefone, listaContatosPessoais, numContatosPessoais, i)) {
                printf("Telefone já existente! Digite novamente: ");
                fgets(listaContatosPessoais[i].telefone, TAM_TELEFONE, stdin);
                extermina_linha(listaContatosPessoais[i].telefone);
            }

            printf("Contato pessoal alterado!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("O contato pessoal não foi encontrado!\n");
    }
}

void alterarContatoTrabalho() {
    if (numContatosTrabalho == 0) {
        printf("Não há contatos de trabalho para alterar!\n");
        return;
    }

    char email[TAM_EMAIL];
    printf("Digite o email do contato de trabalho a ser alterado: ");
    fgets(email, TAM_EMAIL, stdin);
    extermina_linha(email);

    int encontrado = 0;
    for (int i = 0; i < numContatosTrabalho; i++) {
        if (strcmp(listaContatosTrabalho[i].email, email) == 0) {
            encontrado = 1;

            printf("Novo email: ");
            fgets(listaContatosTrabalho[i].email, TAM_EMAIL, stdin);
            extermina_linha(listaContatosTrabalho[i].email);

            while (!validaEmail(listaContatosTrabalho[i].email)) {
                printf("Email inválido! Digite novamente: ");
                fgets(listaContatosTrabalho[i].email, TAM_EMAIL, stdin);
                extermina_linha(listaContatosTrabalho[i].email);
            }

            printf("Novo telefone: ");
            fgets(listaContatosTrabalho[i].telefone, TAM_TELEFONE, stdin);
            extermina_linha(listaContatosTrabalho[i].telefone);

            printf("Contato de trabalho alterado!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("O contato de trabalho não foi encontrado!\n");
    }
}

void salvarContatosPessoais() {
    FILE *arquivo = fopen("contatos_pessoais.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    fwrite(&numContatosPessoais, sizeof(int), 1, arquivo);
    fwrite(listaContatosPessoais, sizeof(struct ContatoPessoal), numContatosPessoais, arquivo);

    fclose(arquivo);
    printf("Contatos pessoais salvos com sucesso!\n");
}

void salvarContatosTrabalho() {
    FILE *arquivo = fopen("contatos_trabalho.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    fwrite(&numContatosTrabalho, sizeof(int), 1, arquivo);
    fwrite(listaContatosTrabalho, sizeof(struct ContatoTrabalho), numContatosTrabalho, arquivo);

    fclose(arquivo);
    printf("Contatos de trabalho salvos com sucesso!\n");
}

void carregarContatosPessoais() {
    FILE *arquivo = fopen("contatos_pessoais.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar!\n");
        return;
    }

    fread(&numContatosPessoais, sizeof(int), 1, arquivo);
    fread(listaContatosPessoais, sizeof(struct ContatoPessoal), numContatosPessoais, arquivo);

    fclose(arquivo);
    printf("Contatos pessoais carregados com sucesso!\n");
}

void carregarContatosTrabalho() {
    FILE *arquivo = fopen("contatos_trabalho.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar!\n");
        return;
    }

    fread(&numContatosTrabalho, sizeof(int), 1, arquivo);
    fread(listaContatosTrabalho, sizeof(struct ContatoTrabalho), numContatosTrabalho, arquivo);

    fclose(arquivo);
    printf("Contatos de trabalho carregados com sucesso!\n");
}





int main() {
    int opcao;

    do {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar Contato Pessoal\n");
        printf("2. Adicionar Contato de Trabalho\n");
        printf("\n");
        printf("3. Listar Contatos Pessoais\n");
        printf("4. Listar Contatos de Trabalho\n");
        printf("\n");
        printf("5. Deletar Contato Pessoal\n");
        printf("6. Deletar Contato de Trabalho\n");
        printf("\n");
        printf("7. Alterar Contato Pessoal\n");
        printf("8. Alterar Contato de Trabalho\n");
        printf("\n");
        printf("9. Salvar Contatos Pessoais\n");
        printf("10. Salvar Contatos de Trabalho\n");
        printf("\n");
        printf("11. Carregar Contatos Pessoais\n");
        printf("12. Carregar Contatos de Trabalho\n");
        printf("13. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        clearBuffer(); 

        switch (opcao) {
            case 1:
                adicionarContatoPessoal();
                break;
            case 2:
                adicionarContatoTrabalho();
                break;
            case 3:
                listarContatosPessoais();
                break;
            case 4:
                listarContatosTrabalho();
                break;
            case 5:
                deletarContatoPessoal();
                break;
            case 6:
                deletarContatoTrabalho();
                break;
            case 7:
                alterarContatoPessoal();
                break;
            case 8:
                alterarContatoTrabalho();
                break;
            case 9:
                salvarContatosPessoais();
                break;
            case 10:
                salvarContatosTrabalho();
                break;
            case 11:
                carregarContatosPessoais();
                break;
            case 12:
                carregarContatosTrabalho();
                break;
            case 13:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 13);

    return 0;
}


