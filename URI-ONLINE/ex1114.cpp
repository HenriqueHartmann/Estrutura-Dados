#include <stdio.h>
/*
	Checa se a senha digitada
	est� correta, caso esteja
	imprime 'Acesso Permitido'
	em caso contr�rio ser�
	exibido 'Senha Invalida' e
	por meio da recurs�o ser�
	necess�rio digitar mais uma
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

