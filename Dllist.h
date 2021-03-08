#pragma once
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	node* prev;
	node* next;
}node;

node* initialize(int key);
//Adding new elem
node* ADD(node* prev, int key);

node* DEL(node* current);
//deleting of the root
node* DELROOT(node* root);

unsigned int COUNT_ELEMENT(node* head);

