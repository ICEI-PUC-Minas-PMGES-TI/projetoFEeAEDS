#include <stdio.h>
#include "pedido.h"

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