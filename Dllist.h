#pragma once
#include<malloc.h>

typedef struct node {
	int key;
	node* prev;
	node* next;
}node;

node* INIT(int  key);

//Adding new elem
node* ADD(node* prev, int key);

node* DEL(node* current);
//deleting of the root
node* DELROOT(node* root);