#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Christopher Roy		260687695
//Kayla O'Sullivan Steben	260744112

void Consumer(){
	
	char c;
	char turn;
	FILE *DC;
	FILE *T;
	while(1){
		DC = fopen("DATA.txt", "rt");
		if(DC == NULL) exit(1);
		while(1){ //infinite loop that runs until producer is finished		
			T = fopen("TURN.txt", "rt");
			turn = fgetc(T);
			if (turn == '1') break;
			fclose(T);
		}
		//T won't be closed at this point in the code
		fclose(T);
		
		DC = fopen("DATA.txt", "rt");
		if(DC == NULL) exit(1);
		
		//Transfers the char in DATA.txt to the screen
	    	c = fgetc(DC);
		if (c == EOF) break;
		printf("%c", c); 

		//Tell the producer it is done reading from the shared file
		T = fopen("TURN.txt", "wt");
		fprintf(T, "0");
		fclose(T);
		fclose(DC);
	}
	fclose(DC);
	
	

}
