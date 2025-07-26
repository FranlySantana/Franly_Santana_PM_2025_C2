#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VACIO ' '
#define BLANCO 1
#define NEGRO 0

#define COLOR_RESET "\033[0m"

#define COLOR_PIEZA_BLANCA "\033[37m"
#define COLOR_PIEZA_NEGRA "\033[30m"

#define COLOR_CASILLA_CLARA "\033[46m"
#define COLOR_CASILLA_OSCURA "\033[44m"

typedef struct {
    char tipo;
    int color;
    int ha_movido;
    int en_passant;
} Pieza;

Pieza tablero[8][8];
int turno = BLANCO;

void inicializar_tablero();
void mostrar_tablero();
void pedir_movimiento(int*, int*, int*, int*);
int validar_movimiento(int, int, int, int);
void hacer_movimiento(int, int, int, int);
int es_jaque(int);
int rey_existe(int);
void promocion_peon(int, int);
int hay_movimientos_legales(int);
void limpiar_en_passant(int);
void guardar_partida(const char*);
void cargar_partida(const char*);

int main() {
    int opcion;
    char archivo[64];

    printf("1. Nueva partida\n2. Cargar partida\n> ");
    scanf("%d", &opcion);
    while (getchar() != '\n');

    if (opcion == 2) {
        printf("Nombre del archivo a cargar: ");
        fgets(archivo, sizeof(archivo), stdin);
        archivo[strcspn(archivo, "\n")] = 0;
        cargar_partida(archivo);
    } else {
        inicializar_tablero();
    }

    while (1) {
        mostrar_tablero();

        if (es_jaque(turno)) {
            if (!hay_movimientos_legales(turno)) {
                printf("\n[Jaque mate] Ganan las %s.\n", turno == BLANCO ? "negras" : "blancas");
                break;
            } else {
                printf("[!] Estás en jaque.\n");
            }
        } else if (!hay_movimientos_legales(turno)) {
            printf("\n[Empate] El jugador %s no tiene movimientos legales (ahogado).\n", turno == BLANCO ? "blanco" : "negro");
            break;
        }

        printf("Turno de %s.\n", turno == BLANCO ? "Blancas" : "Negras");

        char comando[64];
        printf("Escribe 'guardar nombre.txt' o presiona Enter para mover: ");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = 0;

        if (strncmp(comando, "guardar", 7) == 0) {
            char nombre_archivo[64];
            if (sscanf(comando, "guardar %63s", nombre_archivo) == 1) {
                guardar_partida(nombre_archivo);
            } else {
                printf("Uso: guardar <nombre_archivo.txt>\n");
            }
            continue;
        }

        int fx, fy, tx, ty;
        pedir_movimiento(&fx, &fy, &tx, &ty);

        if (fx < 0 || fx > 7 || fy < 0 || fy > 7 || tx < 0 || tx > 7 || ty < 0 || ty > 7 ||
            !validar_movimiento(fx, fy, tx, ty)) {
            printf("Movimiento inválido o coordenadas fuera de rango.\n");
            continue;
        }

        Pieza temp_tablero_fx_fy = tablero[fx][fy];
        Pieza temp_tablero_tx_ty = tablero[tx][ty];
        int temp_en_passant_fx_fy = tablero[fx][fy].en_passant;
        int temp_ha_movido_fx_fy = tablero[fx][fy].ha_movido;

        hacer_movimiento(fx, fy, tx, ty);

        if (es_jaque(turno)) {
            printf("Movimiento inválido: tu rey estaría en jaque.\n");
            tablero[fx][fy] = temp_tablero_fx_fy;
            tablero[tx][ty] = temp_tablero_tx_ty;
            tablero[fx][fy].en_passant = temp_en_passant_fx_fy;
            tablero[fx][fy].ha_movido = temp_ha_movido_fx_fy;

            continue;
        }

        limpiar_en_passant(!turno);

        turno = !turno;
    }

    return 0;
}

