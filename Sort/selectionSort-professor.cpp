#include <stdio.h>

void selection_sort(int num[], int n);
void print_vet (int num[], int n);

int main()
{
	int v[] = {5, 4, 2, 3};
	selection_sort(v, 4);
	print_vet(v, 4);
	
	return 0;
}

void selection_sort(int num[], int n)
{
	int i, j, min, aux;
	for (i = 0; i < (n-1); i++)
	{
		min = i;
		for (j = (i+1); j < n; j++)
		{
			if (num[j] < num[min])
				min = j;
		}
		if (i != min) {
			aux = num[i];
			num[i] = num[min];
			num[min] = aux;
		}
	}
}

void print_vet (int num[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
}

