#include <stdio.h>

int lenVet (int *vet);
void selectionSort(int *vet);
void printVet (int *vet);

int main()
{
	int vet[] = {5, 4, 2, 3};
	selectionSort(vet);
	printVet(vet);
	
	return 0;
}

int lenVet (int *vet)
{
	return sizeof(*vet);
}

void selectionSort(int *vet)
{
	int k = 0;
	int size = lenVet(vet);
	while (k < size)
	{
		int i = k;
		int smallPos = NULL;
		int aux = NULL;
		while (i < size)
		{
			if (smallPos == NULL)
			{
				smallPos = i;
			}
			if (vet[i] < vet[smallPos])
			{
				smallPos = i;
			}
			i++;
		}
		aux = vet[k];
		vet[k] = vet[smallPos];
		vet[smallPos] = aux;
		k++;
	}
}

void printVet (int *vet)
{
	for (int i = 0; i < lenVet(vet); i++)
	{
		printf("%d ", vet[i]);
	}
}


