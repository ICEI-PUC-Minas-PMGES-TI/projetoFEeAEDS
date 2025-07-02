#include <stdio.h>
#include <math.h>
#include "../includes/rota.h"
#include "../includes/pedido.h"
#include "../includes/veiculo.h"
#include "../includes/local.h"
// Função que calcula a distância euclidiana entre dois locais
float calcularDistancia(Local origem, Local destino) {
    float dx = origem.x - destino.x;
    float dy = origem.y - destino.y;
    return sqrt(dx * dx + dy * dy);
}
// Busca o veículo mais próximo de um local de origem
int buscarVeiculoMaisProximo(Veiculo veiculos[], int numVeiculos, Local locais[], int idOrigem) {
    float menorDistancia = -1;
    int idVeiculoMaisProximo = -1;

    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].status == 0) {  // disponível
            float distancia = calcularDistancia(locais[veiculos[i].idLocalAtual], locais[idOrigem]);
            if (menorDistancia == -1 || distancia < menorDistancia) {
                menorDistancia = distancia;
                idVeiculoMaisProximo = i;
            }
        }
    }

    return idVeiculoMaisProximo;
}
// Associa o último pedido feito a um veículo e imprime as informações da rota
void associarPedidoRotaVeiculo(Pedido pedidos[], int numPedidos, Local locais[], int numLocais, Veiculo veiculos[], int numVeiculos) {
    if (numPedidos == 0) {
        printf("Nenhum pedido disponível!\n");
        return;
    }

    int pedidoId = numPedidos - 1; // Último pedido
    int idOrigem = pedidos[pedidoId].idOrigem;
    int idDestino = pedidos[pedidoId].idDestino;
    // Verifica se os IDs de origem e destino são válidos
    if (idOrigem < 0 || idOrigem >= numLocais || idDestino < 0 || idDestino >= numLocais) {
        printf("Origem ou destino do pedido são inválidos!\n");
        return;
    }
    // Procura um veículo disponível mais próximo da origem
    int idVeiculo = buscarVeiculoMaisProximo(veiculos, numVeiculos, locais, idOrigem);

    if (idVeiculo == -1) {
        printf("Nenhum veículo disponível no momento!\n");
        return;
    }
    // Calcula a distância entre origem e destino
    float distancia = calcularDistancia(locais[idOrigem], locais[idDestino]);

    printf("Pedido ID %d associado ao Veículo ID %d.\n", pedidoId, idVeiculo);
    printf("Origem: %d, Destino: %d, Distância: %.2f km\n", idOrigem, idDestino, distancia);
   // Atualiza o local atual e status do veículo
    veiculos[idVeiculo].idLocalAtual = idDestino;
    veiculos[idVeiculo].status = 1;

    printf("Veículo %d agora está ocupado e no local %d.\n", idVeiculo, idDestino);
}
// Finaliza a entrega de um veículo e o torna disponível novamente
void finalizarEntrega(Veiculo veiculos[], int numVeiculos) {
    int idVeiculo;
    printf("ID do veículo que finalizou a entrega: ");
    scanf("%d", &idVeiculo);
  // Verifica se o ID é válido e se o veículo está ocupado
    if (idVeiculo < 0 || idVeiculo >= numVeiculos || veiculos[idVeiculo].status != 1) {
        printf("ID inválido ou veículo não está em entrega!\n");
        return;
    }
  // Marca o veículo como disponível
    veiculos[idVeiculo].status = 0;
    printf("Entrega finalizada! Veículo %d agora está disponível.\n", idVeiculo);
}
