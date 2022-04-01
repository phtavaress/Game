#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
}Calcular;

void jogar();
void mostrarInfo(Calcular calcular);
int pontos = 0;

int main() {
	// Deve ser chamado apenas uma vez.
	srand(time(NULL));
	jogar();
	return 0;
}

void jogar() {
	//TODO Implementar
}

void mostrarInfo(Calcular calcular) {
	//TODO Implementar
}

int somar(int resposta, Calcular calcular) {
	//TODO Implementar
}

int diminuir(int resposta, Calcular calcular) {
	//TODO Implementar
}

int multiplicar(int resposta, Calcular calcular) {
	//TODO Implementar
}
