#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct {
    int id;
    int idOrigem;
    int idDestino;
    float peso;
} Pedido;
void cadastrarPedido(Pedido pedidos[], int *numPedidos);
void listarPedidos(Pedido pedidos[], int numPedidos);
void atualizarPedido(Pedido pedidos[], int numPedidos);
void removerPedido(Pedido pedidos[], int *numPedidos);
#endif