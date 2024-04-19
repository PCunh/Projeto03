#include <stdio.h>
#include <string.h>
#include "tarefas.h"

void extermina_linha(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
    }
}

// Função para adicionar um novo contato à lista
void adicionarContato(struct Contato lista[], int *numContatos) {
    if (*numContatos < MAX_CONTATOS) {
        printf("Digite o seu nome: ");
        scanf("%s", lista[*numContatos].nome);
        extermina_linha(lista[*numContatos].nome);
        clearBuffer();

        printf("Digite o seu sobrenome: ");
        scanf("%s", lista[*numContatos].sobrenome);
        extermina_linha(lista[*numContatos].sobrenome);
        clearBuffer();

        printf("Digite o seu email: ");
        scanf("%s", lista[*numContatos].email);
        extermina_linha(lista[*numContatos].email);
        clearBuffer();

        printf("Digite o seu telefone: ");
        scanf("%s", lista[*numContatos].telefone);
        extermina_linha(lista[*numContatos].telefone);
        clearBuffer();

        (*numContatos)++;
    } else {
        printf("Lista de contatos cheia!\n");
    }
}

// Função para exibir todos os contatos na lista
void ListarContatos(struct Contato lista[], int numContatos) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("NOME: %s\n", lista[i].nome);
        printf("SOBRENOME: %s\n", lista[i].sobrenome);
        printf("EMAIL: %s\n", lista[i].email);
        printf("TELEFONE: %s\n", lista[i].telefone);
    }
}
