#include <stdio.h>
#include <stdlib.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* TAD: Aluno (matr�cula, nome, p1, p2, p3) */
typedef struct aluno {
	int matricula;
	char nome[50];
	float p1, p2, p3;
}Aluno; /* Define um novo tipo */


/* Cabe�alho das fun��es */

/* Recupera entre os alunos a maior nota da prova 1 */
Aluno* maiorNota (int n, Aluno* v);

/* Recupera entre os alunos a maior m�dia
Aluno maiorMedia ();

 Recupera entre os alunos a menor m�dia 
Aluno menorMedia (); 

 imprime a situa��o dos alunos(aprovado/reprovado) com base na m�dia 
void situacaoAluno (); */
