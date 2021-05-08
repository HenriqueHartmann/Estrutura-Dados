#include <stdio.h>

int lenVet (int *vet);
int check (int *vet);
void swap (int *vet);
void bubbleSort (int *vet);
void printVet (int *vet);

int main()
{
	int vet[] = {5, 4, 2, 3};
	bubbleSort(vet);
	printVet(vet);
	
	return 0;
}

int lenVet (int *vet)
{
	return sizeof(*vet);
}

int check (int *vet)
{
	int correct = 0;
	for (int i = 0; i < lenVet(vet) - 1; i++)
	{
		if (vet[i] > vet[i+1])
		{
			correct = 1;
			return correct;
		}
	}
	
	return correct;
}

void swap (int *vet)
{
	for (int i = 0; i < lenVet(vet) - 1; i++)
	{
		if (vet[i] > vet[i+1])
		{
			int aux = vet[i];
			vet[i] = vet[i+1];
			vet[i+1] = aux;
		}
	}
}

void bubbleSort (int *vet)
{
	int correct = check(vet);
	while (correct != 0)
	{
		swap(vet);
		correct = check(vet);
	}
}

void printVet (int *vet)
{
	for (int i = 0; i < lenVet(vet); i++)
	{
		printf("%d ", vet[i]);
	}
}

