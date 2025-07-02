#include <stdio.h>
#include <string.h>
#include "../includes/veiculo.h"
// Cadastra um novo veículo
void cadastrarVeiculo(Veiculo veiculos[], int *numVeiculos) {
    if (*numVeiculos >= MAX_VEICULOS) {
        printf("Limite de veículos atingido!\n");
        return;
    }
    printf("Placa: ");
    scanf(" %[^\n]", veiculos[*numVeiculos].placa);
    printf("Modelo: ");
    scanf(" %[^\n]", veiculos[*numVeiculos].modelo);
    veiculos[*numVeiculos].status = 0; // disponível
    printf("ID do local atual: ");
    scanf("%d", &veiculos[*numVeiculos].idLocalAtual);
    (*numVeiculos)++;
    printf("Veículo cadastrado com sucesso!\n");
}
// Lista todos os veículos
void listarVeiculos(Veiculo veiculos[], int numVeiculos) {
    for (int i = 0; i < numVeiculos; i++) {
        printf("%d - %s | %s | Status: %s | Local: %d\n",
               i,
               veiculos[i].placa,
               veiculos[i].modelo,
               veiculos[i].status == 0 ? "Disponível" : "Ocupado",
               veiculos[i].idLocalAtual);
    }
}
// Atualiza os dados de um veículo
void atualizarVeiculo(Veiculo veiculos[], int numVeiculos) {
    int i;
    printf("Índice do veículo a atualizar: ");
    scanf("%d", &i);
    if (i < 0 || i >= numVeiculos) {
        printf("Índice inválido!\n");
        return;
    }
    printf("Nova placa: ");
    scanf(" %[^\n]", veiculos[i].placa);
    printf("Novo modelo: ");
    scanf(" %[^\n]", veiculos[i].modelo);
    printf("Novo status (0 = disponível, 1 = ocupado): ");
    scanf("%d", &veiculos[i].status);
    printf("Novo ID do local atual: ");
    scanf("%d", &veiculos[i].idLocalAtual);
    printf("Veículo atualizado com sucesso!\n");
}
// Remove um veículo da lista
void removerVeiculo(Veiculo veiculos[], int *numVeiculos) {
    int i;
    printf("Índice do veículo a remover: ");
    scanf("%d", &i);
    if (i < 0 || i >= *numVeiculos) {
        printf("Índice inválido!\n");
        return;
    }
    for (int j = i; j < *numVeiculos - 1; j++) {
        veiculos[j] = veiculos[j + 1];
    }
    (*numVeiculos)--;
    printf("Veículo removido com sucesso!\n");
}