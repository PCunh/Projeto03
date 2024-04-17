#include <stdio.h>
#include "tarefas.h"

// Função para adicionar um novo contato à lista
void adicionarContato(struct Contato lista[], int *numContatos) {
    if (*numContatos < MAX_CONTATOS) {
        printf("Digite o seu nome: ");
        scanf("%s", lista[*numContatos].nome);
        printf("Digite o seu sobrenome: ");
        scanf("%s", lista[*numContatos].sobrenome);
        (*numContatos)++;
    } else {
        printf("Lista de contatos cheia!\n");
    }
}

// Função para exibir todos os contatos na lista
void ListarContatos(struct Contato lista[], int numContatos) {
    printf("Lista de Contatos:\n");
    printf("\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%s %s\n", lista[i].nome, lista[i].sobrenome);
    }
}
