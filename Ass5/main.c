//
// Christopher Roy - Assignment 5 - 260687695
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
		
	const int TRUE = 1;
	int n = 0;

	//creates a new list in the list.c file	
	newList();

	//the loop below will run indefinitely unless the break statement is reached (n <=0)	
	while (TRUE) {
		printf("Please enter an integer greater than zero: ");
		scanf("%d", &n);

		if (n <= 0) {
			break;
		}

		addNode(n);
	}
	
	//once the loop is exited, we print the values in the list
	prettyPrint();


	return 0;



}
