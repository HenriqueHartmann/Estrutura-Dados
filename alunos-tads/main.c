#include "aluno.h"

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

int main (void)
{
	/* Declaração de variáveis */
	Aluno *vet;
	int qtd_alunos;
	Aluno* alunoMaiorNota = (Aluno*) malloc(sizeof(Aluno));
	Aluno* alunoMaiorMedia = (Aluno*) malloc(sizeof(Aluno));
	Aluno* alunoMenorMedia = (Aluno*) malloc(sizeof(Aluno));
	
	/* Atribuir o número de alunos */
	printf("Deseja cadastrar quantos alunos? \n");
	scanf("%d", &qtd_alunos);
	
	/* Alocação dinâmica do vetor */
	vet = cria(qtd_alunos);
	
	/* Cadastro dos alunos no vetor */
	cadastro(qtd_alunos, vet);
	
	/* Aluno com a maior nota da prova 1 */
	maiorNota(qtd_alunos, vet, alunoMaiorNota);
	printf("Melhor prova 1: \n Matricula: %d\n Aluno: %d\n Prova 1: %f\n", alunoMaiorNota->matricula, alunoMaiorNota->nome, alunoMaiorNota->p1);
	printf("--------------------------\n");
	
	/* Aluno com a maior média */
	maiorMedia (qtd_alunos, vet, alunoMaiorMedia);
	printf("\nMaior media: \n Matricula: %d\n Aluno: %s\n Media: %f\n", alunoMaiorMedia->matricula, alunoMaiorMedia->nome, (alunoMaiorMedia->p1 + alunoMaiorMedia->p2 + alunoMaiorMedia->p3) / 3);
	printf("--------------------------\n");
	
	/* Aluno com a menor média */
	menorMedia (qtd_alunos, vet, alunoMenorMedia);
	printf("\nMenor media: \n Matricula: %d\n Aluno: %s\n Media: %f\n", alunoMenorMedia->matricula, alunoMenorMedia->nome, (alunoMenorMedia->p1 + alunoMenorMedia->p2 + alunoMenorMedia->p3) / 3);
	printf("--------------------------\n");
	
	/* Situação dos alunos */
	situacaoAluno (qtd_alunos, vet);
	
	/* Libera memória */
	free(alunoMaiorNota);
	free(alunoMaiorMedia);
	free(alunoMenorMedia);
	free(vet);
	
	/* Fim do programa */
	return 0;
}
