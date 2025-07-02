#include "../includes/munit.h"
#include "../includes/rota.h"
static MunitResult test_pedido_valido(const MunitParameter params[], void* data) {
    Local locais[2] = {{0, 0}, {3, 4}};
    Pedido pedidos[1] = {{.idOrigem = 0, .idDestino = 1}};
    Veiculo veiculos[1] = {{.idLocalAtual = 0, .status = 0}};

    associarPedidoRotaVeiculo(pedidos, 1, locais, 2, veiculos, 1);

    munit_assert_int(veiculos[0].idLocalAtual, ==, 1);
    munit_assert_int(veiculos[0].status, ==, 1);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    { "/teste/pedido_valido", test_pedido_valido, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    // Adicione mais testes aqui
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/rota_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}