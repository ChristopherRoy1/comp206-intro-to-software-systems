#include <stdio.h>
#include <stdlib.h>

void FindRecord(char *filename, char *name, char record[]){
	FILE *f = fopen(filename, "r");
	char currRecord[1000] = {"\0"};
	char *currName;
	int same;
	while(!feof(f)){
		same = 1; 
		fgets(currRecord, 999, f);

		for(int i = 0; i < 1000; i++){
			//First check to see if there is anything left in the two arrays currRecord and name 
			//if currRecord or name array contains an \0 before the other, then cannot have the same name
			if((*(currRecord+i) == ',' && *(name+i) != '\0') || (*(currRecord+i) != ',' && *(name+i) == '\0')){
				same = 0;
				break;
			}

			//If the above if statement did not trigger, and the name has reached '\0', then the record matches the name
			//All the preceding letters had to have matched, and the current record cannot have reached its comma yet
			if(*(name +i) == '\0'){
				break;
			}			
						
			//this if statement checks if the two characters are the same at the current index
			if(*(currRecord + i) != *(name+i)){
				same = 0;
				break;  
			}
			 		 
		}

		if(same != 0){
			puts("Record found!");
			int i;
			for(i = 0; *(currRecord + i) != '\0'; i++){
				record[i] = *(currRecord + i);
			}

			break;
			   
		}
	}
	if( same == 0){
		puts("Record was not found! Terminating program");
		exit(1);
	}
	fclose(f);
}


void Replace(char *name, char *newname, char record[]){
	char *NewRecord = malloc(sizeof(char)*1000);
	int i=0; //tracks length of old name
	int j=0; //tracks length of new name
	int k=0; //tracks position in New Record

	//loop below counts length of name
	while(*(name+i) != '\0'){
		i++;
	}
	
	//loop counts length of the new name, and inserts it into temp array NewRecord
	while(*(newname+j) != '\0'){
		*(NewRecord + j) = *(newname+j);
		j++;
	}
	
	//places the rest of the record into the NewRecord array
	while(*(record + i + k) != '\0'){
		*(NewRecord +j +k) = *(record + i +k);
		k++;
	}
	
	//copies the NewRecord into the old (replaces it)
	for(int l = 0; *(NewRecord + l) != '\0'; l++){
		*(record+l) = *(NewRecord+l);
		//if statement adds the '\0' incase record hasn't been completely overwritten (occurs when new name is shorter than the old)
		if(*(NewRecord + l + 1) == '\0'){
			*(record + l + 1) = '\0';
		}
	}
	
	free(NewRecord); //necessary because used malloc

}

void SaveRecord(char *filename, char *name, char record[]){
	FILE *f = fopen(filename, "r+");
	FILE *n = fopen("temp.csv", "w+"); //temp file, will be renamed later

	char currRecord[1000] = {"\0"};
	int same = 1; //using same as a boolean variable, is set to 0 once a difference between line in file and name being replaced
	int i = 0;
	
	//similar logic to FindRecord
	while(fgets(currRecord, 999, f)){
		int same = 1;
		for(int i = 0; i < 1000; i++){
			//First check to see if there is anything left in the two arrays currRecord and name 
			//if currRecord or name array contains an \0 before the other, then cannot have the same name
			if((*(currRecord+i) == ',' && *(name+i) != '\0') || (*(currRecord+i) != ',' && *(name+i) == '\0')){
				same = 0;
				break;
			}

			//If the above if statement did not trigger, and the name has reached '\0', then the record matches the name
			//All the preceding letters had to have matched, and the current record cannot have reached its comma yet
			if(*(name +i) == '\0'){
				break;
			}
			
						
			//this if statement checks if the two characters are the same at the current index
			if(*(currRecord + i) != *(name+i)){
				same = 0;
				break;  
			}
			 		 
		}
		if(same == 0){
			fprintf(n, "%s", currRecord); //print the record into temp
		}
		else{
			fprintf(n, "%s", record); //insert the new record in the old record's place
		}
		
		

	}
	puts("Record replacement complete!");
	fclose(n);
	fclose(f);
	rename("temp.csv", filename); //rename the temp file to phonebook.csv

}



void main(){
	char name[1000] = {"\0"};
	char newname[1000] = {"\0"};
	char record[1000]= {"\0"};
	//Step 1 is to ask for a name
	puts("Please enter a name that is in the phonebook");
	scanf("%s", name);
	
	//Step 2 is to ask for a replacement name
	puts("Please enter a replacement name for the record");
	scanf("%s", newname);
	
	FindRecord("phonebook.csv", name, record);
	Replace(name, newname, record);
	SaveRecord("phonebook.csv", name, record);
	exit(0);
}



