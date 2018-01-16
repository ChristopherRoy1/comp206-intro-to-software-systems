#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Producer.c"
#include "Consumer.c"

//Christopher Roy	260687695
//Kayla O'Sullivan	206744112	


int main(){
	//Files are created so that we don't have to incldue them
	FILE *T = fopen("TURN.txt", "wt");
	fprintf(T, "0");
	fclose(T);
	
	FILE *md = fopen("mydata.txt", "wt");
	fprintf(md, "Contents of mydata.txt!");
	fclose(md);
	
	//two processes run with different PIDs now
	int pid = fork();
		
	if (pid == -1) exit(1); //error has occured
	if (pid == 0){ Producer(); }

	if (pid != 0){ Consumer(); }


}
