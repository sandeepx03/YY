#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <timer.h>
#include "dlist.hh"

struct Node{
	int key;
	struct Node *prev;
	struct Node *next;
};
typedef struct Node Node;

struct Node *front;

Node *first(){
	return front;
}

Node *last(Node *n){
	while(n->next != NULL) n = n->next;
	return n;
}

Node *previous(Node *q){
	return n->prev;
}

Node *next(Node *q){
	return n->next;
}

Node *createNewNode(int x){

	Node *n = (Node*)malloc(sizeof(Node));
	
	n->key = x;
	n->prev = NULL;
	n->next = NULL;
	return n;

}

void add_to_front(int x){
	
	Node *n = createNewNode(x);

	if(front == NULL){
		front = n;
		return;
	}
	front->prev = n;
	n->next = front;
	front = n;

}

void add_to_back(int x){

	Node *temp = front;
	Node *n = createNewNode(x);
	if(front == NULL){
		front = n;
		return;
	}
	while(temp->next != NULL) temp = temp->next;
	temp->next = n;
	n->prev = temp;

}

void remove(Node *n){

	if(front == NULL){		
		return;
	}
	if(front == n){				
		front = n->next;		
	}	
	if(n->next != NULL){			
		n->next->prev = n->prev;	
	}
	if(n->prev != NULL){		
		n->prev->next = n->next;	
	}
	free(n);					
	return;

}

Node *search_value(int key){

	if(front == NULL){						
		return NULL;				
	}

	Node *temp = front;					
	for(temp; temp != NULL; temp = temp->next){		
		if(temp->key == key){				
			return temp;						
		}
	}

	return NULL;						
}

void Print() {
	struct Node* temp = front;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->key);
		temp = temp->next;
	}
	printf("\n");
}