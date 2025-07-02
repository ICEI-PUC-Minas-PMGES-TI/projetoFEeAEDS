#include <stdio.h>
#include "../includes/local.h"
// Cadastra um novo local no vetor
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
// Lista todos os locais cadastrados
void listarLocais(Local locais[], int numLocais) {
    for (int i = 0; i < numLocais; i++) {
        printf("%d - %s (%.2f, %.2f)\n", i, locais[i].nome, locais[i].x, locais[i].y);
    }
}
// Atualiza um local com base no ID
void atualizarLocal(Local locais[], int numLocais) {
    int id;
    printf("ID do local para atualizar: ");
    scanf("%d", &id);
    if (id < 0 || id >= numLocais) {
        printf("ID invalido!\n");
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
// Remove um local com base no ID
void removerLocal(Local locais[], int *numLocais) {
    listarLocais(locais, *numLocais);  

    int id;
    printf("Digite o ID do local a remover: ");
    while (scanf("%d", &id) != 1) {
        printf("Entrada invalida. Digite um número inteiro: ");
        while (getchar() != '\n');
    }

    if (id < 0 || id >= *numLocais) {
        printf("ID invalido!\n");
        return;
    }

    for (int i = id; i < *numLocais - 1; i++) {
        locais[i] = locais[i + 1];
    }

    (*numLocais)--;
    printf("Local removido com sucesso!\n");
}