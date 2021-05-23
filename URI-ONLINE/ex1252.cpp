#include <stdio.h>
#include <stdlib.h>

int compara(int vA, int vB, int mod);
void merge(int vetor[], int comeco, int meio, int fim, int mod);
void mergeSort(int vetor[], int comeco, int fim, int mod);

int main()
{
    int n, m, i;    
	// cria o vetor com o tamanho máximo para as entradas.
    int vetor[10001];

	//leitura do n e m
    scanf("%d %d", &n, &m);
    
    while (n>0){
        for (i = 0; i < n; ++i)
			scanf("%d", &vetor[i]);
		
		//Aqui chama o algoritmo de ordenação adaptado para esse problema, 
		//   só precisam colocar a chamada da função aqui e implementar o algoritmo de ordenação.
		
		mergeSort(vetor, 0, n-1, m);
		//quickSort(...)
		
		
		//Imprime a resposta no formato esperado.
		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i)
			printf("%d\n", vetor[i]);
	    
		
		//leitura do n e m
	    scanf("%d %d", &n, &m);
    }
    
	//Imprime o último par de n e m, mesmo quando for zero.
    printf("%d %d\n", n, m);
    
    return 0;
}

int compara(int vA, int vB, int mod)
{
	if (vA % mod < vB % mod)
		return 1;
	if (vA % mod > vB % mod)
		return 0;
	if (abs(vA % 2)== 1 && abs(vB % 2) == 1)
	{
		if (vA > vB)
			return 1;
		else
			return 0;
	}
	if (abs(vA % 2) == 0 && abs(vB % 2) == 0)
	{
		if (vA < vB)
			return 1;
		else
			return 0;
	}
	if (abs(vA % 2) == 1)
		return 1;
	else
		return 0;
}

void merge(int vetor[], int comeco, int meio, int fim, int mod)
{
	int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim - comeco + 1;
	int *vetAux;
	vetAux = (int*)malloc(tam * sizeof(int));
	
	while (com1 <= meio && com2 <= fim)
	{
		if (compara(vetor[com1], vetor[com2], mod)) 
		{
			vetAux[comAux] = vetor[com1];
			com1++;
		} 
		else 
		{
			vetAux[comAux] = vetor[com2];
			com2++;
		}
		comAux++;
	}
	
	while (com1 <= meio)
	{
		vetAux[comAux] = vetor[com1];
		comAux++;
		com1++;
	}
	
	while (com2 <= fim)
	{
		vetAux[comAux] = vetor[com2];
		comAux++;
		com2++;
	}
	
	for (comAux = comeco; comAux <= fim; comAux++)
	{
		vetor[comAux] = vetAux[comAux-comeco];
	}
	
	free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim, int mod) {
	if (comeco < fim)
	{
		int meio = (fim + comeco) / 2;
		
		mergeSort(vetor, comeco, meio, mod);
		mergeSort(vetor, meio+1, fim, mod);
		merge(vetor, comeco, meio, fim, mod);
	}
}

