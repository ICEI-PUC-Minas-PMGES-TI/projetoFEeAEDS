#ifndef ROTA_H
#define ROTA_H

#include "../includes/local.h"
#include "../includes/veiculo.h"
#include "../includes/pedido.h"

float calcularDistancia(Local origem, Local destino);
void calcularRota(Local locais[], int numLocais);
void associarPedidoRotaVeiculo(Pedido pedidos[], int numPedidos, Local locais[], int numLocais, Veiculo veiculos[], int numVeiculos);
void finalizarEntrega(Veiculo veiculos[], int numVeiculos);
int buscarVeiculoMaisProximo(Veiculo veiculos[], int numVeiculos, Local locais[], int idOrigem);

#endif