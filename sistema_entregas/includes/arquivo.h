#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "../includes/local.h"
#include "../includes/veiculo.h"
#include "../includes/pedido.h"

void salvarLocais(Local locais[], int numLocais);
void salvarVeiculos(Veiculo veiculos[], int numVeiculos);
void salvarPedidos(Pedido pedidos[], int numPedidos, const char* nomeArquivo);

void carregarLocais(Local locais[], int *numLocais);
void carregarVeiculos(Veiculo veiculos[], int *numVeiculos);
void carregarPedidos(Pedido pedidos[], int *numPedidos, const char* nomeArquivo);

#endif