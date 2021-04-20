#include <stdio.h>
#include <stdlib.h>

struct lot {
	char l;
	struct lot* prox;
};

typedef struct lot Lot;

Lot* push (Lot* a, char l);
void pop (Lot** a);
int count (Lot* a);

int main(void)
{
	Lot* arr = NULL;
	arr = push(arr, 'F');
	arr = push(arr, 'A');
	arr = push(arr, 'C');
	arr = push(arr, 'E');
	
	int num, score = 0;
	char t1[2], t2[2], t3[2], t4[2];
	
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		int i2 = 0;
		char l[5];
		Lot* p;
		
		for (p = arr; i2 < 4; p = p->prox)
		{
			l[i2] = p->l;
			i2++;
		}
		
		scanf("%s%s%s%s", t1, t2, t3, t4);
		
		if (t1[0] == l[0] && t2[0] == l[1] && t3[0] == l[2] && t4[0] == l[3])
		{
			pop(&arr);
			pop(&arr);
			pop(&arr);
			pop(&arr);
			
			if (count(arr) == 0)
			{
				arr = push(arr, 'F');
				arr = push(arr, 'A');
				arr = push(arr, 'C');
				arr = push(arr, 'E');
			}
			score++;
		}
		else
		{
			arr = push(arr, t1[0]);
			arr = push(arr, t2[0]);
			arr = push(arr, t3[0]);
			arr = push(arr, t4[0]);
		}
	}
	
	printf("%d\n", score);
	
	return 0;
}

Lot* push (Lot* a, char l)
{
	Lot* novo = (Lot*) malloc(sizeof(Lot));
	novo->l = l;
	novo->prox = a;
	
	return novo;
}

void pop (Lot** a)
{
	Lot* first = *a;
	*a = first->prox;
	free(first);
}

int count (Lot* a)
{
	int count = 0;
	Lot* q;
	for (q = a; q != NULL; q = q->prox)
	{
		count++;
	}
	
	return count;
}

