#include <stdio.h>

/*
 	Digita o numero de posi��es em n,
 	ent�o digitamos as posi��es de largada 
 	e chegada. Ent�o percorremos de 0 at� n
 	e mais uma vez de 0 at� n para encontrarmos
 	a posi��o de indices da chegada e criarmos um
 	vetor. Depois percorremos de 0 at� n e de i + 1
 	at� n e comparamos se a posi��o i do vetor e
 	maior que que a posi��o j aplicamos a ordenacao
 	e adicionamos mais 1 na contagem de mudan�as.
*/

int main()
{
	int largada[24], chegada[24];
	int n, i, j;
	
	while(scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &largada[i]);
		
		for (i = 0; i < n; i++)
			scanf("%d", &chegada[i]);
		
		int vetor[n], count = 0, aux;
		
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (largada[i] == chegada[j])
	            {
	                vetor[j] = i;
	            }
		
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (vetor[i] > vetor[j])
				{
					aux = vetor[j];
					vetor[j] = vetor[i];
					vetor[i] = aux;
					count++;
				}
		
		printf("%d\n", count);
	}
	
	return 0;
}
