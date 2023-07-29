#include <stdio.h>

void descendenteMuda(int doors[], int size, int index) {
	for(int i = 1; i <= size; i++) {
		if(i > 0 && i % index == 0)
			doors[i] = !doors[i];
	}
}

void showOpened(int doors[], int size) {
	for(int i = 1; i <= size; i++) {
		if(doors[i] == 1)
			printf("%d ", i);
	}
	putchar('\n');
}

int main() {

	int num;
	scanf("%d", &num);

	int doors[num+1];
	//Porta fechada: 0; porta aberta: 1;
	for(int i = 1; i <= num; i++)
		doors[i] = 0;


	for(int i = 1; i <= num; i++)
		descendenteMuda(doors, num, i);

	showOpened(doors, num);

	return 0;
}
