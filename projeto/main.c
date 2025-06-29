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
        printf("\\n3. Atualizar Local");
        printf("\\n4. Remover Local");
        printf("\\n5. Cadastrar Veículo");
        printf("\\n6. Listar Veículos");
        printf("\\n7. Atualizar Veículo");
        printf("\\n8. Remover Veículo");
        printf("\\n9. Cadastrar Pedido");
        printf("\\n10. Listar Pedidos");
        printf("\\n11. Atualizar Pedido");
        printf("\\n12. Remover Pedido");
        printf("\\n0. Sair");
        printf("\\nEscolha: ");
        scanf("%d", &opcao);
        