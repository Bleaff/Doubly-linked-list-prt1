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

    printf("HELP: \n 1.Type: 'create data'  where 'data' some string \n 2.Type:'add data' to add new element with parameter data \n 3.Type:'sort' to sort doubly linked list  \n 4.Type: 'delete data' where 'data' is the element with such parameter \n 5.Type 'delete root' to delete root \n6.Type:'count element' to see how many element already exist \n 7.Type:'itforward' or 'itbackward' to print items forward or backward \n 8.Type: 'delete list' to delete all list \n 9.Type:'remove duplicate' to remove duplicate \n 10.Type:'read file_path' to read list from file with name = file_path' \n 11.Type:'write file_name' to write to file with name file_name. \n");



    {
        while(buffer != "stop")
        {
            scanf("%s", buffer);

            char* splited_str = strtok_s(buffer, seps, &token);

            while (splited_str != NULL)
            {
                if (splited_str == "create")
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    head = initialize(splited_str);

                    break;
                }
                else if (splited_str == "add")
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    GETTAIL(head)->next = ADD(GETTAIL(head), splited_str);

                    break;
                }
                else if (splited_str == "sort")
                {
                    BUBBLE_SORT(head);

                    printf("List has been sorted ! \n");

                    break;
                }
                else if (splited_str == "delete")
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);

                    if (splited_str == "root")
                        head = DELROOT(head);

                    else if (splited_str == "list")
                    {
                        for (size_t i = 0; i < COUNT_ELEMENT(head); i++)
                        {
                            if (i == COUNT_ELEMENT(head) - 1)
                                DELROOT(head);

                            else {
                                DEL(GETTAIL(head));
                            }
                        }
                    }

                    else {
                        DEL(FIND(splited_str, head));

                        printf("Deleted completly \n");
                    }
                    break;
                }

                else if (splited_str == "count")
                {
                    printf("The number of the element : %d \n", COUNT_ELEMENT(head));
                }
                else if (splited_str == "itforward")
                {
                    TRAVERSAL_FORWARD(head);
                }
                else if (splited_str == "itbackward")
                {
                    TRAVERSAL_BACKWARD(head);
                }
                else if (splited_str == "remove")
                {
                    REMOVING_DUPLICATE(head);
                }
                else if (splited_str == "read")
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    READING_FROM_FILE(head, splited_str);

                }
                else if (splited_str == "write")
                {
                    if (token != NULL)
                        splited_str = strtok_s(NULL, seps, &token);
                    WRITING_TO_FILE(head, splited_str);
                }
                else if (splited_str == "stop")
                    break;
            }
        }

    }


    return 0;
}