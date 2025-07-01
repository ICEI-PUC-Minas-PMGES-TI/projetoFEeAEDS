#include <stdio.h>
#include "../includes/pedido.h"
#include <stdlib.h>

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
    while (scanf("%f", &pedidos[*numPedidos].peso) != 1) {
        printf("Entrada invalida. Digite o peso (ex: 12.5): ");
        while (getchar() != '\n'); // Limpa o buffer
    }

    printf("Pedido cadastrado com sucesso!\n");
    (*numPedidos)++;
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
    while (scanf("%f", &pedidos[i].peso) != 1) {
        printf("Entrada invalida. Digite o peso (ex: 12.5): ");
        while (getchar() != '\n');
    }

    printf("Pedido atualizado com sucesso!\n");
}

void removerPedido(Pedido pedidos[], int *numPedidos) {
    int i;
    printf("ID do pedido a remover: ");
    scanf("%d", &i);

    if (i < 0 || i >= *numPedidos) {
        printf("ID invalido!\n");
        return;
    }

    for (int j = i; j < *numPedidos - 1; j++) {
        pedidos[j] = pedidos[j + 1];
    }

    (*numPedidos)--;
    printf("Pedido removido com sucesso!\n");
}

void salvarPedidos(Pedido pedidos[], int numPedidos, const char* nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "wb");
    if (f == NULL) {
        perror("Erro ao abrir arquivo para salvar pedidos");
        return;
    }
    fwrite(&numPedidos, sizeof(int), 1, f);
    fwrite(pedidos, sizeof(Pedido), numPedidos, f);
    fclose(f);
    printf("Pedidos salvos com sucesso!\n");
}

void carregarPedidos(Pedido pedidos[], int *numPedidos, const char* nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "rb");
    if (f == NULL) {
        perror("Arquivo de pedidos não encontrado");
        return;
    }
    fread(numPedidos, sizeof(int), 1, f);
    fread(pedidos, sizeof(Pedido), *numPedidos, f);
    fclose(f);
    printf("Pedidos carregados com sucesso!\n");
}