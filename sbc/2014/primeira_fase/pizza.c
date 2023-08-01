#include <stdio.h>
#include <stdbool.h>

char isPossible(int positions[], int qtde, int circu) {

	if(qtde > circu || circu % qtde != 0)
		return 'N';

	int comprimentoSetor = circu / qtde;
	printf("Comprimento de cada setor: %d\n", comprimentoSetor);

	int limits[qtde+1];
	for(int i = 0; i <= qtde; i++) {
		limits[i] = i*comprimentoSetor; // 0 4 8 e 12
		printf("Limite %d: %d\n", i+1, limits[i]);
	}
	
	for(int i = 0; i < circu; i++) {
	
		bool possible = false;

		for(int j = 0; j < qtde; j++) {
		
			printf("Analisando se %d é maior que %d e menor que %d\n", positions[j], limits[j], limits[j+1]);	
			if(positions[j] > limits[j] && positions[j] < limits[j+1]) {
				printf("Está dentro do intervalo\n");
				possible = true;
			} else {
				printf("Não está dentro do intervalo\n");
				possible = false;
				break;	
			}
		}
	
		if(possible) {
			printf("Existe uma partição\n");
			return 'S';
		} else {
			printf("Não existe uma combinação, deslocando os limites: \n");
			for(int i = 0; i <=qtde; i++) {
					limits[i]++;
					printf("Limite %d: %d\n", i+1, limits[i]);
			}
		}
	}

	return 'N';
}

int main() {

	int circu, qtde;
	scanf("%d %d", &circu, &qtde);

	int positions[qtde];
	for(int i = 0; i < qtde; i++) {
		scanf("%d", &positions[i]);
	}

	char asnw = isPossible(positions, qtde, circu);
	printf("%c\n", asnw);
	return 0;
}
