#include "functions.h" /* interface functions.h */

/* 
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4 
*/

Aluno* maiorNota (int n, Aluno* v)
{
	int i;
	float nota = 0;
	Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
	
	for ( i = 0; i < n; i++ )
	{
		if (v[i].p1 > nota)
		{
			nota = v[i].p1;
			aluno = v[i];
		}
		
	}
	
	return aluno;
}

