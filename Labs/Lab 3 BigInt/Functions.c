#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Functions.h"

void plus(Big_Int tgk, int length1, int length2)
{
	int count = 0;
	int* mass_sum;
	if (length1 >= length2)
	{
		mass_sum = calloc((length1 + 1), sizeof(int));

		for (int i = 0; i < length1; i++)
			if (i < length2)
			{
				mass_sum[i] = mass_sum[i] + tgk.mass1[length1 - i - 1] + tgk.mass2[length2 - i - 1];

				if (mass_sum[i] > 9)
				{
					mass_sum[i] = mass_sum[i] % 10;
					mass_sum[i + 1] ++;
				}
			}
			else
			{
				mass_sum[i] = mass_sum[i] + tgk.mass1[length1 - i - 1];
				if (mass_sum[i] > 9)
				{
					mass_sum[i] = mass_sum[i] % 10;
					mass_sum[i + 1] ++;
				}
			}
		for (int i = length1; i >= 0; i--)
			if (mass_sum[i] == 0)
				count++;
			else
				break;
		for (int i = (length1 - count); i >= 0; i--)
		{
			printf("%d", mass_sum[i]);
		}
		free(mass_sum);
		printf("\n");
	}
	else
	{
		mass_sum = calloc((length2 + 1), sizeof(int));

		for (int i = 0; i < length2; i++)
			if (i < length1)
			{
				mass_sum[i] = mass_sum[i] + tgk.mass1[length1 - i - 1] + tgk.mass2[length2 - i - 1];

				if (mass_sum[i] > 9)
				{
					mass_sum[i] = mass_sum[i] % 10;
					mass_sum[i + 1] ++;
				}
			}
			else
			{
				mass_sum[i] = mass_sum[i] + tgk.mass2[length2 - i - 1];
				if (mass_sum[i] > 9)
				{
					mass_sum[i] = mass_sum[i] % 10;
					mass_sum[i + 1] ++;
				}
			}
		for (int i = length1; i >= 0; i--)
			if (mass_sum[i] == 0)
				count++;
			else
				break;
		for (int i = (length1 - count); i >= 0; i--)
		{
			printf("%d", mass_sum[i]);
		}
		free(mass_sum);
		printf("\n");
	}
}

void multiply(Big_Int tgk, int length1, int length2)

{
	int count = 0;
	int* mass_sum;
	mass_sum = (int*)calloc((length1 + length2 + 1), sizeof(int));
	if (length1 >= length2)
	{
		for (int i = 0; i < (length1 + length2 + 1); i++)
			for (int j = 0; j < length1; j++)

				if (i < length2)
				{
					mass_sum[i + j] = mass_sum[i + j] + tgk.mass1[length1 - j - 1] * tgk.mass2[length2 - 1 - i];
					mass_sum[i + j + 1] = mass_sum[i + j] / 10;
					mass_sum[i + j] = mass_sum[i + j] % 10;
				}
	}
	else
	{
		for (int i = 0; i < (length1 + length2 + 1); i++)
			for (int j = 0; j < length2; j++)
				if (i < length1)
				{
					mass_sum[i + j] = mass_sum[i + j] + tgk.mass2[length2 - j - 1] * tgk.mass2[length1 - 1 - i];
					mass_sum[i + j + 1] = mass_sum[i + j] / 10;
					mass_sum[i + j] = mass_sum[i + j] % 10;
				}
	}
	for (int i = (length1 + length2); i >= 0; i--)
		if (mass_sum[i] == 0)
			count++;
		else
			break;
	for (int i = (length1 + length2 - count); i >= 0; i--)
	{
		printf("%d", mass_sum[i]);
	}
	printf("\n");
}

