#include "aluno.h"

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

int main (void)
{
	/* Declara��o de vari�veis */
	Aluno *vet;
	int qtd_alunos;
	Aluno* alunoMaiorNota = (Aluno*) malloc(sizeof(Aluno));
	Aluno* alunoMaiorMedia = (Aluno*) malloc(sizeof(Aluno));
	Aluno* alunoMenorMedia = (Aluno*) malloc(sizeof(Aluno));
	
	/* Atribuir o n�mero de alunos */
	printf("Deseja cadastrar quantos alunos? \n");
	scanf("%d", &qtd_alunos);
	
	/* Aloca��o din�mica do vetor */
	vet = cria(qtd_alunos);
	
	/* Cadastro dos alunos no vetor */
	cadastro(qtd_alunos, vet);
	
	/* Aluno com a maior nota da prova 1 */
	maiorNota(qtd_alunos, vet, alunoMaiorNota);
	printf("Melhor prova 1: \n Matricula: %d\n Aluno: %d\n Prova 1: %f\n", alunoMaiorNota->matricula, alunoMaiorNota->nome, alunoMaiorNota->p1);
	printf("--------------------------\n");
	
	/* Aluno com a maior m�dia */
	maiorMedia (qtd_alunos, vet, alunoMaiorMedia);
	printf("\nMaior media: \n Matricula: %d\n Aluno: %s\n Media: %f\n", alunoMaiorMedia->matricula, alunoMaiorMedia->nome, (alunoMaiorMedia->p1 + alunoMaiorMedia->p2 + alunoMaiorMedia->p3) / 3);
	printf("--------------------------\n");
	
	/* Aluno com a menor m�dia */
	menorMedia (qtd_alunos, vet, alunoMenorMedia);
	printf("\nMenor media: \n Matricula: %d\n Aluno: %s\n Media: %f\n", alunoMenorMedia->matricula, alunoMenorMedia->nome, (alunoMenorMedia->p1 + alunoMenorMedia->p2 + alunoMenorMedia->p3) / 3);
	printf("--------------------------\n");
	
	/* Situa��o dos alunos */
	situacaoAluno (qtd_alunos, vet);
	
	/* Libera mem�ria */
	free(alunoMaiorNota);
	free(alunoMaiorMedia);
	free(alunoMenorMedia);
	free(vet);
	
	/* Fim do programa */
	return 0;
}
