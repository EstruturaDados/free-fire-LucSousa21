#include <stdio.h>
#include <string.h>

#define MAX 30
#define TAM 10

typedef struct {
    char nome[MAX];
    char tipo[MAX];
    int quantidade;
} Item;


//Adcionar itens na mochila
void adicionarItem(Item mochila[], int *contador) {
    if (*contador < TAM) { //Usando um pouco de ponteiros
        printf("Nome: ");
        getchar(); 
        fgets(mochila[*contador].nome, MAX, stdin);
        mochila[*contador].nome[strcspn(mochila[*contador].nome, "\n")] = '\0';

        printf("Tipo: ");
        fgets(mochila[*contador].tipo, MAX, stdin);
        mochila[*contador].tipo[strcspn(mochila[*contador].tipo, "\n")] = '\0';

        printf("Quantidade: ");
        scanf("%d", &mochila[*contador].quantidade);

        (*contador)++;
        printf("Item adicionado com sucesso!\n");
    } else {
        printf("Mochila cheia!\n");
    }
}

//Remover Itens
void removerItem(Item mochila[], int *contador) {
    if (*contador == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    char nomeRemover[MAX];
    printf("Digite o nome do item a remover: ");
    getchar();
    fgets(nomeRemover, MAX, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int i, encontrado = 0;
    for (i = 0; i < *contador; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*contador)--;
            encontrado = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}

// Listar Itens
void listarItens(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Mochila vazia.\n");
    } else {
        printf("\n=== Itens na mochila ===\n");
        printf("%-20s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
        printf("------------------------------------------------------\n");
        for (int i = 0; i < contador; i++) {
            printf("%-20s %-20s %-10d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        }
    }
}


int main() {
    Item mochila[TAM];
    int contador = 0;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarItem(mochila, &contador);
                break;
            case 2:
                removerItem(mochila, &contador);
                break;
            case 3:
                listarItens(mochila, contador);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
