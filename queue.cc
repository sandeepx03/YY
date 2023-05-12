#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <timer.h>
#include "queue.hh"

struct QueueNode
{
	double key;
	struct QueueNode *next;

};
typedef struct QueueNode QueueNode;

struct Queue
{
	QueueNode *head, *tail;
	int s; //size

};
typedef struct Queue Queue;

void createEmptyQueue(Queue *q){

	q->s = 0;
	q->head = NULL;
	q->tail = NULL;

}

void enqueue(Queue *q, double x){

	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));	
	temp->key = x;												
	temp->next = NULL;										

	if(q->tail == NULL){									
		q->head = q->tail = temp;								
	}

	q->tail->next = temp;										
	q->tail = temp;											

	q->s++;												

}

double dequeue(Queue *q){

	if(q->head == NULL) return NULL;				
	QueueNode *temp = q->head;							
	double x = q->head->key;							
	q->head = q->head->next;							
	q->n--;													
	free(temp);												
	return x;											

}