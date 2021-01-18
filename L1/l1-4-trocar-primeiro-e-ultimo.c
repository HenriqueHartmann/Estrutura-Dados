#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

void imprimir (int arr[3][4])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d\n", arr[i][j]);
		}
		printf("---- \n");	
	}
}

int main (void)
{
	int i;
	int arr[3][4] = {{1, 2, 3, 4},
					 {5, 6, 7, 8},
					 {9, 10, 11, 12}};				
	int a[4], b[4];
	
	for (i = 0; i < 4; i++)
	{
		a[i] = arr[0][i];
		b[i] = arr[2][i];
	}	
	
	for (i = 0; i < 4; i++)
	{
		arr[0][i] = b[i];
		arr[2][i] = a[i];
	}

	imprimir(arr);
	
	return 0;
}

