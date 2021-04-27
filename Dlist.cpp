#pragma warning(disable:4996)
#include "Dllist.h"
#include<string.h>


// initialization of root
 node* initialize(char *data) {
	node* head;

	head = (node*)malloc(sizeof(node));

	head->data = (char*)malloc(strlen(data) * sizeof(char));

	strcpy(head->data, data);
	head->next = NULL;           
	head->prev = NULL;
	

	return head;
}

//Adding new elem

 node* ADD(node* lst, char *number)
{
	node* temp;
	temp = (struct node*)malloc(sizeof(node));

	temp->data = (char*)malloc(strlen(number) * sizeof(char));
	lst->next = temp; // предыдущий узел указывает на создаваемый
	strcpy(temp->data, number);// сохранение поля данных добавляемого узла
	temp->next = NULL; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	return(temp);
}

node* DEL(node* current) {
	node* next, * prev;

	prev = current->prev;
	next = current->next;

	if (prev != NULL)prev->next = current->next;
	if (next != NULL)next->prev = current->prev;

	free(current);

	return prev;
}

//deleting of the root
node* DELROOT(node* head)
{
	node* next_after_head;

	next_after_head = head->next;
	next_after_head->prev = NULL;

	free(head);

	return next_after_head;
}

unsigned COUNT_ELEMENT(node* head) 
{
	int COUNTER = 0;

	node* temp = head;

	while (temp!= NULL) {
		if (temp != NULL)
		{
			COUNTER++;
			if (temp->next == nullptr)temp = temp->next;
			else { break; }
		}
	}
	return COUNTER;
}

void TRAVERSAL_FORWARD(node* head)  
{
	node* element = head;
	int counter = COUNT_ELEMENT(head);
	if(element != NULL)
	{

		for (int i = 0; i < counter; i++)
		{
			printf("%s \n", element->data);
			if(element->next != nullptr)
				element = element->next;
		}

	}
}
void TRAVERSAL_BACKWARD(node* tail)
{
	node* element = tail;
	if (element != NULL)
	{
		while (element= NULL)
		{
			printf(element->data);

			element = element->prev;
		}
	}
}

node* FIND(char* elem_data, node* head)
{
	node* element = head;
	if (element != NULL)
	{
		while (element != NULL)
		{
			
			if (strcmp(element->data,elem_data)==0)
				return element;

			element = element->next;
		}
		return NULL;
	}
}

void EXTRACTION(char* del_elem_data,node* head)
{
	if (FIND(del_elem_data, head)->prev == NULL)DELROOT(head);
	else {
		DEL(FIND(del_elem_data, head));
	}
		printf("Deleted %s completly", del_elem_data);
}

void REMOVING_DUPLICATE(node* head)
{// не должно быть удаления корня 
// должно оставлять нетронутым 1 элемент , если их больше 1 повторяющегося!
	int counter = COUNT_ELEMENT(head);

	if (counter >= 2)
	{
		node* tmp = head;

		for (size_t i = 0; i < counter + 1; i++)
		{
			tmp = head;


			for (size_t i = 0; i < counter - 1; i++)
			{
				if (tmp->next != nullptr)
				{
					if (strcmp(tmp->data, tmp->next->data) == 0)
					{
						
						node* both_to_die = tmp;
						if (both_to_die->prev == nullptr)
						{
							head = DELROOT(both_to_die);

							tmp = head;
						}
						else{
							tmp = tmp->next;
							DEL(both_to_die);
						}


					}
					else{ tmp = tmp->next; }
					

				}

			}
		}
	}
}

//swap with pointers and data

/*void SWAP(node* lhv, node* rhv)
{
	lhv->prev->next = rhv;
	rhv->next->prev = lhv;

	node* temp = rhv;

	rhv = lhv;
	rhv->next = lhv;

	lhv = temp;
	lhv->prev = rhv;
}
*/

void SWAP(node* lhv, node* rhv)
{
	char *tmp = lhv->data;

	lhv->data = rhv->data;

	rhv->data = tmp;
}
  
node* GETTAIL(node* head)
{
	node* temp = head;

	while (temp->next != NULL )
	{
		temp = temp->next;
	}
	return temp;

}

void BUBBLE_SORT(node* head) {

	int counter = COUNT_ELEMENT(head);

	if (counter >= 2)
	{
		node* tmp = head;

		for (size_t i = 0; i < counter + 1; i++)
		{
			tmp = head;


			for (size_t i = 0; i < counter - 1; i++)
			{
				if(tmp->next != nullptr)
				{
					if (strcmp(tmp->data, tmp->next->data) > 0)
					{
						SWAP(tmp,tmp->next);
					
					}
					tmp = tmp->next;

				}
				
			}
		}
	}
}

node* READING_FROM_FILE(node* head, char* file_name)
{
	FILE* file_r;

	int Is_node_already_exist = 1;

	printf("Is head already exist: 1 - yes, 0 - no \n");

	scanf("%d", &Is_node_already_exist);

	char seps[] = " ,";
	
	char* token = NULL;

	char buffer[1024];

	node* head_in = nullptr;
	
	node* last = nullptr;
	//Система токенов : токен - следующий символ *(вернее указатель на него) , который потом передается в строку 
	if (Is_node_already_exist == 1)
	{
		last = GETTAIL(head);
	}

	file_r = fopen( file_name, "r");

	if (file_r != NULL)
	{
		printf("File was opened successfully!");

		char* splited_str = strtok_s(buffer, seps, &token);

		while (fgets(buffer, 1024, file_r) != NULL)
		{
			while (splited_str != NULL)
			{
				if (!Is_node_already_exist)
				{
					head_in = initialize(splited_str);

					last = head_in;
				}
				else {
					last = ADD(last, splited_str);
				}
				if(token != NULL)
					splited_str = strtok_s(NULL, seps, &token);	
			}
		}
		fclose(file_r);
	}
	return head_in;
}

void WRITING_TO_FILE(node* container_head, char* file_name) {

	FILE* F1;

	F1 = fopen(file_name, "w");

	node* tmp = container_head;

	if (F1 != NULL)
	{
		printf("File was opened successfully!");

		while (tmp != NULL)
		{
			fputs(tmp->data, F1);

			fputs("\n", F1);

			tmp = tmp->next;
		}
		fclose(F1);

	}
	else {
		printf("File wasn't opened correctly!");
	}
}
