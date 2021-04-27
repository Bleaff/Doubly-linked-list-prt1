#pragma warning(disable:4996)

#include"Dllist.h"
#include<conio.h>
#include<stdio.h> //Для printf
#include<cstring>
#include<string.h> // Для strlen

int main()
{
    node* head = nullptr;

    char buffer[128];

    char* token = NULL;

    char seps[] = " ,";

    printf("Firstly complete initialization. To initialize print: '1 data' where 'data' some string  \n");

    printf("HELP: \n 1.Type: '1 data'  where 'data' some string \n 2.Type:  '2 data' to add new element with parameter data \n 3.Type:'3' to sort doubly linked list  \n 4.Type: '4 data' to delete element where 'data' is the element with such parameter \n 5.Type '5' to delete root \n6.Type:'6' to see how many element already exist \n 7.Type:'7' to print items forward . 8.Type '8' to print items backward \n 9.Type: '9' to delete all list \n 10.Type:'10' to remove duplicate \n 11.Type:'11 file_path' to read list from file with name = file_path' \n 12.Type:'12 file_name' to write to file with name file_name. \n 13.Type '0' to STOP. \n");

        while(buffer != "stop")
        {
           gets_s( buffer);

            char* splited_str = strtok_s(buffer, seps, &token);

            while (splited_str != NULL)
            {
                if (strcmp(splited_str, "1") == 0)
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    head = initialize(splited_str);

                    break;
                }
                else if (strcmp(splited_str, "2") == 0)
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    ADD(GETTAIL(head), splited_str);

                    break;
                }
                else if (strcmp(splited_str, "3") == 0)
                {
                    BUBBLE_SORT(head);

                    printf("List has been sorted ! \n");

                    break;
                }
                else if (strcmp(splited_str,"4")==0)
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    DEL(FIND(splited_str, head));
                    printf("Deleted completly \n");
                    break;
 
                }
                else if (strcmp(splited_str, "5")==0)
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);

                        head = DELROOT(head);
                }

                else if (strcmp(splited_str, "6") == 0)
                {
                    splited_str = strtok_s(NULL, seps, &token);
                    printf("The number of the element : %d \n", COUNT_ELEMENT(head));
                }
                else if (strcmp(splited_str, "7") == 0)
                {
                    splited_str = strtok_s(NULL, seps, &token);
                    TRAVERSAL_FORWARD(head);
                }
                else if (strcmp(splited_str, "8") == 0)
                {
                    splited_str = strtok_s(NULL, seps, &token);
                    TRAVERSAL_BACKWARD(head);
                }
                else if (strcmp(splited_str, "9") == 0)
                {
                    splited_str = strtok_s(NULL, seps, &token);

                    for (size_t i = 0; i < COUNT_ELEMENT(head); i++)
                    {
                        if (i == COUNT_ELEMENT(head) - 1)
                            DELROOT(head);

                        else {
                            DEL(GETTAIL(head));
                        }
                    }
                }

                else if (strcmp(splited_str, "10") == 0)
                {
                    splited_str = strtok_s(NULL, seps, &token);

                    REMOVING_DUPLICATE(head);
                }
                else if (strcmp(splited_str, "11") == 0)
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    READING_FROM_FILE(head, splited_str);

                }
                else if (strcmp(splited_str, "12") == 0)
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    WRITING_TO_FILE(head, splited_str);
                }
                else if (strcmp(splited_str, "0") == 0)
                    break;
            }
        }


    return 0;
}