#include <stdio.h>
#include "../includes/local.h"

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
    int id;
    printf("ID do local para atualizar: ");
    scanf("%d", &id);
    if (id < 0 || id >= numLocais) {
        printf("ID inválido!\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", locais[id].nome);
    printf("Nova coordenada X: ");
    scanf("%f", &locais[id].x);
    printf("Nova coordenada Y: ");
    scanf("%f", &locais[id].y);
    printf("Local atualizado!\n");
}

void removerLocal(Local locais[], int *numLocais) {
    int id;
    printf("ID do local para remover: ");
    scanf("%d", &id);
    if (id < 0 || id >= *numLocais) {
        printf("ID inválido!\n");
        return;
    }
    for (int i = id; i < *numLocais - 1; i++) {
        locais[i] = locais[i + 1];
    }
    (*numLocais)--;
    printf("Local removido!\n");
}