void inicializar_tablero() {
    char piezas_fila_trasera[] = {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'};
    for (int j = 0; j < 8; j++) {
        tablero[0][j] = (Pieza){piezas_fila_trasera[j], NEGRO, 0, 0};
        tablero[1][j] = (Pieza){'P', NEGRO, 0, 0};
        tablero[6][j] = (Pieza){'P', BLANCO, 0, 0};
        tablero[7][j] = (Pieza){piezas_fila_trasera[j], BLANCO, 0, 0};
    }
    for (int i = 2; i <= 5; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = (Pieza){VACIO, -1, 0, 0};
        }
    }
}

void mostrar_tablero() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("   a b c d e f g h\n");
    printf("  -----------------\n");

    for (int i = 0; i < 8; i++) {
        printf("%d |", 8 - i);
        for (int j = 0; j < 8; j++) {
            Pieza p = tablero[i][j];

            if ((i + j) % 2 == 0) {
                printf(COLOR_CASILLA_CLARA);
            } else {
                printf(COLOR_CASILLA_OSCURA);
            }

            if (p.color == BLANCO) {
                printf(COLOR_PIEZA_BLANCA);
            } else if (p.color == NEGRO) {
                printf(COLOR_PIEZA_NEGRA);
            }

            if (p.tipo == VACIO) {
                printf("  ");
            } else {
                char letra_pieza = (p.color == BLANCO) ? p.tipo : tolower(p.tipo);
                printf("%c ", letra_pieza);
            }
            printf(COLOR_RESET);
        }
        printf("| %d\n", 8 - i);
    }
    printf("  -----------------\n");
    printf("   a b c d e f g h\n");
}

void pedir_movimiento(int* fx, int* fy, int* tx, int* ty) {
    char entrada[16];
    printf("Ingresa movimiento (ej: e2 e4): ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    if (strlen(entrada) < 5 || entrada[2] != ' ') {
        *fx = *fy = *tx = *ty = -1;
        return;
    }

    *fy = entrada[0] - 'a';
    *fx = 8 - (entrada[1] - '0');
    *ty = entrada[3] - 'a';
    *tx = 8 - (entrada[4] - '0');
}