void minus(Big_Int tgk, int length1, int length2)
{
	int count = 0;
	int* mass_sum;
	if (length1 > length2)
	{
		mass_sum = (int*)calloc(length1, sizeof(int));
		for (int i = 0; i < length1; i++)
		{
			if (i < length2)
			{
				if ((tgk.mass1[length1 - i - 1] - tgk.mass2[length2 - i - 1]) < 0)
				{
					tgk.mass1[length1 - i - 1] = tgk.mass1[length1 - i - 1] + 10 - tgk.mass2[length2 - i - 1];
					tgk.mass1[length1 - i - 2] = tgk.mass1[length1 - i - 2] - 1;
				}
				else
					tgk.mass1[length1 - i - 1] = tgk.mass1[length1 - i - 1] - tgk.mass2[length2 - i - 1];
			}
			mass_sum[i] = mass_sum[i] + tgk.mass1[length1 - i - 1];
		}
		for (int i = (length1 - 1); i >= 0; i--)
			if (mass_sum[i] == 0)
				count++;
			else
				break;
		for (int i = (length1 - count - 1); i >= 0; i--)
		{
			printf("%d", mass_sum[i]);
		}
	}
	if (length1 < length2)
	{
		mass_sum = (int*)calloc(length2, sizeof(int));
		for (int i = 0; i < length2; i++)
		{
			if (i < length1)
			{
				if ((tgk.mass2[length2 - i - 1] - tgk.mass1[length1 - i - 1]) < 0)
				{
					tgk.mass2[length2 - i - 1] = tgk.mass2[length2 - i - 1] + 10 - tgk.mass1[length1 - i - 1];
					tgk.mass2[length2 - i - 2] = tgk.mass2[length2 - i - 2] - 1;
				}
				else
					tgk.mass2[length2 - i - 1] = tgk.mass2[length2 - i - 1] - tgk.mass1[length1 - i - 1];
			}
			mass_sum[i] = mass_sum[i] + tgk.mass2[length2 - i - 1];
		}
		for (int i = (length2 - 1); i >= 0; i--)
			if (mass_sum[i] == 0)
				count++;
			else
				break;
		printf("-");
		for (int i = (length2 - count - 1); i >= 0; i--)
		{
			printf("%d", mass_sum[i]);
		}
		count = 0;
	}
	if (length1 == length2)
	{
		count = 0;
		for (int j = 0; j < length1; j++)
		{
			if (tgk.mass1[j] == tgk.mass2[j])
				count++;
		}
		if (count == length1)
		{
			printf("0\n");
			exit;
		}
		count = 0;
		mass_sum = (int*)calloc(length1, sizeof(int));
		for (int j = 0; j < length1; j++)
		{
			if (tgk.mass1[j] > tgk.mass2[j])
			{
				for (int i = 0; i < length1; i++)
				{
					if ((tgk.mass1[length1 - i - 1] - tgk.mass2[length2 - i - 1]) < 0)
					{
						tgk.mass1[length1 - i - 1] = tgk.mass1[length1 - i - 1] + 10 - tgk.mass2[length2 - i - 1];
						tgk.mass1[length1 - i - 2] = tgk.mass1[length1 - i - 2] - 1;
					}
					else
						tgk.mass1[length1 - i - 1] = tgk.mass1[length1 - i - 1] - tgk.mass2[length2 - i - 1];
					mass_sum[i] = mass_sum[i] + tgk.mass1[length1 - i - 1];
				}
				for (int i = (length1 - 1); i >= 0; i--)
					if (mass_sum[i] == 0)
						count++;
					else
						break;
				for (int i = (length1 - count - 1); i >= 0; i--)
				{
					printf("%d", mass_sum[i]);
				}
				break;
				exit;
			}
			if (tgk.mass1[j] < tgk.mass2[j])
			{
				for (int i = 0; i < length2; i++)
				{
					if ((tgk.mass2[length2 - i - 1] - tgk.mass1[length1 - i - 1]) < 0)
					{
						tgk.mass2[length2 - i - 1] = tgk.mass2[length2 - i - 1] + 10 - tgk.mass1[length1 - i - 1];
						tgk.mass2[length2 - i - 2] = tgk.mass2[length2 - i - 2] - 1;
					}
					else
						tgk.mass2[length2 - i - 1] = tgk.mass2[length2 - i - 1] - tgk.mass1[length1 - i - 1];
					mass_sum[i] = mass_sum[i] + tgk.mass2[length2 - i - 1];
				}
				printf("-");
				for (int i = (length2 - 1); i >= 0; i--)
					if (mass_sum[i] == 0)
						count++;
					else
						break;
				for (int i = (length2 - count - 1); i >= 0; i--)
				{
					printf("%d", mass_sum[i]);
				}
				break;
				exit;
			}
		}
	}
}

