#pragma once
#include "Dllist.h"

typedef struct node {
	char *data;
	node* prev;
	node* next;
}node;

// initialization of root
 node* initialize(char *data) {
	node* head;

	head = (node*)malloc(sizeof(node));

	head->data = data;
	head->next = NULL;           
	head->prev = NULL;
	

	return head;
}

//Adding new elem

 node* ADD(node* lst, char *number)
{
	node* temp, * p;
	temp = (struct node*)malloc(sizeof(node));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->data = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}

node* DEL(node* current) {
	node* next, * prev;

	prev = current->prev;
	next = current->next;

	if (prev != NULL)prev->next = current->next;
	if (next != NULL)next->prev = current->prev;

	delete[] current->data;
	free(current);

	return prev;
}

//deleting of the root
node* DELROOT(node* head)
{
	node* next_after_head;

	next_after_head = head->next;
	next_after_head->prev = NULL;

	delete[] head->data;
	free(head);

	return next_after_head;
}

unsigned COUNT_ELEMENT( node* head) 
{
	int COUNTER = 1;

	node* temp = head;

	while (temp!= NULL) {
		if (temp != NULL)
		{
			COUNTER++;
			temp = temp->next;
		}
	}
	return COUNTER;
}

void TRAVERSAL_FORWARD(node* head)  
{
	node* element = head;
	if(element != NULL)
	{
		while (element!= NULL)
		{
			printf(element->data);

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
			
			if (element->data == elem_data)
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
{
	node* lhv = head;
	
	if (lhv->next != NULL)
	{
		node* rhv = lhv->next;

		while (lhv != NULL)
		{

			while (rhv != NULL)
			{

				if (lhv->data == rhv->data)//условие схожести элементов
				{
					DEL(rhv);
				}
				rhv = rhv->next;

			}

			lhv = lhv->next;
		}
	}

}

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

	while (temp->next != NULL)
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

		for (size_t i = 0; i < counter; i++)
		{


			for (size_t i = 0; i < counter - 1; i++)
			{
				if (tmp->data > tmp->next->data)
				{
					SWAP(FIND(tmp->data, head), FIND(tmp->next->data, head));
				}
				tmp = tmp->next;
			}
		}
	}
}

node* READING_FROM_FILE(node* head, char* file_name)
{
	FILE* file_r;

	int Is_node_already_exist = 1;

	printf("Is head already exist: 1 - yes, 0 - no \n");

	scanf("%d", Is_node_already_exist);

	char seps[] = " ,";
	
	char* token = NULL;

	char buffer[1024];

	node* head_in;
	
	node* last;

	if (Is_node_already_exist == 1)
	{
		last = GETTAIL(head);
	}

	file_r = fopen( file_name, "r");

	if (file_r != NULL)
	{
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
	}

	fclose(file_r);

	return head_in;
}
