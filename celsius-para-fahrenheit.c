#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Converte Celsius em Fahrenheit */
float converte (float c)
{
	float f;
	f = c * 1.8 +32.0;
	return f;
}

int main(void) 
{
	float t1, t2;
	
	/* Mostra mensagem para usuario */
	printf("Digite a temperatura em Celsius: ");
	
	/* Captura valor de entrada via teclado */
	scanf("%f", &t1);
	
	/* Chama a function converte */
	t2 = converte(t1);
	
	/* Exibe o resultado */
	printf("A temperatura em Fahrenheit e: %f\n", t2);
	
	/* Termina o programa*/
	return 0;
}
