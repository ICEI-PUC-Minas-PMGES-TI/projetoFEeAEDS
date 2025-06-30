#include <stdio.h>
#include "../includes/arquivo.h"

void backup(Local locais[], int numLocais, Veiculo veiculos[], int numVeiculos, Pedido pedidos[], int numPedidos) {
    FILE *f = fopen("backup.dat", "wb");
    if (!f) {
        printf("Erro ao criar backup!\n");
        return;
    }
    fwrite(&numLocais, sizeof(int), 1, f);
    fwrite(locais, sizeof(Local), numLocais, f);
    fwrite(&numVeiculos, sizeof(int), 1, f);
    fwrite(veiculos, sizeof(Veiculo), numVeiculos, f);
    fwrite(&numPedidos, sizeof(int), 1, f);
    fwrite(pedidos, sizeof(Pedido), numPedidos, f);
    fclose(f);
    printf("Backup realizado com sucesso!\n");
}

void restore(Local locais[], int *numLocais, Veiculo veiculos[], int *numVeiculos, Pedido pedidos[], int *numPedidos) {
    FILE *f = fopen("backup.dat", "rb");
    if (!f) {
        printf("Erro ao ler backup!\n");
        return;
    }
    fread(numLocais, sizeof(int), 1, f);
    fread(locais, sizeof(Local), *numLocais, f);
    fread(numVeiculos, sizeof(int), 1, f);
    fread(veiculos, sizeof(Veiculo), *numVeiculos, f);
    fread(numPedidos, sizeof(int), 1, f);
    fread(pedidos, sizeof(Pedido), *numPedidos, f);
    fclose(f);
    printf("Restore realizado com sucesso!\n");
}