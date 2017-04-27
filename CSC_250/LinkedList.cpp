#include <stdio.h>
#include <stdlib.h>

struct node_def
{
	int data;
	struct node_def *next;
};
typedef struct node_def node;

void printList(node *L);
node *insertFront(node *L, int x);
node *insertEnd(node *L, int x);

int main()
{
	node *head = NULL;
	node *tmp = NULL;

	head = insertFront(head, 7);
	head = insertFront(head, 10);
	head = insertFront(head, 11);

	printList(head);
	
	return 0;
}

void printList(node *L){
	while(L != NULL){
		printf(" %2d",L->data);
		L = L->next;
	}
	printf("\n");
}

node *insertFront(node *L, int x){
	node *new = malloc(sizeof(node));

	new->data = x;
	new->next = L;

	return new;
}

node *insertEnd(node *L, int x){
	node *new = malloc(sizeof(node));
	new->data = x;
	new->next = NULL;

	node *tmp = L;

	if (L == NULL)
	{
		L = new;
	}else{
		while(L != NULL){
		
		}
	}
}