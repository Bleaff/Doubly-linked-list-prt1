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
		while (element->next != NULL)
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
		while (element->prev != NULL)
		{
			printf(element->data);

			element = element->prev;
		}
	}
}



