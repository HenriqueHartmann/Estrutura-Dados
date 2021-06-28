#include <stdio.h>
/*
	Checa se a senha digitada
	está correta, caso esteja
	imprime 'Acesso Permitido'
	em caso contrário será
	exibido 'Senha Invalida' e
	por meio da recursão será
	necessário digitar mais uma
	vez a senha.
*/
void checkPassword();

int main()
{
	checkPassword();
	
	return 0;
}

void checkPassword()
{
	int password;
	scanf("%d", &password);
	
	if (password == 2002)
	{
		printf("Acesso Permitido\n");
	}
	else
	{
		printf("Senha Invalida\n");
		checkPassword();	
	}
}