int validar_movimiento(int fx, int fy, int tx, int ty) {
    if (fx < 0 || fx > 7 || fy < 0 || fy > 7 ||
        tx < 0 || tx > 7 || ty < 0 || ty > 7) {
        return 0;
    }

    Pieza origen = tablero[fx][fy];
    Pieza destino = tablero[tx][ty];

    if (origen.tipo == VACIO || origen.color != turno) {
        return 0;
    }

    if (destino.tipo != VACIO && destino.color == origen.color) {
        return 0;
    }

    int dx = tx - fx;
    int dy = ty - fy;

    switch (origen.tipo) {
        case 'P': {
            int dir = (origen.color == BLANCO) ? -1 : 1;
            int fila_inicial = (origen.color == BLANCO) ? 6 : 1;

            if (dy == 0 && dx == dir && destino.tipo == VACIO) {
                return 1;
            }
            if (dy == 0 && dx == 2 * dir && fx == fila_inicial &&
                tablero[fx + dir][fy].tipo == VACIO && destino.tipo == VACIO) {
                return 1;
            }
            if (abs(dy) == 1 && dx == dir && destino.tipo != VACIO && destino.color != origen.color) {
                return 1;
            }
            Pieza enemigo_en_passant = tablero[fx][ty];
            if (abs(dy) == 1 && dx == dir && enemigo_en_passant.tipo == 'P' &&
                enemigo_en_passant.color != origen.color && enemigo_en_passant.en_passant) {
                return 1;
            }
            return 0;
        }
        case 'T': {
            if (fx != tx && fy != ty) return 0;

            int paso_x = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
            int paso_y = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

            int i = fx + paso_x;
            int j = fy + paso_y;
            while (i != tx || j != ty) {
                if (tablero[i][j].tipo != VACIO) return 0;
                i += paso_x;
                j += paso_y;
            }
            return 1;
        }
        case 'C':
            return (abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2);
        case 'A': {
            if (abs(dx) != abs(dy)) return 0;

            int paso_x = (dx > 0) ? 1 : -1;
            int paso_y = (dy > 0) ? 1 : -1;

            for (int i = 1; i < abs(dx); i++) {
                if (tablero[fx + i * paso_x][fy + i * paso_y].tipo != VACIO) return 0;
            }
            return 1;
        }
        case 'D': {
            if (fx == tx || fy == ty) {
                int paso_x = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
                int paso_y = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
                int i = fx + paso_x;
                int j = fy + paso_y;
                while (i != tx || j != ty) {
                    if (tablero[i][j].tipo != VACIO) return 0;
                    i += paso_x;
                    j += paso_y;
                }
                return 1;
            } else if (abs(dx) == abs(dy)) {
                int paso_x = (dx > 0) ? 1 : -1;
                int paso_y = (dy > 0) ? 1 : -1;
                for (int i = 1; i < abs(dx); i++) {
                    if (tablero[fx + i * paso_x][fy + i * paso_y].tipo != VACIO) return 0;
                }
                return 1;
            }
            return 0;
        }
        case 'R': {
            if (abs(dx) <= 1 && abs(dy) <= 1) return 1;

            if (!origen.ha_movido && dx == 0 && abs(dy) == 2) {
                int fila = fx;
                int lado = (dy > 0) ? 1 : -1;
                int torre_col = (lado == 1) ? 7 : 0;

                Pieza torre = tablero[fila][torre_col];
                if (torre.tipo == 'T' && torre.color == origen.color && !torre.ha_movido) {
                    int paso_dir = (dy > 0) ? 1 : -1;
                    for (int i = fy + paso_dir; i != torre_col; i += paso_dir) {
                        if (tablero[fila][i].tipo != VACIO) return 0;
                    }

                    int original_turno = turno;

                    if (es_jaque(origen.color)) {
                        return 0;
                    }

                    Pieza temp_orig_k = tablero[fx][fy];
                    Pieza temp_dest_k1 = tablero[fx][fy + paso_dir];
                    tablero[fx][fy + paso_dir] = temp_orig_k;
                    tablero[fx][fy] = (Pieza){VACIO, -1, 0, 0};
                    turno = origen.color;
                    if (es_jaque(origen.color)) {
                        tablero[fx][fy] = temp_orig_k;
                        tablero[fx][fy + paso_dir] = temp_dest_k1;
                        turno = original_turno;
                        return 0;
                    }
                    tablero[fx][fy] = temp_orig_k;
                    tablero[fx][fy + paso_dir] = temp_dest_k1;

                    Pieza temp_dest_k2 = tablero[fx][ty];
                    tablero[fx][ty] = temp_orig_k;
                    tablero[fx][fy] = (Pieza){VACIO, -1, 0, 0};
                    turno = origen.color;
                    if (es_jaque(origen.color)) {
                        tablero[fx][fy] = temp_orig_k;
                        tablero[fx][ty] = temp_dest_k2;
                        turno = original_turno;
                        return 0;
                    }
                    tablero[fx][fy] = temp_orig_k;
                    tablero[fx][ty] = temp_dest_k2;

                    turno = original_turno;

                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}

void hacer_movimiento(int fx, int fy, int tx, int ty) {
    Pieza origen_pieza = tablero[fx][fy];
    Pieza* origen_ptr = &tablero[fx][fy];
    Pieza* destino_ptr = &tablero[tx][ty];

    if (origen_pieza.tipo == 'P' && abs(fy - ty) == 1 && destino_ptr->tipo == VACIO) {
        tablero[fx][ty] = (Pieza){VACIO, -1, 0, 0};
    }

    *destino_ptr = origen_pieza;
    destino_ptr->ha_movido = 1;
    tablero[fx][fy] = (Pieza){VACIO, -1, 0, 0};

    if (origen_pieza.tipo == 'P' && abs(tx - fx) == 2) {
        destino_ptr->en_passant = 1;
    } else {
        destino_ptr->en_passant = 0;
    }

    if (destino_ptr->tipo == 'P' && (tx == 0 || tx == 7)) {
        promocion_peon(tx, ty);
    }

    if (origen_pieza.tipo == 'R' && abs(ty - fy) == 2) {
        int fila = fx;
        int lado = (ty - fy > 0) ? 1 : -1;
        int torre_col = (lado == 1) ? 7 : 0;
        int nueva_col_torre = fy + (lado == 1 ? 1 : -1);

        tablero[fila][nueva_col_torre] = tablero[fila][torre_col];
        tablero[fila][torre_col] = (Pieza){VACIO, -1, 0, 0};
        tablero[fila][nueva_col_torre].ha_movido = 1;
    }
}

void guardar_partida(const char* nombre) {
    FILE* f = fopen(nombre, "w");
    if (!f) {
        printf("Error: No se pudo abrir el archivo '%s' para guardar la partida.\n", nombre);
        return;
    }

    fprintf(f, "%d\n", turno);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Pieza p = tablero[i][j];
            char tipo_guardar = (p.tipo == VACIO) ? 'V' : p.tipo;
            fprintf(f, "%c %d %d %d\n", tipo_guardar, p.color, p.ha_movido, p.en_passant);
        }
    }
    fclose(f);
    printf("Partida guardada en '%s'.\n", nombre);
}

void cargar_partida(const char* nombre) {
    FILE* f = fopen(nombre, "r");
    if (!f) {
        printf("Error: No se pudo abrir el archivo '%s' para cargar la partida.\n", nombre);
        exit(1);
    }

    fscanf(f, "%d\n", &turno);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char tipo_leido;
            int color, ha_movido, en_passant;
            fscanf(f, " %c %d %d %d\n", &tipo_leido, &color, &ha_movido, &en_passant);
            tablero[i][j] = (Pieza){(tipo_leido == 'V' ? VACIO : tipo_leido), color, ha_movido, en_passant};
        }
    }
    fclose(f);
    printf("Partida cargada desde '%s'.\n", nombre);
}

