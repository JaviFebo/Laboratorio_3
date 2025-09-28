#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

//Función que suma todos los elementos en una línea de una matriz
int sumar_linea (int matriz[SIZE][SIZE], int i) {
	int suma = 0;

	for (int j = 0; j < SIZE; j++) { //Se itera por cada columna en una línea de la matriz
		suma = suma + matriz[i][j];
	}

	return suma;
}

//Función que suma todos los elementos en una columna de una matriz
int sumar_columna (int matriz[SIZE][SIZE], int j) {
	int suma = 0;

	for (int i = 0; i < SIZE; i++) { //Se itera por cada línea en una columna de la matriz
		suma = suma + matriz[i][j];
	}

	return suma;
}

//Función que suma todos los elementos de la diagonal principal en una matriz
int sumar_diagPrim (int matriz[SIZE][SIZE]) {
	int suma = 0;

	for (int i = 0, j = 0; i < SIZE; i++, j++) { //Se recorre la diagonal principal de la matriz
		suma = suma + matriz[i][j];
	}

	return suma;
}

//Función que suma todos los elementos de la diagonal secundaria en una matriz
int sumar_diagSec (int matriz[SIZE][SIZE]) {
	int suma = 0;

	for (int i = 0, j = SIZE-1; i < SIZE; i++, j--) { //Se recorre la diagonal secundaria de la matriz
		suma = suma + matriz[i][j];
	}

	return suma;
}

//Función que verifica si una matriz es un cuadrado mágico
int es_cuadradoMagico (int matriz[SIZE][SIZE]) {
	int suma_magica = sumar_linea (matriz, 0); //Se obtiene el valor mágico de sumar los elementos de la primera línea
	
	int suma_diag_prim = sumar_diagPrim (matriz);
	int suma_diag_sec = sumar_diagSec (matriz);

	if (suma_diag_prim != suma_magica || suma_diag_sec != suma_magica) { //Si la suma de las diagonales no es igual al valor mágico retorna falso
		return 0;
	}


	for (int i = 0; i < SIZE; i++) { //Se itera por cada línea de la matriz
		int suma_linea_i = sumar_linea (matriz, i);
		if (suma_linea_i != suma_magica) { //Si la suma de una línea no es igual al valor mágico retorna falso
			return 0;
		}
	}

	for (int j = 0; j < SIZE; j++) { //Se itera por cada columna de la matriz
		int suma_col_j = sumar_columna (matriz, j);
		if (suma_col_j != suma_magica) { //Si la suma de una columna no es igual al valor mágico retorna falso
			return 0;
		}
	}

	return 1;
}

//Función que imprime una matriz línea por línea
int imprimir_matriz (int matriz [SIZE][SIZE]) {
	for (int i = 0; i < SIZE; ++i) { //Se itera cada línea de la matriz
		for (int j = 0; j < SIZE; ++j) { //Se itera cada columna de la matriz
			printf (" %d ", matriz[i][j]);
		}
		printf ("\n");
	}
	return 0;
}

//Función que genera una matriz cuadrada con valores aleatorios
void poblar_matrizRand (int matriz [SIZE][SIZE]) {
	srand (time(NULL));
	int max = 9; //El valor máximo para poblar la matriz es 9
	int min = 0; //El valor mínimo para poblar la matriz es 0

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			matriz [i][j] = rand() % (max + 1 - min) + min;
		}
	}
}

int main () {
	int matriz_const [SIZE][SIZE] = { //Se inicializa una matriz constante
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
	
	int matriz_rand [SIZE][SIZE]; //Se inicializa la matriz que será poblada de forma aleatoria
	poblar_matrizRand(matriz_rand); //Se pobla la matriz de forma aleatoria
	
	printf ("\nLa matriz aleatoria utilizada fue:\n");
	imprimir_matriz (matriz_rand);
	
	if (es_cuadradoMagico(matriz_rand)) {
		printf ("La matriz es un cuadrado mágico\n");
	} else {
		printf ("La matriz no es un cuadrado mágico\n");
	}
	
	return 0;
}