void division(Big_Int tgk, int length1, int length2)
{
	int count = 0;
	int* mass_sum;
	int otstup = 0;
	int last = 0;
	mass_sum = (int*)calloc(length1, sizeof(int));
	int length3 = length1;
gf:	mass_sum[length3 - 1]++;
	if (length1 >= length2)
	{
	for (int i = 0; i < length2; i++)
	{
		if ((tgk.mass1[length1 - i - 1] - tgk.mass2[length2 - i - 1]) < 0)
		{
			tgk.mass1[length1 - i - 1] = tgk.mass1[length1 - i - 1] + 10 - tgk.mass2[length2 - i - 1];
			tgk.mass1[length1 - i - 2] = tgk.mass1[length1 - i - 2] - 1;
		}
		else
		{
			tgk.mass1[length1 - i - 1] = tgk.mass1[length1 - i - 1] - tgk.mass2[length2 - i - 1];
		}
	}
		for (int i = (length3 - 1); i >= 1; i--)
		{
			mass_sum[i - 1] = mass_sum[i - 1] + (mass_sum[i] / 10);
			mass_sum[i] = mass_sum[i] % 10;
		}
		for (int i = 0; i < length1; i++)
			if (tgk.mass1[i] == 0)
				count++;
			else
				break;
		if (count != length1)
		{
			if (count > 0)
				for (int i = 0; i < (length1 - count); i++)
				{
					tgk.mass1[i] = tgk.mass1[i + count];
				}
			length1 = length1 - count;
			count = 0;
		}
		else
				goto gh;
	}
if (length1 > length2)
{
	goto gf;
}
	if(length1 == length2)
		for (int i = 0; i < length2; i++)
		{
			if (tgk.mass1[i] > tgk.mass2[i])
			{
				goto gf;
			}
			if(tgk.mass1[i] < tgk.mass1[i])
			break;
		}
	for (int i = 0; i < length2; i++)
		if (tgk.mass1[i] == tgk.mass2[i])
		{
			last++;
		}
	if (last == length1)
	{
		last = 0;
		goto gf;
	}
gh:	for (int i = 0; i < length3; i++)
		if (mass_sum[i] == 0)
			otstup++;
		else
			break;
	for (int i = 0; i < (length3 - otstup); i++)
	{
		printf("%d", mass_sum[i + otstup]);
	}
}

void function(Big_Int tgk, int leng1, int leng2)
{
	int count = 0;
	int length1 = leng1;
	int length2 = leng2;
	for (int i = 0; i < length1; i++)
		if (tgk.mass1[i] == 0)
			count++;
		else
			break;
	if (count > 0)
	for (int i = 0; i < (length1 - count); i++)
	{
		tgk.mass1[i] = tgk.mass1[i + count];
	}
	length1 = length1 - count;
	count = 0;
	for (int i = 0; i < length2; i++)
		if (tgk.mass2[i] == 0)
			count++;
		else
			break;
	if(count > 0)
	for (int i = 0; i < (length2 - count); i++)
	{
		tgk.mass2[i] = tgk.mass2[i + count];
	}
	length2 = length2 - count;
	char Enter = NULL;
	printf("Enter operation\n");
	scanf_s("%c", &Enter);
	if (Enter != '+' && Enter != '*' && Enter != '-' && Enter != '/')
	{
		printf("incorect symbol\n");
		return 0;
	}
	switch (Enter)
	{
	case '+':
	{
		plus(tgk, length1, length2);
		break;
	}
	case '*':
	{
		multiply(tgk, length1, length2);
		break;
	}
	case '-':
	{
		minus(tgk, length1, length2);
		break;
	}
	case '/':
	{
		division(tgk, length1, length2);
		break;
	}
	printf("\n");
	}
}

void free_nums(Big_Int tgk)
{
	free(tgk.mass1);
	free(tgk.mass2);
}
