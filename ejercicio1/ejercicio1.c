#include <stdio.h>
#include <stdlib.h>


int factorial (int n) {
	int i = 1;
	if ( n == 1 ) {
		return i;
	}
	while (n > 1) {
		i = i * n;
		n = n - 1;
	}
	return i;
}

int main (int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("%d! =  %d\n", n, factorial(n));
	return 0;
}
