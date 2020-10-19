#include <stdio.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* Escolhe o maior valor */
float maior_valor(float a, float b, float c)
{
	/* Declara e inicializa a variavel m com valor de a */
	float m = a;
	
	/* verifica se b é maior que m */
	if (b > m)
	{
	 	/* Caso seja True, m recebe b */
		m = b;
	}
	
	/* verifica se c é maior que m */
	if (c > m)
	{
		/* Caso seja True, m recebe c */
		m = c;
	}
	
	/* Retorna m */
	return m;
}

int main(void) 
{
	/* Declaracao das variaveis */
	float a,b,c,m;
	
	/* Mostra mensagem para o usuario */
	printf("Digite 3 valores \n");
	
	printf("Primeiro valor: ");
	
	/* Captura o valor de entrada via teclado e atribui a variavel a*/
	scanf("%f", &a);
	
	/* Limpa o buffer do teclado */
	fflush(stdin);

	printf("Segundo valor: ");
	
	/* Captura o valor de entrada via teclado e atribui a variavel b*/
	scanf("%f", &b);
	
	/* Limpa o buffer do teclado */
	fflush(stdin);
	
	printf("Terceiro valor: ");
	
	/* Captura o valor de entrada via teclado e atribui a variavel c*/
	scanf("%f", &c);
	
	/* Chama a function maior_valor*/
	m = maior_valor(a, b, c);
	
	/* Imprime o resultado */
	printf("O maior valor e: %f\n", m);
	
	/* Termina o programa */
	return 0;
}
