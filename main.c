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
                printf("Contatos salvos com sucesso!\n");
                break;
            case '5':
                carregarContatos(listaContatos, &numContatos);
                printf("Contatos carregados com sucesso!\n");
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