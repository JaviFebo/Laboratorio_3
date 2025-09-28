#include <stdio.h>
#include <stdlib.h>

//Función que calcula n!
int factorial (int n) {
	int i = 1;
	if ( n == 1 || n == 0 ) {
		return i; //Si n es 1 o 0 devuelve 1
	}
	while (n > 1) {
		i = i * n;
		n = n - 1;
	}
	return i;
}

int main (int argc, char *argv[]) {
	int n = atoi(argv[1]); //Guarda el primer argumento que se le pasa al programa como int
	printf("%d! =  %d\n", n, factorial(n));
	return 0;
}
