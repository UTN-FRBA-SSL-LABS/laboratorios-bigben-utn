#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento() {
    printf("\ncompra con descuento\n");
    Carrito carrito;
    carrito_init(&carrito);

    Producto pan = {"Pan", 200, 3}; // 600
    Producto leche = {"Leche", 350, 2}; // 700

    carrito_agregar(&carrito, pan);
    carrito_agregar(&carrito, leche);

    ASSERT_IGUAL(1300, carrito_total(&carrito));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&carrito), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    printf("\nllenar carrito\n");
    Carrito carrito;
    carrito_init(&carrito);

    Producto leche = {"Leche", 350, 1};

    for (int i = 0; i < MAX_ITEMS; i++) {
        carrito_agregar(&carrito, leche);
    }

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&carrito));
    ASSERT_IGUAL(0, carrito_agregar(&carrito, leche));
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&carrito));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
