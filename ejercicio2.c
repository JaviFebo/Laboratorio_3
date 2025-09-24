#include <stdio.sh>

#define SIZE 5

int findLargestLine (int matrix[][SIZE]) {
	//Implementación
}

int main () {
	int matrix [SIZE][SIZE] = {
		{2, 7, 6},
		{9, 5, 1},
		{4, 3, 8}
	};

	int largestLine = findLargestLine (matrix);
	printf ("El tamaño de la secuencia de 1s mas grande es: %d\n", largestLine);

	return 0;
}

