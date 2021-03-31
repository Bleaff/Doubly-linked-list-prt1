#include"Dllist.h"
#include<conio.h>
#include<stdio.h> //Для printf
#include<cstring>
#include<string.h> // Для strlen





int main()
{
    node* head;

    char buffer[128];

    char* token;

    char seps[] = " ,";

    printf("HELP: \n 1.Type: 'create data'  where 'data' some string \n 2.Type:'add data' to add new element with parameter data \n 3.Type:'sort' to sort doubly linked list  \n 4.Type: 'delete data' where 'data' is the element with such parameter \n 5.Type 'delete root' to delete root \n6.Type:'count element' to see how many element already exist \n 7.Type:'itforward' or 'itbackward' to print items forward or backward \n 8.Type: 'delete list' to delete all list \n 9.Type:'remove duplicate' to remove duplicate \n 10.Type:'read file_path' to read list from file with name = file_path' \n 11.Type:'write file_name' to write to file with name file_name");

    int number_of_command;

    printf("Enter the amount of command :");

    if (scanf("%d", &number_of_command) != NULL)
    {
        for (size_t i = 0; i < number_of_command; i++)
        {

        }

    }

   

	
    return 0;
}