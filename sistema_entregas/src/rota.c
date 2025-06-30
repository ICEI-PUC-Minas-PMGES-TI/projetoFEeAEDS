#include <stdio.h>
#include <math.h>
#include "../includes/rota.h"

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