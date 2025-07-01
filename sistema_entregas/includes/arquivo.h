#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "../includes/local.h"
#include "../includes/veiculo.h"
#include "../includes/pedido.h"

void backup(Local locais[], int numLocais, Veiculo veiculos[], int numVeiculos, Pedido pedidos[], int numPedidos);
void restore(Local locais[], int *numLocais, Veiculo veiculos[], int *numVeiculos, Pedido pedidos[], int *numPedidos);

#endif