#pragma once
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char* data;
	node* prev;
	node* next;
}node;

node* initialize(char* data);
//Adding new elem
node* ADD(node* prev, char* data);

node* DEL(node* current);
//deleting of the root
node* DELROOT(node* root);

int COUNT_ELEMENT(node* head);

void TRAVERSAL_FORWARD(node* head);
void TRAVERSAL_BACKWARD(node* tail);

node* FIND(char* elem_data, node* head);

void EXTRACTION(char* del_elem_data);

void REMOVING_DUPLICATE(node* head);

node* SWAP(node* lst1, node* lst2, node* head);

void SWAP(node* lhv, node* rhv);

node* GETTAIL(node* head);

void BUBBLE_SORT(node* n);

node* READING_FROM_FILE(node* head,char* file_name);

void WRITING_TO_FILE(node* container, char* file_name);