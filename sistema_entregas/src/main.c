#include <stdio.h>
#include "../includes/local.h"
#include "../includes/veiculo.h"
#include "../includes/pedido.h"


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
        printf("\n==== Sistema de Logistica de Entrega de Mercadorias ====");
        printf("\n1. Cadastrar Local");
        printf("\n2. Listar Locais");
        printf("\n3. Atualizar Local");
        printf("\n4. Remover Local");
        printf("\n5. Cadastrar Veículo");
        printf("\n6. Listar Veículos");
        printf("\n7. Atualizar Veículo");
        printf("\n8. Remover Veículo");
        printf("\n9. Cadastrar Pedido");
        printf("\n10. Listar Pedidos");
        printf("\n11. Atualizar Pedido");
        printf("\n12. Remover Pedido");
        printf("\\n13. Associar pedido a rota e veículo");
        printf("\\n14. Finalizar entrega");
        printf("\n0. Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrarLocal(locais, &numLocais); break;
            case 2: listarLocais(locais, numLocais); break;
            case 3: atualizarLocal(locais, numLocais); break;
            case 4: removerLocal(locais, &numLocais); break;
            case 5: cadastrarVeiculo(veiculos, &numVeiculos); break;
            case 6: listarVeiculos(veiculos, numVeiculos); break;
            case 7: atualizarVeiculo(veiculos, numVeiculos); break;
            case 8: removerVeiculo(veiculos, &numVeiculos); break;
            case 9: cadastrarPedido(pedidos, &numPedidos); break;
            case 10: listarPedidos(pedidos, numPedidos); break;
            case 11: atualizarPedido(pedidos, numPedidos); break;
            case 12: removerPedido(pedidos, &numPedidos); break;
            case 13: associarPedidoRotaVeiculo(pedidos, numPedidos, locais, numLocais, veiculos, numVeiculos); break;
            case 14: finalizarEntrega(veiculos, numVeiculos); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