int rey_existe(int color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tablero[i][j].tipo == 'R' && tablero[i][j].color == color) {
                return 1;
            }
        }
    }
    return 0;
}

void promocion_peon(int x, int y) {
    char eleccion;
    printf("Promociona el peón a (D-Dama, T-Torre, A-Alfil, C-Caballo): ");
    scanf(" %c", &eleccion);
    while (getchar() != '\n');

    eleccion = toupper(eleccion);

    if (strchr("DTAC", eleccion)) {
        tablero[x][y].tipo = eleccion;
    } else {
        printf("Elección inválida, promocionando a Dama por defecto.\n");
        tablero[x][y].tipo = 'D';
    }
}

void limpiar_en_passant(int color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tablero[i][j].tipo == 'P' && tablero[i][j].color == color && tablero[i][j].en_passant == 1) {
                tablero[i][j].en_passant = 0;
            }
        }
    }
}

int hay_movimientos_legales(int color) {
    int original_turno = turno;

    for (int fx = 0; fx < 8; fx++) {
        for (int fy = 0; fy < 8; fy++) {
            Pieza p = tablero[fx][fy];
            if (p.tipo == VACIO || p.color != color) continue;

            for (int tx = 0; tx < 8; tx++) {
                for (int ty = 0; ty < 8; ty++) {
                    turno = color;
                    if (validar_movimiento(fx, fy, tx, ty)) {
                        Pieza temp_origen = tablero[fx][fy];
                        Pieza temp_destino = tablero[tx][ty];
                        int temp_en_passant_orig = tablero[fx][fy].en_passant;
                        int temp_ha_movido_orig = tablero[fx][fy].ha_movido;

                        hacer_movimiento(fx, fy, tx, ty);

                        int jaque_despues_mov = es_jaque(color);

                        tablero[fx][fy] = temp_origen;
                        tablero[tx][ty] = temp_destino;
                        tablero[fx][fy].en_passant = temp_en_passant_orig;
                        tablero[fx][fy].ha_movido = temp_ha_movido_orig;

                        if (!jaque_despues_mov) {
                            turno = original_turno;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    turno = original_turno;
    return 0;
}

int es_jaque(int color) {
    int rx = -1, ry = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Pieza p = tablero[i][j];
            if (p.tipo == 'R' && p.color == color) {
                rx = i;
                ry = j;
                break;
            }
        }
        if (rx != -1) break;
    }

    if (rx == -1) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Pieza p_atacante = tablero[i][j];
            if (p_atacante.tipo != VACIO && p_atacante.color != color) {
                int original_turno = turno;
                turno = p_atacante.color;
                int puede_atacar = validar_movimiento(i, j, rx, ry);
                turno = original_turno;

                if (puede_atacar) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
