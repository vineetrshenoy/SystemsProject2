#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * compressString(char * input);

int main(int argc, char ** argv){
	// Pointers for our input and output files
	FILE * input;
	FILE * output;

	//Filenames for our input and output files.
	char * fileName = argv[1];  //Gets the filename
	char * outputName = "output.txt";

	//Open input file and NULL check
	input = fopen("test1.txt", "r");
	if (input == NULL){
		
		exit(1);
	}

	//Open output file and NULL check
	output = fopen(outputName, "w");
	if (output == NULL){
		
		exit(1);
	}


	int newChar;
	int loopChar;
	char currentChar;	// Char against which to compare
	int count;			//Hold teh number of occurences for the letter
	
	char * buffer = (char * ) malloc(500 * sizeof(char));	//String buffer for sprintf
	newChar = fgetc(input);
	
	while (newChar != EOF) {
		currentChar = (char) newChar;
		count = 1;

		//Loop while letter is not EOF and while the chars match
		while (((loopChar = fgetc(input)) != EOF ) &&  (loopChar == currentChar)){
			count++;
		}

		//Convert the count to a string
		sprintf(buffer, "%d", count);

		// If the number of occurrences is greater than two
		if (count  > 2)
			fprintf(output, "%s%c", buffer, currentChar);
		
		//if the number of occurrences is exactly two, print letter twice
		else if (count == 2)
			fprintf(output, "%c%c", currentChar, currentChar);
		
		//If the number of occurrences is one, print the letter once
		else
			fprintf(output, "%c", currentChar);
		
		//loopChar finished on the first DIFFERENT letter. Set this to the newChar
		newChar = loopChar;
		
	}
	
	//Close the files
	fclose(input);
	fclose(output);
	

	
}

/*
char * compressString(char * input){
	int length = strlen(input);
	int i = 0;
	int j = 0;
	char * newString = (char *) malloc ((length + 1) *sizeof(char));
	while (input[i] != '\0'){
		char currentChar = input[i];
		int count = 0;
		while (currentChar == input[i]){
			count = count + 1;
			i = i + 1;
		}
		char * buffer = (char * ) malloc(sizeof(char));
		sprintf(buffer, "%d", count);

		if (count  > 2){
			newString[j] = buffer[0];
			j++;
			newString[j] = currentChar;
		}

		else if (count == 2){
			newString[j] = currentChar; 
			j++;
			newString[j] = currentChar;

		}
		else{
			newString[j] = currentChar;
		}

		j++;
		free(buffer);

	}

	newString[j] = '\0';


	return newString;
}
*/