//
// Christopher Roy - Assignment 5 - 260687695
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

//the head of the node (and thus the entire list) only exists within the scope of the list.c file
static struct NODE *head;


void newList(){
	head = NULL;
}



int addNode(int value){
	struct NODE *newNode = (struct NODE *) malloc(sizeof(struct NODE));
	if(newNode == NULL){//if the allocation wasn't permitted
		return 1;
	}
	
	//assign the value to the new node
	newNode->data = value;
	//have the new node point to the old head of the list
	newNode->next = head;

	//assign the new node to be the head of the list 
	head = newNode;

	return 0;


}


void prettyPrint(){
	struct NODE *currNode = head;
	while(currNode != NULL){
		printf("%d \n", currNode->data);
		currNode = currNode->next;
	}
}
