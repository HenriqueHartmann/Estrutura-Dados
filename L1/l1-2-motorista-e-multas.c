#include <stdio.h>

/*
	Aluno: Henrique Luiz Hartmann
	Turma: BSI4
*/

void registrarCarteira (int *pcarteira)
{
	int valor;
	printf("\nDigite o numero da carteira: ");
	scanf("%d", &valor);
	*pcarteira = valor;
}

int main (void)
{
	int carteira;
	float recursos_arrecadados;
	int carteira_maior_numero_multas = 0;
	int qtd_multas;
	
	registrarCarteira(&carteira);
	
	while (carteira != 0)
	{
		int numero_multas = 0;
		float valor_multa = 0;
		float divida = 0;
		int i = 0;
		
		printf("Digite o numero de multas: ");
		scanf("%d", &numero_multas);
		
		while (i < numero_multas)
		{
			printf("\nDigite o valor da multa numero %d: R$", (i + 1));
			scanf("%f", &valor_multa);
			divida += valor_multa;
			i++;
		}
		
		recursos_arrecadados += divida;
		
		if (qtd_multas < numero_multas)
		{
			carteira_maior_numero_multas = carteira;
			qtd_multas = numero_multas;
		}
		
		printf("MOTORISTA:\nCarteira: %d\nDivida: R$%f \n", carteira, divida);
		
		registrarCarteira(&carteira);
	}
	
	if (carteira_maior_numero_multas != 0)
	{
		printf("\nRecursos Arrecadados: R$%f\nMaior Numero de Multas:\n MOTORISTA:\n Carteira: %d com %d multas", recursos_arrecadados, carteira_maior_numero_multas, qtd_multas);	
	}
	else
	{
		printf("\nNenhum Motorista Cadastrado!");
	}	
	
	return 0;
}

