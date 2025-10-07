#include <stdio.h>
#include <string.h>

int main() {
    char id[5][10];
    char nombre[5][20];
    float precio[5];
    int stock[5];
    float ganancia = 0;
    int cont = 0;
    int opc, opc2, pv, cantidad;
    float valor;

    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Ingresar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Informacion de productos\n");
        printf("5. Ver ganancias\n");
        printf(">> ");
        if (scanf("%d", &opc) != 1) {
            printf("Entrada invalida.\n");
            while (getchar() != '\n'); // limpiar buffer
            continue;
        }

        switch (opc) {
        case 1:
            if (cont >= 5) {
                printf("No se pueden ingresar mas productos.\n");
                break;
            }
            printf("Ingrese ID del producto %d: ", cont);
            scanf("%s", id[cont]);
            printf("Ingrese nombre del producto %d: ", cont);
            while (getchar() != '\n');
            fgets(nombre[cont], 20, stdin);
            int len = strlen(nombre[cont]);
            if (len > 0 && nombre[cont][len - 1] == '\n')
                nombre[cont][len - 1] = '\0';
            printf("Ingrese precio: ");
            scanf("%f", &precio[cont]);
            printf("Ingrese stock: ");
            scanf("%d", &stock[cont]);
            cont++;
            break;

        case 2:
            if (cont == 0) {
                printf("No hay productos para vender.\n");
                break;
            }
            printf("#\tID\tNombre\t\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
                printf("%d\t%s\t%s\t\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            printf("Seleccione producto a vender: ");
            scanf("%d", &pv);
            if (pv < 0 || pv >= cont) {
                printf("Indice invalido.\n");
                break;
            }
            if (stock[pv] == 0) {
                printf("No hay stock para vender.\n");
                break;
            }
            do {
                printf("Cantidad a vender: ");
                scanf("%d", &cantidad);
                if (cantidad > stock[pv])
                    printf("No hay suficiente stock.\n");
            } while (cantidad > stock[pv] || cantidad <= 0);
            valor = cantidad * precio[pv];
            stock[pv] -= cantidad;
            ganancia += valor;
            printf("Venta realizada: $%.2f\n", valor);
            break;

        case 3:
            if (cont == 0) {
                printf("No hay productos para reabastecer.\n");
                break;
            }
            printf("#\tID\tNombre\t\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
                printf("%d\t%s\t%s\t\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            printf("Seleccione producto a reabastecer: ");
            scanf("%d", &pv);
            if (pv < 0 || pv >= cont) {
                printf("Indice invalido.\n");
                break;
            }
            printf("Cantidad a agregar: ");
            scanf("%d", &cantidad);
            if (cantidad > 0) {
                stock[pv] += cantidad;
                printf("Nuevo stock: %d\n", stock[pv]);
            } else {
                printf("Cantidad invalida.\n");
            }
            break;

        case 4:
            if (cont == 0) {
                printf("No hay productos registrados.\n");
                break;
            }
            printf("#\tID\tNombre\t\tPrecio\tStock\n");
            for (int i = 0; i < cont; i++)
                printf("%d\t%s\t%s\t\t%.2f\t%d\n", i, id[i], nombre[i], precio[i], stock[i]);
            break;

        case 5:
            printf("Ganancias totales: $%.2f\n", ganancia);
            break;

        default:
            printf("Opcion no valida.\n");
        }

        printf("\n¿Desea realizar otra operación? 1.Sí / 2.No: ");
        scanf("%d", &opc2);
    } while (opc2 != 2);

    return 0;
}
