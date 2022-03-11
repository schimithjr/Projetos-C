#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

bool palindromo(int tamanho, char *palavra, int i){
	if(palavra[tamanho-1]==palavra[i]){
		if(tamanho<i){ 
			return palindromo(tamanho-1, palavra, i+1);
		} else{
			return true;
		}
	} else {
		return false;
	}
}

int main(){
	setlocale(LC_ALL, ""); 
	char palavra[10]="ana";
	int t= strlen(palavra); 
	bool p;
	int aux=0;
	p= palindromo(t, palavra, aux);
	
	if(p){
		printf("É um palíndromo");
	} else{
		printf("Não é palíndoromo");
	}
	
	return 0;
}
