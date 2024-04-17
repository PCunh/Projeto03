#include <stdio.h>
#include "tarefas.h"

int main() {
    struct Contato listaContatos[MAX_CONTATOS];
    int numContatos = 0;
    char opcao;

    do {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarContato(listaContatos, &numContatos);
                break;
            case '2':
                ListarContatos(listaContatos, numContatos);
                break;
            case '3':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '3');

    return 0;
}
