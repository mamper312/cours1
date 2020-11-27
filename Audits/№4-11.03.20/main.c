#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<math.h>

#define pi 3.14
/*1.Реализовать односвязный список вещественных чисел, реализовать функции:
addRandomValue - добавление рандомного вещественного числа в список
outputList - вывод списка чисел в консоль
addBeforeValue(double value) - добавление рандомного числа перед числом value в списке, если числа value в списке нет - сообщить об этом пользователю
find(double value) - поиск первого вхождения value в списке
count(double value) - подсчёт числа вхождений value в списке*/

typedef struct Node {
	double value;
	struct Node* next;
}List;

List* create(double data)
{
	List* tmp = (List*)malloc(sizeof(List));
		tmp->value = data;
		tmp->next = NULL;
	return(tmp);
}

void addRandomValue(List* head)
{
	while (head->next != NULL)
		head = head->next;
	head->next = create((double)(rand() % 10) + (double)rand() / RAND_MAX);
}

void outputList(List *head)
{
	List* tmp = head, * p = NULL;
	while (tmp != NULL)
	{
		printf(" %.3lf ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

List* addBeforeValue(double data, List* head)
{
	List* p = head;
	List* tmp = NULL;
	int count = 0;
	while (p->next != NULL)
	{
		if (p->next->value == data)
		{
			tmp = p->next;
			p->next = create(-1);
			p->next->next = tmp;
			return(head);
		}
		else
		{
			p = p->next;
			if (p->next == NULL)
			{
				printf("Tmp not have num\n");
				return(head);
			}
		}
	}
}

void find(double skate, List* head)
{
	List* p = head;
	int count = 1;
	while (p != NULL)
	{
		if (p->value == skate)
			break;
	p = p->next;
	count++;
	}
	printf("Pervoe vhozhdenia = %d\n", count);
}

void count(double skate, List* head)
{
	List* p = head;
	int count = 0;
	while (p != NULL)
	{
		if (p->value == skate)
			count++;
		p = p->next;
	}
	printf("Chislo vhozhdenii = %d\n", count);
}

/*int main() {
	srand(time(NULL));
	List* tmp;
	tmp = create(10);
	tmp->next = create(5);
	tmp->next->next = create(93);
	tmp->next->next->next = create(93);
	find(93,tmp);
	for(int i = 0; i < 10; i++)
		addRandomValue(tmp);
	outputList(tmp);
  	addBeforeValue(6, tmp);
	outputList(tmp);
	count(93, tmp);
	system("pause");
	return 0;
}
*/

//2.https://acm.timus.ru/problem.aspx?space=1&num=1084

int main()
{
	double length = 0;
	double r = 0;
	scanf_s("%lf", &length);
	scanf_s("%lf", &r);
	if (r <= length / 2)
		printf("S = %.3lf", (double)(pi * r * r));
	else
		if (sqrt(2) * length / 2 <= r)
			printf("S = %.3lf", (double)(length * length));
		else
			printf("S = %.3lf", (((pi * r * r) - (4 * acos(length / r / 2) * r * r)) + (2 * length * sqrt(r * r - length * length / 4))));
}

