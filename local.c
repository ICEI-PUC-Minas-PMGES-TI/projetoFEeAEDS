#include <stdio.h>
#include <string.h>
#include "local.h"

void cadastrarLocal(Local locais[], int *numLocais) {
    if (*numLocais >= MAX_LOCAIS) {
        printf("Limite de locais atingido!\n");
        return;
    }
    printf("Nome do local: ");
    scanf(" %[^\n]", locais[*numLocais].nome);
    printf("Coordenada X: ");
    scanf("%f", &locais[*numLocais].x);
    printf("Coordenada Y: ");
    scanf("%f", &locais[*numLocais].y);
    (*numLocais)++;
    printf("Local cadastrado com sucesso!\n");
}

void listarLocais(Local locais[], int numLocais) {
    for (int i = 0; i < numLocais; i++) {
        printf("%d - %s (%.2f, %.2f)\n", i, locais[i].nome, locais[i].x, locais[i].y);
    }
}