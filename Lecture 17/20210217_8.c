/*
Задача 8.
Напишете програма, която да представя Реда на Фибоначи в масив.
Ред на Фибоначи: Всяко число е равно на сумата на двете преди него.
Първите 2 са 0 и 1. 

*/

#include <stdio.h>

long long int array[100];

void putNumbersInArray(int, int);
void print();

int main(void){

	int a = 0, b = 1;
	int (*p)(int, int) = NULL;
	p = &putNumbersInArray;
	int value = (*p)(a,b);
	print();

	return 0;
}

void putNumbersInArray(int a, int b){

	int i = 0;
	array[i++] = a;
	array[i++] = b;

	for(i; i <=100; i++){
		array[i] = a + b;
		a = b;
		b = array[i];
	}
}

void print(){

	int i = 0;

	for(i; i <= 100; i++){
		printf("%lld\n", array[i]);
	}
}
