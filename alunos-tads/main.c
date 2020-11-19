#include "functions.h"

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

int main (void)
{
	/* Declaração de variáveis */
	Aluno *v;
	int i, n;
	Aluno *mp1;
	
	/* Leitura do número de valores */
	printf("Deseja cadastrar quantos alunos? \n");
	scanf("%d", &n);
	
	/* Alocação dinâmica */
	v = (Aluno*) malloc(n*sizeof(Aluno));
	if (v==NULL)
	{
		printf("Memoria Insuficiente.\n");
		return 1;
	}
	
	/* Leitura dos valores */
	for ( i = 0; i < n; i++ )
	{
		printf("Aluno: %d \n", i+1);
		
		printf("Digite o numero de matricula: \n");
		scanf("%d", &v[i].matricula);
		
		printf("Digite o nome: (max 50 caracteres)\n");
		scanf("%s", v[i].nome);
		fflush(stdin);
		
		printf("Digite a nota da prova 1: \n");
		scanf("%f", &v[i].p1);
		
		printf("Digite a nota da prova 2: \n");
		scanf("%f", &v[i].p2);
		
		printf("Digite a nota da prova 3: \n");
		scanf("%f", &v[i].p3);
	}
	
	mp1 = maiorNota(n, v);
	printf("Melhor p1 = \n{\n Aluno: %d\n P1: %f\n}", mp1->matricula, mp1->p1);
	
	/* Libera memória */
	free(v);
	
	/* Fim do programa */
	return 0;
}
