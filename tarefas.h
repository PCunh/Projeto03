#define TAREFAS_H

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

typedef enum { ABRIR, FECHAR, ESCREVER, LER } ErrorCode;

// Protótipos de funções
void adicionarContato(struct Contato lista[], int *numContatos);
void listarContatos(struct Contato lista[], int numContatos);
void deletarContato(struct Contato lista[], int *numContatos);
ErrorCode salvarContatos(struct Contato lista[], int *numContatos);
ErrorCode carregarContatos(struct Contato lista[], int *numContatos);

void extermina_linha(char *str);
void clearBuffer();
