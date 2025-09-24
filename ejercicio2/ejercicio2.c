#include <stdio.h>

#define SIZE 3

int sumar_linea (int matriz[SIZE][SIZE], int i) {
	int suma = 0;

	for (int j = 0; j < SIZE; j++) {
		suma = suma + matriz[i][j];
	}

	return suma;
}


int sumar_columna (int matriz[SIZE][SIZE], int j) {
	int suma = 0;

	for (int i = 0; i < SIZE; i++) {
		suma = suma + matriz[i][j];
	}

	return suma;
}

int sumar_diagPrim (int matriz[SIZE][SIZE]) {
	int suma = 0;

	for (int i = 0, j = 0; i < SIZE; i++, j++) {
		suma = suma + matriz[i][j];
	}

	return suma;
}

int sumar_diagSec (int matriz[SIZE][SIZE]) {
	int suma = 0;

	for (int i = 0, j = SIZE-1; i < SIZE; i++, j--) {
		suma = suma + matriz[i][j];
	}

	return suma;
}

int es_cuadradoMagico (int matriz[SIZE][SIZE]) {
	int suma_magica = sumar_linea (matriz, 0);

	for (int i = 0; i < SIZE; i++) {
		int suma_linea_i = sumar_linea (matriz, i);
		if (suma_linea_i != suma_magica) {
			return 0;
		}
	}

	for (int j = 0; j < SIZE; j++) {
		int suma_col_j = sumar_columna (matriz, j);
		if (suma_col_j != suma_magica) {
			return 0;
		}
	}

	int suma_diag_prim = sumar_diagPrim (matriz);
	int suma_diag_sec = sumar_diagSec (matriz);

	if (suma_diag_prim != suma_magica || suma_diag_sec != suma_magica) {
		return 0;
	}

	return 1;
}

int main () {
	int matriz [SIZE][SIZE] = {
		{2, 7, 6},
		{9, 5, 1},
		{4, 3, 8}
	};
	
	if (es_cuadradoMagico(matriz)) {
		printf ("La matriz es un cuadrado mágico\n");
	} else {
		printf ("La matriz no es un cuadrado mágico\n");
	}

	return 0;
}

