/*Хранить длинные целые числа в своей структуре BigInt.
Реализовать сложение, вычитание, умножение, деление длинных чисел.

Пример:
	в файле 1.txt находится 
99999999999999999999999999999999999999999999999999999
	в файле 2.txt находится 
1

результат сложения:
100000000000000000000000000000000000000000000000000000
результат вычитания:
99999999999999999999999999999999999999999999999999998
результат умножения:
99999999999999999999999999999999999999999999999999999
результат деления:
99999999999999999999999999999999999999999999999999999

Предусмотреть возможность ввода данных с консоли, с файла, параметрами main.
Пример реализации: example.exe*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Functions.h"

int main(int argc, char* argv[]) {
	int length1 = 0;
	int length2 = 0;
	int Enter = 0;
	char* garage;
	printf("1 - console \n 2 - from file\n  3 - arguments\n");
	scanf_s("%d", &Enter);
	char skip;
	scanf_s("%c", &skip);
	Big_Int tgk;
	if (Enter != 1 && Enter != 2 && Enter != 3)
	{
		printf("incorect symbol\n");
		return 0;
	}
	switch (Enter)
	{
	case(1):
	{
		printf("First number :\n");
		gets(tgk.num1);
		length1 = strlen(tgk.num1);
		tgk.mass1 = calloc(length1, sizeof(int));;
		for (int i = 0; i < length1; i++)
		{
			tgk.mass1[i] = tgk.num1[i] - '0';
		}
		printf("Second number : \n");
		gets(tgk.num2);
		length2 = strlen(tgk.num2);
		tgk.mass2 = calloc(length2, sizeof(int));
		for (int i = 0; i < length2; i++)
		{
			tgk.mass2[i] = tgk.num2[i] - '0';
		}
		printf("\n");
		function(tgk, length1, length2);
		break;
	}
		case(2):
	{
			FILE* input;
			fopen_s(&input, "input.txt", "r");
			char num = NULL;
			if (input == NULL)
				return 0;
			while ((num = fgetc(input)) != '\n')
			{
				length1++;
				if (input == EOF)
					return 3;
			}
			while ((num = fgetc(input)) != EOF)
				length2++;
			tgk.mass1 = calloc(length1, sizeof(int));
			tgk.mass2 = calloc(length2, sizeof(int));
			fclose(input);
			fopen_s(&input, "input.txt", "r");
			if (input == NULL)
				return 0;
			for (int i = 0; i < length1; i++)
			{
				tgk.num1[i] = fgetc(input);
				tgk.mass1[i] = tgk.num1[i] - '0';
			}
			num = fgetc(input);
			for (int i = 0; i < length2; i++)
			{
				tgk.num2[i] = fgetc(input);
				tgk.mass2[i] = tgk.num2[i] - '0';
			}
			fclose(input);
			printf("\nFirst number : \n");
			for (int i = 0; i < length1; i++)
				printf("%d", tgk.mass1[i]);
			printf("\nSecond number : \n");
			for (int i = 0; i < length2; i++)
				printf("%d", tgk.mass2[i]);
			printf("\n");
			function(tgk, length1, length2);
			break;
	}
		case(3):
			garage = argv[1];
			for (int i = 0; i <= strlen(garage); i++)
				tgk.num1[i] = garage[i];
			printf("First number :\n");
			length1 = strlen(tgk.num1);
			tgk.mass1 = calloc(length1, sizeof(int));;
			for (int i = 0; i < length1; i++)
			{
				tgk.mass1[i] = tgk.num1[i] - '0';
				printf("%d", tgk.mass1[i]);
			}
			garage = argv[2];
			for (int i = 0; i <= strlen(garage); i++)
				tgk.num2[i] = garage[i];
			printf("\nSecond number : \n");
			length2 = strlen(tgk.num2);
			tgk.mass2 = calloc(length2, sizeof(int));
			for (int i = 0; i < length2; i++)
			{
				tgk.mass2[i] = tgk.num2[i] - '0';
				printf("%d", tgk.mass2[i]);
			}
			printf("\n");
			function(tgk, length1, length2);
			break;
	}
	free_nums(tgk);
	printf("\n");
	system("pause");
	return 0;
}