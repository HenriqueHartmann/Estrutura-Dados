#include <stdio.h>

void selectionSort(int v[], int n);
void classificar(int v[], int n, int k);

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	if (k < 0 || k > n)
		return 1;
	
	int pontuacao[n];
	
	for (int i = 0; i < n; i++)
		scanf("%d", &pontuacao[i]);
	
	classificar(pontuacao, n, k);
	
	return 0;
}

void selectionSort(int v[], int n)
{
	int k = 0;
	while (k < n)
	{
		int i = k, m = i, aux = NULL;
		while (i < n)
		{
			if (v[i] > v[m])
				m = i;
			i++;
		}
		aux = v[k];
		v[k] = v[m];
		v[m] = aux;
		k++;
	}
}

void classificar(int v[], int n, int k)
{
	selectionSort(v, n);
	int val_ref = v[k - 1], empate = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (i > (k - 1) && val_ref == v[i])
			empate++;
	}
	
	k += empate;
	
	printf("%d\n", k);	
}

