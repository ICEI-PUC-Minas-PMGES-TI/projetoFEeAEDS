#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_PEDIDOS 100

typedef struct {
    int id;
    int idOrigem;
    int idDestino;
    float peso;
} Pedido;

// Cadastra um novo pedido
void cadastrarPedido();

// Lista todos os pedidos
void listarPedidos();

// Atualiza um pedido
void atualizarPedido();

// Remove um pedido
void removerPedido();

#endif
