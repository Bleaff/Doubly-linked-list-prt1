#include"Dllist.h"
#include<conio.h>
#include<stdio.h> //Для printf
#include<cstring>
#include<string.h> // Для strlen

// перераспределение памяти с константного буферного массива в динамический адаптирующийся
char* GETCHARP(char buffer [128])
{
	int size_of_buffer = strlen(buffer);

	char* string = (char*)malloc(size_of_buffer * sizeof(char*));

	strcpy(string, buffer);

	delete buffer;
	
	return string;
}

int main()
{

	return 0;
}