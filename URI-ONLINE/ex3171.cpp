#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
	int nro_vertices;
	int** arestas;
	int* grau;
}tipo_grafo;


tipo_grafo *criaGrafo(int n);
void insereAresta(tipo_grafo *G, int x, int y);
void bfs(tipo_grafo *G, int ini, int *visitado);
void completo(int v, int *visitado);


int main()
{
	int v, e;

	scanf("%d %d", &v, &e);
	
	tipo_grafo *G = criaGrafo(v);
	
	for (int i = 0; i < e; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		insereAresta(G, x - 1, y - 1);
	}

	int vis[v];
	
	bfs(G, 0, vis);
	completo(v, vis);
	
	return 0;
}

tipo_grafo *criaGrafo(int n)
{
	tipo_grafo *G = (tipo_grafo*) malloc(sizeof(tipo_grafo));
	
	if (G != NULL)
	{
		int i;
		
		G->nro_vertices = n;
		G->grau = (int*) calloc(n, sizeof(int));
		G->arestas = (int**) malloc(n * sizeof(int*));
		
		for (i = 0; i < n; i++)
		{
			G->arestas[i] = (int*) malloc(n * sizeof(int));
		}
	}
	
	return G;
}

void insereAresta(tipo_grafo *G, int x, int y)
{
	G->arestas[x][G->grau[x]] = y;
	G->grau[x]++;
	
	G->arestas[y][G->grau[y]] = x;
	G->grau[y]++;
}

void bfs(tipo_grafo *G, int ini, int *visitado)
{
	int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
	
	for (i = 0; i < G->nro_vertices; i++)
		visitado[i] = 0;
	
	NV = G->nro_vertices;
	fila = (int*) malloc(NV * sizeof(int));
	FF++;
	fila[FF] = ini;
	visitado[ini] = cont;
	
	while (IF != FF)
	{
		IF = (IF + 1) % NV;
		vert = fila[IF];
		cont++;
		
		for (i = 0; i < G->grau[vert]; i++)
		{
			if (!visitado[G->arestas[vert][i]])
			{
				FF = (FF + 1) % NV;
				fila[FF] = G->arestas[vert][i];
				visitado[G->arestas[vert][i]] = cont;
			}
		}
	}
	free(fila);
}

void completo(int v, int *visitado)
{
	int i, correct = 0;
	
	for (i = 0; i < v; i++)
		if (visitado[i] == 0)
			correct = 1;	
	
	if (correct == 0)
		printf("COMPLETO\n");
	else
		printf("INCOMPLETO\n");
}

