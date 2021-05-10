#include <stdio.h>

int lenVet (int *vet);
int check (int *vet);
void bubbleAndMirror (int *vet1, float *vet2);
void printVet (int *vet1, float *vet2);

int main()
{
	int v1[] = {5, 4, 3, 2};
	float v2[] = {0.65, 0.23, 1.2, 0.75};
	bubbleAndMirror(v1, v2);
	printVet(v1, v2);
	
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

void bubbleAndMirror (int *vet1, float *vet2)
{
	int correct = check(vet1);
	while (correct != 0)
	{
		for (int i = 0; i < lenVet(vet1) - 1; i++)
		{
			if (vet1[i] > vet1[i+1])
			{
				// Vet1 bubble sort
				int aux1 = vet1[i];
				vet1[i] = vet1[i+1];
				vet1[i+1] = aux1;
				
				// Vet2 mirroring Vet1
				float aux2 = vet2[i];
				vet2[i] = vet2[i+1];
				vet2[i+1] = aux2;
			}
		}
		correct = check(vet1);
	}
}

void printVet (int *vet1, float *vet2)
{
	for (int i = 0; i < lenVet(vet1); i++)
	{
		printf("%d = %f\n", vet1[i], vet2[i]);
	}
}

