#include <stdio.h>

int main(void)
{
	int hora_i, min_i, hora_f, min_f;
	
	scanf("%d %d %d %d", &hora_i, &min_i, &hora_f, &min_f);	
	
	int hora_t = hora_f - hora_i;
	int min_t = min_f - min_i;
	
	if (hora_t < 0)
	{
		hora_t += 24;
	}
	
	if (hora_t == 0)
	{
		if (min_t > 0)
		{
			hora_t = 0;
		}
		else
		{
			hora_t = 24;	
		}
	}
	//printf("%d %d", hora_t, min_t);
	
	if (min_t < 0)
	{
		min_t += 60;
		if (hora_t > 0)
		{
			hora_t -= 1;
		}
	}
	
	if (hora_i == hora_f && min_i == min_f)
	{
		hora_t = 24;
		min_t = 0;
	}
	
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hora_t, min_t);
	
	return 0;
}
