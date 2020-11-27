#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct{
	int age;
	char first_name[40];
	char second_name[25];
}Persons;
int main() {
	setlocale(LC_ALL, "RUS");
	int count = 0;
	FILE* per;
	Persons* persons;
	int big_man = 0;
	char text[52] = { "\0" };
	fopen_s(&per, "D:\\Аудиторные_1-13\\№2-26.02.20\\persons.txt", "r+");
	if (per == NULL)
	{
		perror("Ошибка открытия файла");
		return 3;
	}
	fscanf_s(per, "%d", &count);
	persons = (Persons*)malloc(count * sizeof(Persons));
	while (!(feof(per)))
		fgets(text[52], 51, per);
	for (int i = 0; i < count; i++)
	{
		if (big_man < persons[i].age)
			big_man = i;
	}
	printf("Самый долгожитель - %s %s - %d лет", persons[big_man].first_name, persons[big_man].second_name, persons[big_man].age);
	fclose(per);
	free(persons);
	system("pause");
	return 0;
}
/*#define SIZE 45

int main() {
	setlocale(LC_ALL, "Rus"); 
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	FILE* f;
	fopen_s(&f, "D:\\Аудиторные_1-13\\№2-26.02.20\\persons.txt", "r");
	if (f == NULL)
	{
		perror("Ошибка открытия файла");
		return 3;
	}
	unsigned int N = 10, delta = 10, i = 0;
	char* buf = (char*)malloc(sizeof(char) * N);
	while ((buf[i] = fgetc(f)) != EOF) { 
		if (++i >= N) {
			N += delta;
			buf = (char*)realloc(buf, sizeof(char) * N);
		}
	}
	fclose(f);
	buf[i] = '\0';
	puts(buf);
	free(buf);
	return 0;
}*/