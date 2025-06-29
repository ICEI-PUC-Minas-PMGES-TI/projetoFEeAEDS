#ifndef VEICULO_H
#define VEICULO_H
#define MAX_VEICULOS 100

typedef struct {
    char placa[10];
    char modelo[30];
    int status;
    int idLocalAtual;
    } Veiculo;
    void cadastrarVeiculo(Veiculo veiculos[], int *numVeiculos);
void listarVeiculos(Veiculo veiculos[], int numVeiculos);
void atualizarVeiculo(Veiculo veiculos[], int numVeiculos);
void removerVeiculo(Veiculo veiculos[], int *numVeiculos);
    #endif