#include <stdio.h>

void bubble_sort (int vetor[], int n);
void print_vet (int vetor[], int n);

int main()
{
	int v[] = {5, 4, 2, 3};
	bubble_sort(v, 4);
	print_vet(v, 4);
	
	return 0;
}

void bubble_sort (int vetor[], int n)
{
	int k, j, aux;
	
	for (k = 1; k < n; k++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (vetor[j] > vetor[j+1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}

void print_vet (int vetor[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", vetor[i]);
	}
}

