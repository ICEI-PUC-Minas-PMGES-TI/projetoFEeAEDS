#include <stdio.h>
#include "../includes/arquivo.h"

void salvarLocais(Local locais[], int numLocais) {
    FILE *f = fopen("locais.dat", "wb");
    if (!f) {
        printf("Erro ao salvar locais!\n");
        return;
    }
    fwrite(&numLocais, sizeof(int), 1, f);
    fwrite(locais, sizeof(Local), numLocais, f);
    fclose(f);
    printf("Locais salvos com sucesso!\n");
}

void salvarVeiculos(Veiculo veiculos[], int numVeiculos) {
    FILE *f = fopen("veiculos.dat", "wb");
    if (!f) {
        printf("Erro ao salvar veículos!\n");
        return;
    }
    fwrite(&numVeiculos, sizeof(int), 1, f);
    fwrite(veiculos, sizeof(Veiculo), numVeiculos, f);
    fclose(f);
    printf("Veículos salvos com sucesso!\n");
}

void salvarPedidos(Pedido pedidos[], int numPedidos) {
    FILE *f = fopen("pedidos.dat", "wb");
    if (!f) {
        printf("Erro ao salvar pedidos!\n");
        return;
    }
    fwrite(&numPedidos, sizeof(int), 1, f);
    fwrite(pedidos, sizeof(Pedido), numPedidos, f);
    fclose(f);
    printf("Pedidos salvos com sucesso!\n");
}

void carregarLocais(Local locais[], int *numLocais) {
    FILE *f = fopen("locais.dat", "rb");
    if (!f) {
        printf("Nenhum backup de locais encontrado.\n");
        *numLocais = 0;
        return;
    }
    fread(numLocais, sizeof(int), 1, f);
    fread(locais, sizeof(Local), *numLocais, f);
    fclose(f);
    printf("Locais carregados com sucesso!\n");
}

void carregarVeiculos(Veiculo veiculos[], int *numVeiculos) {
    FILE *f = fopen("veiculos.dat", "rb");
    if (!f) {
        printf("Nenhum backup de veículos encontrado.\n");
        *numVeiculos = 0;
        return;
    }
    fread(numVeiculos, sizeof(int), 1, f);
    fread(veiculos, sizeof(Veiculo), *numVeiculos, f);
    fclose(f);
    printf("Veículos carregados com sucesso!\n");
}

void carregarPedidos(Pedido pedidos[], int *numPedidos) {
    FILE *f = fopen("pedidos.dat", "rb");
    if (!f) {
        printf("Nenhum backup de pedidos encontrado.\n");
        *numPedidos = 0;
        return;
    }
    fread(numPedidos, sizeof(int), 1, f);
    fread(pedidos, sizeof(Pedido), *numPedidos, f);
    fclose(f);
    printf("Pedidos carregados com sucesso!\n");
}
