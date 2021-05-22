#include <stdio.h>

void selectionSort(int *vet, int size);
void printVet (int *vet, int size);

int main()
{
	int vet[] = {5, 4, 2, 3};
	selectionSort(vet, 4);
	printVet(vet, 4);
	
	return 0;
}

void selectionSort(int *vet, int size)
{
	int k = 0;
	while (k < size)
	{
		int i = k, smallPos = i, aux = NULL;
		while (i < size)
		{
			if (vet[i] < vet[smallPos])
				smallPos = i;
			i++;
		}
		aux = vet[k];
		vet[k] = vet[smallPos];
		vet[smallPos] = aux;
		k++;
	}
}

void printVet (int *vet, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", vet[i]);
	}
}

