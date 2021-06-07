#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
	int numVertice;
	int **matriz_adj;
}tipo_grafo;

tipo_grafo *criaGrafo(int nVert)
{
	int lin, col;
	
	tipo_grafo *G = (tipo_grafo *) malloc(sizeof(tipo_grafo));
	G->numVertice = nVert;
	
	G->matriz_adj = (int **) malloc(nVert * sizeof(int *));
	
	for (lin = 0; lin < nVert; lin++)
		G->matriz_adj[lin] = (int *) malloc(nVert * sizeof(int));
	
	for (lin = 0; lin < nVert; lin++)
		for (col = 0; col < nVert; col++)
			G->matriz_adj[lin][col] = 0;
	
	return G;	
}

void addAresta(tipo_grafo *G, int origem, int destino, int peso)
{
	G->matriz_adj[origem][destino] = peso;
	G->matriz_adj[destino][origem] = peso;
}

void removeAresta(tipo_grafo *G, int origem, int destino)
{
	G->matriz_adj[origem][destino] = 0;
	G->matriz_adj[destino][origem] = 0;
}

tipo_grafo *liberaGrafo(tipo_grafo *G)
{
	if (G)
	{
		for (int lin = 0; lin < G->	numVertice; lin++)
			free(G->matriz_adj[lin]);
		free(G->matriz_adj);
		
		free(G);
	}
	return NULL;
}

void mostraGrafo(tipo_grafo *G)
{
	int lin, col;
	
	printf("\n Mostrando a matriz de adj do grafo\n   ");
	
	for (lin = 0; lin < G->numVertice; lin++)
		printf("%d ", lin);
	
	printf("\n");
	
	for (lin = 0; lin < G->numVertice; lin++)
	{
		printf("%d ", lin);
		for (col = 0; col < G->numVertice; col++)
			printf(" %d", G->matriz_adj[lin][col]);
		
		printf("\n");
	}
}

int main()
{
	tipo_grafo *G = criaGrafo(4);
	
	addAresta(G, 1, 2, 1);
	addAresta(G, 3, 1, 1);
	removeAresta(G, 2, 1);
	
	mostraGrafo(G);
	
	G = liberaGrafo(G);
	
	return 0;
}
