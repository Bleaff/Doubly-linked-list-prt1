#include"Dllist.h"
#include<conio.h>
#include<stdio.h> //Для printf
#include<cstring>
#include<string.h> // Для strlen

// перераспределение памяти с константного буферного массива в динамический адаптирующийся
char* GETCHARP(char buffer [128])
{
    unsigned int size_of_buffer = strlen(buffer);

    char* string = new char[size_of_buffer];

    strcpy(string, buffer);

    return string;
}

int main()
{

	return 0;
}