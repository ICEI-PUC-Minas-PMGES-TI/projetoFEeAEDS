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
void atualizarLocal(Local locais[], int numLocais) {
    int i;
    printf("Índice do local a atualizar: ");
    scanf("%d", &i);
    if (i < 0 || i >= numLocais) {
        printf("Índice inválido!\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", locais[i].nome);
    printf("Nova coordenada X: ");
    scanf("%f", &locais[i].x);
    printf("Nova coordenada Y: ");
    scanf("%f", &locais[i].y);
    printf("Local atualizado com sucesso!\n");
}

void removerLocal(Local locais[], int *numLocais) {
    int i;
    printf("Índice do local a remover: ");
    scanf("%d", &i);
    if (i < 0 || i >= *numLocais) {
        printf("Índice inválido!\n");
        return;
    }
    for (int j = i; j < *numLocais - 1; j++) {
        locais[j] = locais[j + 1];
    }
    (*numLocais)--;
    printf("Local removido com sucesso!\n");
}