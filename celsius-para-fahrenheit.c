#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Converte Celsius em Fahrenheit */
float converte (float c)
{
	/* Declara a variavel f */
	float f;
	
	/* Inicializa a variavel f com o valor da formula de conversao*/
	f = c * 1.8 +32.0;
	
	/* Retorna f */
	return f;
}

int main(void) 
{
	/* Declaracao das variaveis */
	float t1, t2;
	
	/* Mostra mensagem para usuario */
	printf("Digite a temperatura em Celsius: ");
	
	/* Captura valor de entrada via teclado e atribui a t1 */
	scanf("%f", &t1);
	
	/* Chama a function converte e atribui seu valor a t2 */
	t2 = converte(t1);
	
	/* Exibe o resultado */
	printf("A temperatura em Fahrenheit e: %f\n", t2);
	
	/* Termina o programa*/
	return 0;
}
