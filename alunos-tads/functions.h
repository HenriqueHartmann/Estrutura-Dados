#include <stdio.h>
#include <stdlib.h>

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

/* TAD: Aluno (matrícula, nome, p1, p2, p3) */
typedef struct aluno {
	int matricula;
	char nome[50];
	float p1, p2, p3;
}Aluno; /* Define um novo tipo */


/* Cabeçalho das funções */

/* Recupera entre os alunos a maior nota da prova 1 */
Aluno* maiorNota (int n, Aluno* v);

/* Recupera entre os alunos a maior média
Aluno maiorMedia ();

 Recupera entre os alunos a menor média 
Aluno menorMedia (); 

 imprime a situação dos alunos(aprovado/reprovado) com base na média 
void situacaoAluno (); */
