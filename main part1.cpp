#include"Dllist.h"
#include<conio.h>
#include<stdio.h>
#include<cstring>

// перераспределение памяти с константного буферного массива в динамический адаптирующийся
char* GETCHARP(char buffer [128])
{
	int size_of_buffer = std::strlen(buffer);

	char* string = (char*)malloc(size_of_buffer * sizeof(char*));

	strcpy(string, buffer);

	delete buffer;
	
	return string;
}

int main()
{
	return 0;
}