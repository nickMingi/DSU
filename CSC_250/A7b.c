#include <stdio.h>
#include <stdlib.h>

typedef struct node_def node;
struct node_def
{
	int val;
	node *next;
};

node *makeNode(int val);
node *insertFront(node *head, node *new);
node *deleteNode(node *head, int val);
node *modifyNode(node *head, int old, int new);
int inList(node *head, int val);
int length(node *head);
void lookForDupes(node *head);
void printList(node *head);

int main(){
	return 0;
}

node *makeNode(int val){
	node *tmp = malloc(sizeof(node));
	tmp -> val = val;
	tmp -> next = NULL;

	return tmp;
}

node *insertFront(node *head, node *new){
	if(head == NULL)
		head = new;
	else{
		new->next = head;
		head = new;
	}

	return head;
}

node *deleteNode(node *L, int val){

}

node *modifyNode(node *L, int old, int new){

}

int inList(node *L, int val){
	// returns 1 if found, 0 if not found
}

int length(node *L){

}

void lookForDupes(node *L){

}

void printList(node *head){
	node *tmp = head;
	int i = 0;

	for(i = 1; tmp != NULL; ++i){
		printf("%d ", tmp->val);
		if(i % 10 == 0)
			printf("\n");
		tmp = tmp -> next;
	}
	if((i-1) % 10)
		printf("\n");

	return;
}