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
int somar(int resposta, Calcular calcular);
int diminuir(int resposta, Calcular calcular);
int multiplicar(int resposta, Calcular calcular);
int pontos = 0;

int main() {
	// Deve ser chamado apenas uma vez.
	srand(time(NULL));
	jogar();
	return 0;
}

void jogar() {
	Calcular calcular;
	int dificuldade;
	printf("Informe o nível de dificuldade desejado [1, 2, 3, 4]:\n ");
	scanf("%d", &dificuldade);
	calcular.dificuldade = dificuldade;
	// 0 = Somar; 1 = Subtrair; 2 = Multiplicar
	calcular.operacao = rand() % 3;
	if(calcular.dificuldade == 1) {
		calcular.valor1 = rand() % 11; // 0 a 10
		calcular.valor2 = rand() % 11;
	} else if(calcular.dificuldade == 2) {
		calcular.valor1 = rand() % 101; // 0 a 100
		calcular.valor2 = rand() % 101;
	} else if(calcular.dificuldade == 3) {
		calcular.valor1 = rand() % 1001; // 0 a 1000
		calcular.valor2 = rand() % 1001;
	} else if(calcular.dificuldade == 4) {
		calcular.valor1 = rand() % 10001; // 0 a 10000
		calcular.valor2 = rand() % 10001;
	} else {
		calcular.valor1 = rand() % 100001; // 0 a 100000
		calcular.valor2 = rand() % 100001;
	}

	int resposta;
	printf("Informe o resultado para a seguinte operação: ");
	if(calcular.operacao == 0) {
		printf("%d + %d\n", calcular.valor1, calcular.valor2);
		scanf("%d", &resposta);
		if(somar(resposta, calcular)) {
			pontos += 1;
			printf("Você tem %d pontos.\n", pontos);
		}
	} else if(calcular.operacao == 1) {
		printf("%d - %d\n", calcular.valor1, calcular.valor2);
		scanf("%d", &resposta);
		if(diminuir(resposta, calcular)) {
			pontos += 1;
			printf("Você tem %d pontos.\n", pontos);
		}
	  } else if(calcular.operacao == 2) {
		  printf("%d x %d\n", calcular.valor1, calcular.valor2);
		  scanf("%d", &resposta);
		  if(multiplicar(resposta, calcular)) {
			  pontos += 1;
			  printf("Você tem %d pontos.\n", pontos);
		  }
	  } else {
		  printf("A operação %d não é reconhecida.\n", calcular.operacao);
	  }
	printf("Deseja continuar jogando? [1 - Sim; 0 - Não]");
	int continuar;
	scanf("%d", &continuar);
	if(continuar) {
		jogar();
	} else {
		printf("Você finalizou com %d pontos.\n", pontos);
		printf("Até a próxima!");
	}
}

void mostrarInfo(Calcular calcular) {
	char option[25];
	if(calcular.operacao == 0) {
		sprintf(option, "Somar");
	} else if(calcular.operacao == 1) {
		sprintf(option, "Subtrair");
	} else if(calcular.operacao == 2) {
		sprintf(option, "Multiplicar");
	} else {
		sprintf(option, "Operação inválida.");
	}
	printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperação: %s", calcular.valor1, calcular.valor2,
			calcular.dificuldade, option);
}

int somar(int resposta, Calcular calcular) {
	int resultado = calcular.valor1 + calcular.valor2;
	calcular.resultado = resultado;
	int certo = 0;
	if(resposta == calcular.resultado) {
		printf("Resposta correta!\n");
		certo = 1;
	} else {
		printf("Resposta errada.\n");
	}
	printf("%d + %d = %d\n", calcular.valor1, calcular.valor2, calcular.resultado);
	return certo;
}

int diminuir(int resposta, Calcular calcular) {
	int resultado = calcular.valor1 - calcular.valor2;
	calcular.resultado = resultado;
	int certo = 0;
	if(resposta == calcular.resultado) {
		printf("Resposta correta!\n");
		certo = 1;
	} else {
		printf("Resposta errada.\n");
	}
	printf("%d - %d = %d\n", calcular.valor1, calcular.valor2, calcular.resultado);
	return certo;
}

int multiplicar(int resposta, Calcular calcular) {
	int resultado = calcular.valor1 * calcular.valor2;
	calcular.resultado = resultado;
	int certo = 0;
	if(resposta == calcular.resultado) {
		printf("Resposta correta!\n");
		certo = 1;
	} else {
		printf("Resposta errada.\n");
	}
	printf("%d x %d = %d\n", calcular.valor1, calcular.valor2, calcular.resultado);
	return certo;
}
