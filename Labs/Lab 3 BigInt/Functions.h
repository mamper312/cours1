#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Node {
	char num1[256];
	int* mass1;
	char num2[256];
	int* mass2;
}Big_Int;

void plus(Big_Int tgk, int length1, int length2);

void multiply(Big_Int tgk, int length1, int length2);

void minus(Big_Int tgk, int length1, int length2);


void division(Big_Int tgk, int length1, int length2);

void function(Big_Int tgk, int leng1, int leng2);

void free_nums(Big_Int tgk);
#endif /* FUNCTIONS_H*/