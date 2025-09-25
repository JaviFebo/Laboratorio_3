#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	
	int suma_diag_prim = sumar_diagPrim (matriz);
	int suma_diag_sec = sumar_diagSec (matriz);

	if (suma_diag_prim != suma_magica || suma_diag_sec != suma_magica) {
		return 0;
	}


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

	return 1;
}

int imprimir_matriz (int matriz [SIZE][SIZE]) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			printf (" %d ", matriz[i][j]);
		}
		printf ("\n");
	}
	return 0;
}

void poblar_matrizRand (int matriz [SIZE][SIZE]) {
	srand (time(NULL));
	int max = 9;
	int min = 0;

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			matriz [i][j] = rand() % (max + 1 - min) + min;
		}
	}
}

int main () {
	int matriz_const [SIZE][SIZE] = {
		{2, 7, 6},
		{9, 5, 1},
		{4, 3, 8}
	};

	printf ("La matriz constante utilizada fue:\n");
	imprimir_matriz (matriz_const);
	
	if (es_cuadradoMagico(matriz_const)) {
		printf ("La matriz es un cuadrado mágico\n");
	} else {
		printf ("La matriz no es un cuadrado mágico\n");
	}
	
	int matriz_rand [SIZE][SIZE];
	poblar_matrizRand(matriz_rand);
	
	printf ("\nLa matriz aleatoria utilizada fue:\n");
	imprimir_matriz (matriz_rand);
	
	if (es_cuadradoMagico(matriz_rand)) {
		printf ("La matriz es un cuadrado mágico\n");
	} else {
		printf ("La matriz no es un cuadrado mágico\n");
	}
	
	return 0;
}
