#include <stdio.h>
#include <stdlib.h>

int lenVet (int *vet);
int check (int *vet);
int* swap (int *vet);
int* bubbleSort (int *vet);
void printVet (int *vet);

int main()
{
	int vet[4];
	vet[0] = 5;
	vet[1] = 4;
	vet[2] = 2;
	vet[3] = 3;
	
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
	int len = lenVet(vet);
	for (int i = 0; i < len; i++)
	{
		if (len - 1 == i)
		{
			break;
		}
		if (vet[i] > vet[i+1])
		{
			correct = 1;
			return correct;
		}
	}
	
	return correct;
}

int* swap (int *vet)
{
	int len = lenVet(vet);
	for (int i = 0; i < len; i++)
	{
		if (len - 1 == i)
		{
			break;
		}
		if (vet[i] > vet[i+1])
		{
			int aux = vet[i];
			vet[i] = vet[i+1];
			vet[i+1] = aux;
		}
	}
	
	return vet;
}

int* bubbleSort (int *vet)
{
	int correct = check(vet);
	while (correct != 0)
	{
		vet = swap(vet);
		correct = check(vet);
	}
	
	return vet;
}

void printVet (int *vet)
{
	int len = lenVet(vet);
	for (int i = 0; i < len; i++)
	{
		printf("%d", vet[i]);
	}
}

