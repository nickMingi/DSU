#include <stdio.h>
#include <stdlib.h>

struct node_def
{
	int data;
	struct node_def *next;
};
typedef struct node_def node;

node *makeNode(int val);
node *insertFront(node *head, node *new);
void printList(node *head);

int main()
{
	node *head = NULL;
	node *tmp = NULL;
	int nodes = 0, i = 0;
	printf("How many nodes? ");
	scanf("%d",&nodes);
	for(i = 0; i < nodes; i++){
		tmp = makeNode(rand()%9999);
		head = insertFront(head,tmp);
	}
	printList(head);	
}

void printList(node *head){
	int i = 1;
	while(head != NULL){
		printf("%4d ", head->data);
		head = head->next;
		if(i%10==0){
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

node *insertFront(node *head, node *new){
	new -> next = head;
	head = new;

	return head;
}

node *makeNode(int val){
	node *new = malloc(sizeof(node));
	new->data = val;

	return new;
}