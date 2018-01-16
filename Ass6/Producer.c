#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Christopher Roy	260687695
//Kayla O'Sullivan	260744112


void Producer(){
	char c;
	char turn;
	FILE *md;
	FILE *DP;
	FILE *T;
	
	//Contains the data that will be put into the shared file	
	md = fopen("mydata.txt", "rt");	

	if (md == NULL)  exit(1);
	while(1){

		//Need to check if it is the producer's turn
		while(1){
		//	printf("Producer waiting..\n");
			T = fopen("TURN.txt", "rt");
			if(T == NULL) exit(1);
			turn = fgetc(T);
			if (turn == '0') break;	//Wait in this infinite loop until it is the producer's turn
			fclose(T);
		}

		fclose(T);

		//Open the shared file
		DP = fopen("DATA.txt", "wt");

		c = fgetc(md);
		if((int)c == EOF) break;       	
           	fprintf(DP, "%c", c); //place char from my data.txt to DATA
		
	

		fclose(DP);

		T = fopen("TURN.txt","wt");
		fprintf(T, "1"); //tell the consumer that he is free to read the data
		fclose(T);
	}
	T = fopen("TURN.txt", "wt");
	fclose(DP);
	DP = fopen("DATA.txt", "wt");
	
	//Consumer needs final instruction to leave its inifinte loop
	fprintf(T, "1");
	fclose(md);
	fclose(DP);
	fclose(T);
	
}




