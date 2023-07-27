#include <stdio.h> 

int main() {
  int Ncomandos_emitidos;
  char direcao_atual = {'N'};
  char direcoes[] = {'N', 'L', 'S', 'O'};
        
  scanf("%d", &Ncomandos_emitidos);
        
  for (int i = 0; i < Ncomandos_emitidos; i++){
    char comando;
    scanf(" %c", &comando);
            
    int indice_atual;
    for (int j = 0; j < 4; j++){
      if (direcoes[j] == direcao_atual)
        indice_atual = j;
    }

    if (comando == 'E'){
      indice_atual = (indice_atual - 1 + 4) % 4;
    } else if (comando == 'D'){
      indice_atual = (indice_atual + 1) % 4;
    }
            
    direcao_atual = direcoes[indice_atual];
  }
  printf("%c", direcao_atual);
}
