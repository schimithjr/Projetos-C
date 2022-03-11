#include <stdio.h>
#include <stdlib.h>

float recursivoMaior(float *ponteiro, float maior){
	if(ponteiro==NULL){
		return maior;
	} else{
		if(maior<=*ponteiro){
			maior = *ponteiro;
			ponteiro++;
			return recursivoMaior(ponteiro, maior);
		} else if (maior>*ponteiro){
			ponteiro++;
			return recursivoMaior(ponteiro, maior);
		}
	}
}

int main(){
	float vetor[3]= {1, 3, 2};
	float maior= -50000;

	printf("%f", recursivoMaior(vetor, maior));
	
	return 0;
}
