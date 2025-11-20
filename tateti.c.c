#include <stdio.h>

void mostrarTablero(char t[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", t[i][0], t[i][1], t[i][2]);
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

int verificarGanador(char t[3][3], char j) {
    // Filas
    for (int i = 0; i < 3; i++)
        if (t[i][0] == j && t[i][1] == j && t[i][2] == j)
            return 1;

    // Columnas
    for (int i = 0; i < 3; i++)
        if (t[0][i] == j && t[1][i] == j && t[2][i] == j)
            return 1;

    // Diagonal principal
    if (t[0][0] == j && t[1][1] == j && t[2][2] == j)
        return 1;

    // Diagonal secundaria
    if (t[0][2] == j && t[1][1] == j && t[2][0] == j)
        return 1;

    return 0;
}

int main() {
    char t[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int fila, col;
    char jugador = 'X';
    int jugadas = 0;

    printf("===== TATETI =====\n");
    mostrarTablero(t);

    while (1) {
        printf("Turno del jugador %c\n", jugador);

        printf("Fila (0-2): ");
        scanf("%d", &fila);

        printf("Columna (0-2): ");
        scanf("%d", &col);

        // Validación
        if (fila < 0 || fila > 2 || col < 0 || col > 2) {
            printf("Posicion invalida.\n");
            continue;
        }

        if (t[fila][col] != ' ') {
            printf("Posicion ocupada.\n");
            continue;
        }

        t[fila][col] = jugador;
        jugadas++;

        mostrarTablero(t);

        if (verificarGanador(t, jugador)) {
            printf("GANO EL JUGADOR %c!\n", jugador);
            break;
        }

        if (jugadas == 9) {
            printf("EMPATE.\n");
            break;
        }

        jugador = (jugador == 'X') ? 'O' : 'X';
    }

    return 0;
}
