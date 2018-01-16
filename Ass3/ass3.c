#include <stdio.h>

// Mini Assignment 3 by Christopher Roy, ID: 260687695

int main(void)
{
	//message to encrypt will be stored in the message array
	char message[100];
	int key = 0;	
	
	//get message from user
	printf("Sentence: ");
	fgets(message, 99, stdin);
	
	//get key from user: must be between 1 and 25
	printf("Key: ");
	scanf("%d", &key);
	
	//if the key is not between 1 and 25 (inclusive) print an error message and exit program;
	if(key < 1 || key > 25){
		puts("Error: key must be between 1 and 25");
		return 1;
	}

	int currChar;
	
	//encryption loop		
	for(int i = 0; i < 100; i++){
		currChar = message[i];
		if(currChar >= 'a' && currChar <= 'z'){
			//add 26 to avoid negative results from the modulo
			message[i] = (currChar + 26 - 'a' - key)%26 + 'a' ;	
		}
		else if(currChar >= 'A' && currChar <= 'Z'){			
			message[i] = (currChar + 26 - 'A' - key)%26 + 'A' ;	
		}
				
	}
	
	printf("Encrypted message: %s", message);
	
	//decryption loop
	for(int i = 0; i < 100; i++){
		currChar = message[i];
		//the decryption can't result in a negative modulo, so no need to add 26
		if(currChar >= 'a' && currChar <= 'z'){
			message[i] = (currChar  - 'a' + key)%26 + 'a'; 
		} else if(currChar >= 'A' && currChar <= 'Z'){
			message[i] = (currChar - 'A' + key)%26 + 'A';
		}
	}

	printf("Decrypted message: %s", message);

	return 0; 



}
