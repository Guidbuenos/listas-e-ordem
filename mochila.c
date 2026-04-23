#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Funções do sistema
void cadastrarItem(Item inventario[], int *contador);
void removerItem(Item inventario[], int *contador);
void listarItens(Item inventario[], int contador);
void buscarItem(Item inventario[], int contador);

int main() {
    Item inventario[MAX_ITENS];
    int contador = 0;
    int opcao;

    do {
        printf("\nSistema de Inventário\n");
        printf("1. Cadastrar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("4. Buscar Item\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (contador < MAX_ITENS) {
                    cadastrarItem(inventario, &contador);
                } else {
                    printf("Mochila cheia! Não é possível cadastrar mais itens.\n");
                }
                break;
            case 2:
                removerItem(inventario, &contador);
                break;
            case 3:
                listarItens(inventario, contador);
                break;
            case 4:
                buscarItem(inventario, contador);
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 5);

    return 0;
}

void cadastrarItem(Item inventario[], int *contador) {
    Item novoItem;
    printf("Informe o nome do item: ");
    scanf("%s", novoItem.nome);
    printf("Informe o tipo do item (arma, municao, cura): ");
    scanf("%s", novoItem.tipo);
    printf("Informe a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    
    inventario[*contador] = novoItem;
    (*contador)++;
    listarItens(inventario, *contador);
}

void removerItem(Item inventario[], int *contador) {
    char nome[30];
    printf("Informe o nome do item a ser removido: ");
    scanf("%s", nome);

    int i, encontrado = 0;
    for (i = 0; i < *contador; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            encontrado = 1;
            // Move os itens seguintes para a esquerda
            for (int j = i; j < *contador - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            (*contador)--;
            break;
        }
    }

    if (encontrado) {
        printf("Item '%s' removido com sucesso!\n", nome);
    } else {
        printf("Item '%s' não encontrado!\n", nome);
    }
    listarItens(inventario, *contador);
}

void listarItens(Item inventario[], int contador) {
    if (contador == 0) {
        printf("Nenhum item registrado na mochila.\n");
        return;
    }
    printf("\nItens na mochila:\n");
    for (int i = 0; i < contador; i++) {
        printf("Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
    }
}

void buscarItem(Item inventario[], int contador) {
    char nome[30];
    printf("Informe o nome do item a ser buscado: ");
    scanf("%s", nome);

    for (int i = 0; i < contador; i++) {
        if (strcmp(inventario[i].nome, nome) == 0) {
            printf("Item encontrado: Nome: %s, Tipo: %s, Quantidade: %d\n", inventario[i].nome, inventario[i].tipo, inventario[i].quantidade);
            return;
        }
    }
    printf("Item '%s' não encontrado!\n", nome);
}