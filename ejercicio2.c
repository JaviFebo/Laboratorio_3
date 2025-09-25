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
		printf ("i = %d\n", i);
		printf ("j = %d\n", j);
		printf ("m[i][j] = %d\n", matriz[i][j]);
		printf ("Suma = %d\n", suma);
	}

	return suma;
}


int main () {
	int matriz [SIZE][SIZE] = {
		{2, 7, 6},
		{9, 5, 1},
		{4, 3, 8}
	};
	

	int suma_linea = sumar_linea (matriz, 0);
	int suma_columna = sumar_columna (matriz, 0);
	int suma_diagPrim = sumar_diagPrim (matriz);
	int suma_diagSec = sumar_diagSec (matriz);

	printf ("La suma de la línea 1 es: %d\n", suma_linea);
	printf ("La suma de la columna 1 es: %d\n", suma_columna);
	printf ("La suma de la diagonal primaria es: %d\n", suma_diagPrim);
	printf ("La suma de la diagonal secundaria es: %d\n", suma_diagSec);

	return 0;
}

