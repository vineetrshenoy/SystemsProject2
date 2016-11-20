#include <stdio.h>
#include <stdlib.h>
#include <string.h>




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

	int numParts = atoi(argv[2]);

	int numChars = findLength(input); 	//The number of chars in the file
	
	int partLength = numChars/numParts; 	//Length of each part, except the first
	
	int remainder = numChars % numParts;
	

	int nLengths[numParts];
	nLengths[0] = partLength + remainder;

	int i;
	for (i = 1; i < numParts; i++){
		nLengths[i] = partLength;
	}

	int j = fseek(input,  8,SEEK_SET);
	printf("the input character is %c \n", fgetc(input));

	/*
	int newChar;
	int loopChar;
	char currentChar;	// Char against which to compare
	int count;			//Hold the number of occurences for the letter
	
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
	
	*/
	
}


int findLength(FILE * fp){
	int count = 0;
	int newChar;
	while ((newChar = fgetc(fp)) != EOF)	
		count++;

	return count;
}