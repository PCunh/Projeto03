
#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_SOBRENOME 50


#define TAREFAS_H

#define MAX_CONTATOS 255
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_EMAIL 50
#define TAM_TELEFONE 20


struct Contato {
    char nome[TAM_NOME];
    char sobrenome[TAM_SOBRENOME];

};

// Protótipos de funções
void adicionarContato(struct Contato lista[], int *numContatos);
void ListarContatos(struct Contato lista[], int numContatos);

#endif 

