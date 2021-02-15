#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

// Agrupa as variaveis float x e y e cria um novo tipo de variavel
struct coord {
	float x;
	float y;
};

typedef struct coord Coord; // Renomeia a estrutura coord como Coord

// Protótipo das funções
Coord* atribuir (); // Captura os valores de x e y via teclado e retorna um valor do tipo Coord
float calcDistancia (Coord* a, Coord* b); // Aplica a fórmula de cálculo de distância entre duas coordenadas

// Função Main
int main (void)
{
	printf("Ponto A: \n"); // Imprime a mensagem
	Coord* a = atribuir(); // Declara a variavel a como Coord e atribui seu valor por meio do retorno da função atribuir
	
	printf("\n"); // Imprime a mensagem, mais precisamente quebra a linha
	
	printf("Ponto B: \n"); // Imprime a mensagem
	Coord* b = atribuir(); // Declara a variavel b como Coord e atribui seu valor por meio do retorno da função atribuir
	
	float dist = calcDistancia(a, b); // Declara e atribui a variavel dist do tipo float com o retorno da função calcDistancia
	printf("Distancia: %f", dist); // Imprime o valor da variavel dist
	
	// Fim do Programa
	return 0;
}

// Desenvolvimento das Funções
Coord* atribuir ()
{
	// Declara as variaveis x e y como float
	float x, y;
	
	printf("Digite o valor de X: "); // Imprime a mensagem
	scanf("%f", &x); // Captura o valor de entrada via teclado e atribui a variavel x
	
	printf("Digite o valor de Y: "); // Imprime a mensagem
	scanf("%f", &y); // Captura o valor de entrada via teclado e atribui a variavel y
	
	Coord* novo = (Coord*) malloc(sizeof(Coord*)); // Faz a alocação dinâmica do tipo Coord
	novo->x = x; // O elemento x de novo recebe x que foi inserido via teclado
	novo->y = y; // O elemento y de novo recebe y que foi inserido via teclado
	return novo; // Retorna novo
}

float calcDistancia (Coord* a, Coord* b)
{
	float s1 = pow((b->x - a->x), 2); // Declara s1 e atribui seu valor a subtração de Xb e Xa ao quadrado
	float s2 = pow((b->y - a->y), 2); // Declara s2 e atribui seu valor a subtração de Yb e Ya ao quadrado
	return sqrt((s1 + s2)); // Retorna o valor da raiz quadrado da soma de s1 + s2
	
}

