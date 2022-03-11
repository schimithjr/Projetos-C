#include <stdlib.h>
#include <stdio.h>

void moverTorre(int n, char orig, char dest, char aux){
	if (n==1) {
	printf("\nMover disco 1 da torre %c para a torre %c\n", orig, dest);
	return;
	}
	moverTorre(n-1,orig,aux,dest);
	printf("\nMover disco %d da torre %c para a torre %c\n", n, orig, dest);
	moverTorre(n-1,aux,dest,orig);
}
int main(){
	moverTorre(3, 'A', 'B', 'C');
}
