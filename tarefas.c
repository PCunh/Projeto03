#include <stdio.h>
#include <string.h>
#include "tarefas.h"


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
        scanf("%49s", lista[*numContatos].nome); // Para limitar a entrada para evitar estouro de buffer.
        extermina_linha(lista[*numContatos].nome);
        clearBuffer();

        printf("Digite o seu sobrenome: ");
        scanf("%49s", lista[*numContatos].sobrenome); // Para limitar a entrada para evitar estouro de buffer.
        extermina_linha(lista[*numContatos].sobrenome);
        clearBuffer();

        printf("Digite o seu email: ");
        scanf("%49s", lista[*numContatos].email); // Para limitar a entrada para evitar estouro de buffer.
        extermina_linha(lista[*numContatos].email);
        clearBuffer();

        printf("Digite o seu telefone: ");
        scanf("%19s", lista[*numContatos].telefone); // Para limitar a entrada para evitar estouro de buffer.
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
    scanf("%19s", telefone); // Limitar a entrada para evitar estouro de buffer.
    clearBuffer();

    int encontra = 0;
    for (int i = 0; i < *numContatos; i++) {
        if (strcmp(lista[i].telefone, telefone) == 0) {
            encontra = 1;
            
            *numContatos -= 1;
            lista[i] = lista[*numContatos]; 
            printf("O contato foi deletado!\n");
            
        }
    }

    if (!encontra) {
        printf("O contato não foi encontrado!\n");
        return;
    }
}




ErrorCode salvarContatos(struct Contato lista[], int *numContatos) {
    FILE *arquivo = fopen("Agenda", "ab"); 
    if (arquivo == NULL)
        return ABRIR;

    
    int qtd = fwrite(lista, sizeof(struct Contato), 255, arquivo);
    if (qtd == 0)
        return ESCREVER;

    
    qtd = fwrite(numContatos, sizeof(int), 1, arquivo);
    if (qtd == 0)
        return ESCREVER;

    if (fclose(arquivo) != 0)
        return FECHAR;

    return 0; 
}


ErrorCode carregarContatos(struct Contato lista[], int *numContatos) {
    FILE *arquivo = fopen("Agenda", "rb");
    if (arquivo == NULL)
        return ABRIR;

    int qtd = fread(lista, sizeof(struct Contato), MAX_CONTATOS, arquivo);
    if (qtd == 0)
        return LER;

    *numContatos += qtd;

    qtd = fread(numContatos, sizeof(int), 1, arquivo);
    if (qtd != 1)
        return LER;

    if (fclose(arquivo) != 0)
        return FECHAR;

    return 0; 
}