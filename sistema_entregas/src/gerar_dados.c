#include <stdio.h>
#include "local.h"
#include "veiculo.h"
#include "pedido.h"

void gerarLocais() {
    FILE *f = fopen("data/locais.dat", "wb");
    Local locais[3] = {
        { {'C','e','n','t','r','o','\0'}, 10.0, 20.0 },
        { {'B','a','i','r','r','o',' ','A','\0'}, 15.0, 25.0 },
        { {'B','a','i','r','r','o',' ','B','\0'}, 30.0, 40.0 }
    };

    int n = 3;
    fwrite(&n, sizeof(int), 1, f);
    fwrite(locais, sizeof(Local), n, f);
    fclose(f);
    printf("locais.dat gerado com sucesso.\n");
}
void gerarVeiculos() {
    FILE *f = fopen("data/veiculos.dat", "wb");
    Veiculo veiculos[2] = {
        {
            {'A','B','C','1','2','3','4','\0'},
            {'C','a','m','i','n','h','a','o','\0'},
            1,
            1
        },
        {
            {'X','Y','Z','5','6','7','8','\0'},
            {'V','a','n','\0'},
            1,
            2
        }
    };

    int n = 2;
    fwrite(&n, sizeof(int), 1, f);
    fwrite(veiculos, sizeof(Veiculo), n, f);
    fclose(f);
    printf("veiculos.dat gerado com sucesso.\n");
}
void gerarPedidos() {
    FILE *f = fopen("data/pedidos.dat", "wb");
    Pedido pedidos[5] = {
        {1, 1, 1},
        {2, 1, 0},
        {3, 2, 0},
        {4, 2, 1},
        {5, 3, 1}
    };

    int n = 5;
    fwrite(&n, sizeof(int), 1, f);
    fwrite(pedidos, sizeof(Pedido), n, f);
    fclose(f);
    printf("pedidos.dat gerado com sucesso.\n");
}

int main() {
    gerarLocais();
    gerarVeiculos();
    gerarPedidos();
    return 0;
}
