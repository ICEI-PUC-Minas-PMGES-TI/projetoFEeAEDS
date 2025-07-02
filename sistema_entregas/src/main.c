#include <stdio.h>
#include "../includes/local.h"
#include "../includes/veiculo.h"
#include "../includes/pedido.h"
#include "../includes/rota.h"
#include "../includes/arquivo.h"

// Definições das quantidades máximas de elementos
#define MAX_LOCAIS 100
#define MAX_VEICULOS 100
#define MAX_PEDIDOS 100
// Declaração dos arrays de structs que armazenam os dados do sistema
Local locais[MAX_LOCAIS];
Veiculo veiculos[MAX_VEICULOS];
Pedido pedidos[MAX_PEDIDOS];
// Variáveis que armazenam a quantidade atual de cada tipo de entidade
int numLocais = 0, numVeiculos = 0, numPedidos = 0;
// Função principal do menu de opções do sistema
void menu() {
    int opcao;
    do  {     // Exibe o menu principal
        printf("\n==== Sistema de Logistica de Entrega de Mercadorias ====");
        printf("\n1. Cadastrar Local");
        printf("\n2. Listar Locais");
        printf("\n3. Atualizar Local");
        printf("\n4. Remover Local");
        printf("\n5. Cadastrar Veiculo");
        printf("\n6. Listar Veiculos");
        printf("\n7. Atualizar Veiculo");
        printf("\n8. Remover Veiculo");
        printf("\n9. Cadastrar Pedido");
        printf("\n10. Listar Pedidos");
        printf("\n11. Atualizar Pedido");
        printf("\n12. Remover Pedido");
        printf("\n13. Associar pedido a rota e veiculo");
        printf("\n14. Finalizar entrega");
        printf("\n15. Salvar backup");
        printf("\n16. Carregar backup");
        printf("\n0. Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
 // Executa a função correspondente à opção escolhida
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
            case 15:
                salvarLocais(locais, numLocais);
                salvarVeiculos(veiculos, numVeiculos);
                salvarPedidos(pedidos, numPedidos, "pedidos.dat");
            break;
            case 16:
                carregarLocais(locais, &numLocais);
                carregarVeiculos(veiculos, &numVeiculos);
                carregarPedidos(pedidos, &numPedidos, "../data/pedidos.dat");
            break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção invalida!\n"); break;
        }
    } while (opcao != 0); // Repete até o usuário escolher sair
}
// Função principal que inicia o programa
int main() {
    menu();// Chama o menu do sistema
    return 0;// Encerra o programa
}
