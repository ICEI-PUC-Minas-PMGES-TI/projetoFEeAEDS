#include <stdio.h>
#include "../includes/pedido.h"

void cadastrarPedido(Pedido pedidos[], int *numPedidos) {
    if (*numPedidos >= MAX_PEDIDOS) {
        printf("Limite de pedidos atingido!\n");
        return;
    }
    pedidos[*numPedidos].id = *numPedidos;
    printf("ID origem: ");
    scanf("%d", &pedidos[*numPedidos].idOrigem);
    printf("ID destino: ");
    scanf("%d", &pedidos[*numPedidos].idDestino);
    printf("Peso: ");
    scanf("%f", &pedidos[*numPedidos].peso);
    (*numPedidos)++;
    printf("Pedido cadastrado com sucesso!\n");
}

void listarPedidos(Pedido pedidos[], int numPedidos) {
    for (int i = 0; i < numPedidos; i++) {
        printf("%d - Origem: %d | Destino: %d | Peso: %.2f kg\n",
               pedidos[i].id,
               pedidos[i].idOrigem,
               pedidos[i].idDestino,
               pedidos[i].peso);
    }
}

void atualizarPedido(Pedido pedidos[], int numPedidos) {
    int i;
    printf("ID do pedido a atualizar: ");
    scanf("%d", &i);
    if (i < 0 || i >= numPedidos) {
        printf("ID inválido!\n");
        return;
    }
    printf("Novo ID origem: ");
    scanf("%d", &pedidos[i].idOrigem);
    printf("Novo ID destino: ");
    scanf("%d", &pedidos[i].idDestino);
    printf("Novo peso: ");
    scanf("%f", &pedidos[i].peso);
    printf("Pedido atualizado com sucesso!\n");
}

void removerPedido(Pedido pedidos[], int *numPedidos) {
    int i;
    printf("ID do pedido a remover: ");
    scanf("%d", &i);
    if (i < 0 || i >= *numPedidos) {
        printf("ID inválido!\n");
        return;
    }
    for (int j = i; j < *numPedidos - 1; j++) {
        pedidos[j] = pedidos[j + 1];
    }
    (*numPedidos)--;
    printf("Pedido removido com sucesso!\n");
}
