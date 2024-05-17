#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 255
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_EMAIL 50
#define TAM_TELEFONE 20

struct Contato {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];
    char email[TAM_EMAIL];
    char telefone[TAM_TELEFONE];
};

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

void adicionarContato(struct Contato lista[], int *numContatos) {
    if (*numContatos < MAX_CONTATOS) {
        printf("Digite o seu nome: ");
        scanf("%49s", lista[*numContatos].nome);
        extermina_linha(lista[*numContatos].nome);
        clearBuffer();

        printf("Digite o seu sobrenome: ");
        scanf("%49s", lista[*numContatos].sobrenome);
        extermina_linha(lista[*numContatos].sobrenome);
        clearBuffer();

        printf("Digite o seu email: ");
        scanf("%49s", lista[*numContatos].email);
        extermina_linha(lista[*numContatos].email);
        clearBuffer();

        printf("Digite o seu telefone: ");
        scanf("%19s", lista[*numContatos].telefone);
        extermina_linha(lista[*numContatos].telefone);
        clearBuffer();

        (*numContatos)++;
    } else {
        printf("Lista de contatos cheia!\n");
    }
}

void listarContatos(struct Contato lista[], int numContatos) {
    if (numContatos == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("NOME: %s\n", lista[i].nome);
        printf("SOBRENOME: %s\n", lista[i].sobrenome);
        printf("EMAIL: %s\n", lista[i].email);
        printf("TELEFONE: %s\n", lista[i].telefone);
        printf("\n");
    }
}

void deletarContato(struct Contato lista[], int *numContatos) {
    if (*numContatos == 0) {
        printf("Não há contatos para deletar!\n");
        return;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o telefone do contato a ser deletado: ");
    scanf("%19s", telefone);
    clearBuffer();

    int encontrado = 0;
    for (int i = 0; i < *numContatos; i++) {
        if (strcmp(lista[i].telefone, telefone) == 0) {
            encontrado = 1;
            (*numContatos)--;
            lista[i] = lista[*numContatos];
            printf("O contato foi deletado!\n");
        }
    }

    if (!encontrado) {
        printf("O contato não foi encontrado!\n");
    }
}

void salvarContatos(struct Contato lista[], int *numContatos) {
    FILE *arquivo = fopen("Agenda", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    int qtd = fwrite(lista, sizeof(struct Contato), *numContatos, arquivo);
    if (qtd != *numContatos) {
        printf("Erro ao escrever contatos no arquivo.\n");
        fclose(arquivo);
        return;
    }

    qtd = fwrite(numContatos, sizeof(int), 1, arquivo);
    if (qtd != 1) {
        printf("Erro ao escrever número de contatos no arquivo.\n");
    }

    printf("Contatos salvos com sucesso!\n");
    fclose(arquivo);
}

void carregarContatos(struct Contato lista[], int *numContatos) {
    FILE *arquivo = fopen("Agenda", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    int qtd = fread(lista, sizeof(struct Contato), MAX_CONTATOS, arquivo);
    if (qtd <= 0) {
        printf("Erro ao ler contatos do arquivo.\n");
        fclose(arquivo);
        return;
    }

    *numContatos = qtd;

    qtd = fread(numContatos, sizeof(int), 1, arquivo);
    if (qtd != 1) {
        printf("Erro ao ler número de contatos do arquivo.\n");
    }

    printf("Contatos carregados com sucesso!\n");
    fclose(arquivo);
}

int main() {
    struct Contato listaContatos[MAX_CONTATOS];
    int numContatos = 0;
    char opcao;

    do {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Deletar Contato\n");
        printf("4. Salvar Contatos\n");
        printf("5. Carregar Contatos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarContato(listaContatos, &numContatos);
                break;
            case '2':
                listarContatos(listaContatos, numContatos);
                break;
            case '3':
                deletarContato(listaContatos, &numContatos);
                break;
            case '4':
                salvarContatos(listaContatos, &numContatos);
                break;
            case '5':
                carregarContatos(listaContatos, &numContatos);
                break;
            case '6':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '6');

    return 0;
}
