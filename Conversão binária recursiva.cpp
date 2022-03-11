#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void bin(int n){
	int aux;
	if(n/2!=0){
		aux= n/2;
		bin(aux);
		printf("%d", n%2);	
	} else {
		printf("%d", n%2);
	}
}

int main(){
	int dec;
	setlocale(LC_ALL, "");
	printf("Digite o número que deseja encontrar sua forma binária: ");
	scanf("%d", &dec);
	
	printf("\n A forma binária de %d é ", dec);
	bin(dec);
}
