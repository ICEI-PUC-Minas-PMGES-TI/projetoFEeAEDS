#ifndef PEDIDO_H
#define PEDIDO_H
#define MAX_PEDIDOS 100

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
void salvarPedidos(Pedido pedidos[], int numPedidos, const char* nomeArquivo);
void carregarPedidos(Pedido pedidos[], int *numPedidos, const char* nomeArquivo);
#endif