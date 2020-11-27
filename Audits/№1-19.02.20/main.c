/*1.В файле input.txt записано кол - во комплексных чисел, затем записаны сами числа.
Считать эти комплексные числа из файла, вывести в консоль в виде a + bi.
Вывести число максимальное по модулю.

Пример: input.txt
2
1 3   // 1+3i
- 1 9  //-1+9i

вывод :
	1 + 3i
	- 1 + 9i
	max = -1 + 9i // т.к. оно больше по модулю
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#define _CRT_SECURE_NO_WARNINGS
/*struct compl_num {
	int a;
	int b;
	int sum;
};
int main() {
	setlocale(LC_ALL, "RUS");
     	int count = 0;
		int j = 0;
		struct compl_num* nums;
		FILE* input;
		fopen_s(&input, "D:\\Аудиторные_1-13\\№1-19.02.20\\Aud -N1\\input.txt", "r");
		if (input == NULL)
		{
			perror("Ошибка открытия файла");
			return 3;
		}
		fscanf_s(input, "%d", &count);
		nums = (struct compl_num*)malloc(count * sizeof(struct compl_num));
		for (int i = 0; i < count; i = i + 1)
		{
			fscanf_s(input, "%d", &nums[i].a);
			fscanf_s(input, "%d", &nums[i].b);
		}
		fclose(input);
		for (int i = 0; i < count; i = i + 1)
		{
			printf("%d", nums[i].a);
			if (nums[i].b > 0)
				printf(" + %di\n", nums[i].b);
			else
				printf(" %di\n", nums[i].b);
		}
		for (int i = 0; i < count; i = i + 1)
		{
			nums[i].sum = pow(nums[i].a, 2) + pow(nums[i].b, 2);
		}
		for (int i = 1; i < count; i = i + 1)
		{
			if (nums[i - 1].sum < nums[i].sum)
				j = i;
		}
		if (nums[j].b > 0)
			printf("\nmax = %d + %di\n", nums[j].a, nums[j].b);
		else
			printf("\nmax = %d %di\n", nums[j].a, nums[j].b);
			free(nums);
		system("pause");
		return 0;
	}
	*/
	/*2.Реализовать безопасный ввод пароля в консоль(отображение звёздочек вместо печатаемых символов).
	Пример SafePasswordInput_Example.exe*/
/*int main() {
	setlocale(LC_ALL, "RUS");
	char* password;
	char buf[255];
	char c = { " " };
	int count = 0;	for (int i = 0; i < 255; i++)
	{
		c = getch();
		if (c != '\r' && c != '\b')
		{
			buf[i] = c;
			printf("*");
			count++;
		}
		else
		{
			if (c == '\r')
				goto end;
			else
			{
				if (i >= 0)
				{
					buf[i] = '\0';
					i = i - 2;
				if(count > 0)
					count--;
					system("cls");
					for (int j = 0; j < count; j++)
						printf("*");
				}
			}
		}
	}
end:
	password = (char*)malloc(count * sizeof(char) + 1);
	printf("\nyou'r password : ");
	for (int i = 0; i < count; i++)
	{
		password[i] = buf[i];
	printf("%c", password[i]);
    }
	printf("\n");
	system("pause");
	return 0;
}*/