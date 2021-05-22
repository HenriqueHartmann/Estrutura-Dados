#include <stdio.h>

int check (int *vet, int size);
void bubbleSort (int *vet, int size);
void printVet (int *vet, int size);

int main()
{
	//int vet[] = {5, 4, 2, 3};
	int vet[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80};
	bubbleSort(vet, 21);
	printVet(vet, 21);
	
	return 0;
}

int check (int *vet, int size)
{
	int correct = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (vet[i] > vet[i+1])
		{
			correct = 1;
			return correct;
		}
	}
	
	return correct;
}

void bubbleSort (int *vet, int size)
{
	int correct = check(vet, size);
	while (correct != 0)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (vet[i] > vet[i+1])
			{
				int aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
		}
		correct = check(vet, size);
	}
}

void printVet (int *vet, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", vet[i]);
	}
}

