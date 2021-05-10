#include <stdio.h>

void insertion_sort (int vetor[], int n);
void print_vet (int num[], int n);

int main()
{
	int v[] = {5, 4, 2, 3};
    insertion_sort(v, 4); 
    print_vet(v, 4);
	
	return 0;
}

void insertion_sort(int vetor[], int n){
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void print_vet (int num[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
}

