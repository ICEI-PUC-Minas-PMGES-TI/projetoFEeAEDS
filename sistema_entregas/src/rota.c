#include <stdio.h>
#include <math.h>
#include "../includes/rota.h"
#include "../includes/pedido.h"
#include "../includes/veiculo.h"

float calcularDistancia(Local origem, Local destino) {
    float dx = origem.x - destino.x;
    float dy = origem.y - destino.y;
    return sqrt(dx * dx + dy * dy);
}

void calcularRota(Local locais[], int numLocais) {
    int idOrigem, idDestino;
    printf("ID da origem: ");
    scanf("%d", &idOrigem);
    printf("ID do destino: ");
    scanf("%d", &idDestino);

    if (idOrigem < 0 || idOrigem >= numLocais || idDestino < 0 || idDestino >= numLocais) {
        printf("IDs inválidos!\n");
        return;
    }

    float distancia = calcularDistancia(locais[idOrigem], locais[idDestino]);
    printf("Distância da rota: %.2f\n", distancia);
}

void associarPedidoRotaVeiculo(Pedido pedidos[], int numPedidos, Local locais[], int numLocais, Veiculo veiculos[], int numVeiculos) {
    if (numPedidos == 0) {
        printf("Nenhum pedido disponível!\n");
        return;
    }

    int pedidoId = numPedidos - 1; // Último pedido cadastrado
    int idOrigem = pedidos[pedidoId].idOrigem;
    int idDestino = pedidos[pedidoId].idDestino;

    int idVeiculo = buscarVeiculoMaisProximo(veiculos, numVeiculos, locais, idOrigem);

    if (idVeiculo == -1) {
        printf("Nenhum veículo disponível no momento!\n");
        return;
    }

    float distancia = calcularDistancia(locais[idOrigem], locais[idDestino]);

    printf("Pedido ID %d:\n", pedidoId);
    printf("- Veículo escolhido: %d\n", idVeiculo);
    printf("- Origem: %d\n", idOrigem);
    printf("- Destino: %d\n", idDestino);
    printf("- Distância calculada: %.2f km\n", distancia);

    // Atualiza o veículo
    veiculos[idVeiculo].idLocalAtual = idDestino;
    veiculos[idVeiculo].status = 1;  // Marcando como ocupado

    printf("Veículo %d agora está em trânsito e foi movido para o local %d.\n", idVeiculo, idDestino);
}

void finalizarEntrega(Veiculo veiculos[], int numVeiculos) {
    int idVeiculo;
    printf("Digite o ID do veículo que deseja associar ao pedido: ");
    scanf("%d", &idVeiculo);

    if (idVeiculo < 0 || idVeiculo >= numVeiculos) {
    printf("ID inválido! Fora do intervalo de veículos cadastrados.\n");
    return;
    }

    if (veiculos[idVeiculo].status != 0) {
    printf("Veículo não está disponível!\n");
    return;
    }

    veiculos[idVeiculo].status = 0;
    printf("Entrega finalizada! Veículo ID %d agora está disponível.\n", idVeiculo);
}

int buscarVeiculoMaisProximo(Veiculo veiculos[], int numVeiculos, Local locais[], int idOrigem) {
    float menorDistancia = -1;
    int indiceMaisProximo = -1;

    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].status == 0) {  // Livre
            float d = calcularDistancia(locais[veiculos[i].idLocalAtual], locais[idOrigem]);
            if (menorDistancia == -1 || d < menorDistancia) {
                menorDistancia = d;
                indiceMaisProximo = i;
            }
        }
    }

    return indiceMaisProximo;
}