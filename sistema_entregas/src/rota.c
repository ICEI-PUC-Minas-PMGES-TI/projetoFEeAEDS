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

    int pedidoId = numPedidos - 1; // último pedido cadastrado
    printf("Associando pedido ID %d...\n", pedidos[pedidoId].id);

    printf("Veículos disponíveis:\n");
    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].status == 0) {
            printf("ID do Veículo: %d | Local atual: %d | Status: Livre\n", i, veiculos[i].idLocalAtual);
        }
    }

    // Mostrar veículos disponíveis
    int idVeiculo;
    printf("Digite o ID do veículo que deseja associar ao pedido: ");
    scanf("%d", &idVeiculo);

    if (idVeiculo < 0 || idVeiculo >= numVeiculos) {
    printf("ID inválido!\n");
    return;
    }

    if (veiculos[idVeiculo].status != 0) {
    printf("Veículo não disponível!\n");
    return;
    }


    // Calcular distância
    float distancia = calcularDistancia(locais[pedidos[pedidoId].idOrigem], locais[pedidos[pedidoId].idDestino]);
    printf("Distância calculada: %.2f km\n", distancia);

    // Atualizar veículo
    veiculos[idVeiculo].status = 1;
    veiculos[idVeiculo].idLocalAtual = pedidos[pedidoId].idDestino;

     printf("Pedido associado ao veículo ID %d. Veículo agora está ocupado.\n", idVeiculo);
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