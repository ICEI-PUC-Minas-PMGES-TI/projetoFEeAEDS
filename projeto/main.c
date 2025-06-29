#include <stdio.h>
#include "local.h"
#include "veiculo.h"
#include "pedido.h"

#define MAX_LOCAIS 100
#define MAX_VEICULOS 100
#define MAX_PEDIDOS 100

Local locais[MAX_LOCAIS];
Veiculo veiculos[MAX_VEICULOS];
Pedido pedidos[MAX_PEDIDOS];

int numLocais = 0, numVeiculos = 0, numPedidos = 0;
void menu() {
    int opcao;
    do {
        printf("\\n==== Sistema de Logística de Entrega de Mercadorias (SLEM) ====");
        printf("\\n1. Cadastrar Local");
        printf("\\n2. Listar Locais");