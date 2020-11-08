#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>

#define CRT_SECURE_NO_WARNINGS

/*
typedef struct Snow {
	int x;
	int y;
}Snows;

int main() {
	srand(time(NULL));
	Snows *sneg;
	sneg = (Snows*)malloc(5 * sizeof(Snows));
    for (int i = 0; i < 5; i++)
	{
		sneg[i].x = rand() % 125 + 2;
		sneg[i].y = rand() % 6 + 2;
	}
xy:
	for (int g = 0; g < 5; g++)
	{
		for (int i = 0; i < (sneg[g].y - 1); i++)
		{
			printf("\n");
		}
		for (int j = 0; j < (sneg[g].x - 1); j++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
		for (int j = 0; j < (sneg[g].x - 2); j++)
		{
			printf(" ");
		}
		printf("***");
		printf("\n");
		for (int j = 0; j < (sneg[g].x - 1); j++)
		{
			printf(" ");
		}
		printf("*");
		printf("\n");
		for(int i = 0; i < sneg[g].x ; i++)
		printf("\b");
		for (int i = 0; i < (sneg[g].y + 1); i++)
			printf("\r");
	}
	printf("\n");
	for (int g = 0; g < 5; g++) 
	{
		sneg[g].x = sneg[g].x + rand() % 3 - 1;
		sneg[g].y = sneg[g].y +rand() % 3 - 1;
	}
	Sleep(1000);
	system("cls");
	goto xy;
	system("pause");
	return 0;
}
*/

int SearchEasy(int n)
{
	int count = 1;
	int prost = 1;
	xy:
	if (count == n)
	{
		count = 1;
		return prost;
		prost = 1;
	}
	else
	{
		prost = prost + 2;
		for (int i = 2; i < (prost / 2); i++)
		{
			if (prost % i == 0)
			{
				goto xy;
			}
		}
		count++;
	}
	goto xy;
}


int main() {
	int n = 0;
	int count = 1;
	int num = 1;
	int k = 2;
	int* mass;
	FILE* in;
	fopen_s(&in, "D:\\1 курс\\Аудиторные_1-13\\№5-18.03.20\\input.txt", "r+");
	if (in == 0)
		return 3;
	fscanf_s(in, "%d", &n);
	mass = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		fscanf_s(in, "%d", &mass[i]);
	}
	fclose(in);

	for (int i = 0; i < n; i++)
	{
		num = SearchEasy(mass[i]);
		printf("%d ------ %d\n", mass[i], num);
	}
		free(mass);
	system("pause");
	return 0;
}