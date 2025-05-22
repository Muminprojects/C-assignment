#include"generalHelperMethods.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void GetUserInput(char* inputString, int inputSize, const char* prompt)       
{
    printf("%s\n", prompt);
    /* fgets reads line given by stdin (user keyboard input)
        and sets the pointer (inputString) to the user input
    */
    if (fgets(inputString, inputSize, stdin) != NULL)
    {
        int len = strlen(inputString);
        /* Replace newline from user pressing 'Enter' into null terminator*/
        if (len > 0 && inputString[len - 1] == '\n')
        {
            inputString[len - 1] = '\0';
        }
    }
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
	Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
int ConvertStringToInt(char* inputString)
{
    char* end;
    return (int)strtol(inputString, &end, 10);
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
/*	Function: isInputValid	*/
/*	Checks if the length of the input string does not exceed the
    limit (length)

    Input:
    - 'input' : string input given by scanf
    - 'length' : int given that represents the char limit
         a string has

    Output:
    -	returns 0 if char limit exceeded
    - 	returns 1 if within char limit							*/
/*--------------------------------------------------------------*/
int isInputValid(const char* input, int length){
    int inputLength = strlen(input);
    if(inputLength > length || inputLength == 0)
    {
        return 0;
    }
    return 1;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
/*	Function: isAllDigits	*/
/*	Checks if the length of the input string does not exceed the
    limit (length)

    Input:
    - 'input' : string input given by scanf
    - 'length' : int given that represents the char limit
         a string has

    Output:
    - returns 0 if either of the characters are not digits
    - returns 1 if all characters are digits					*/
/*--------------------------------------------------------------*/
int isAllDigits(const char* str) {
    /* Index for iterating through the string */
    int i;

    /* Loop through each character in the string until the null terminator is reached */
    for (i = 0; str[i] != '\0'; i++)
    {
        /* Check if the ASCII value of the current character
        is not between '0' and '9' */
        if (str[i] < '0' || str[i] > '9')
        {
            /* If not a digit, return 0 (false) */
            return 0;
        }
    }

    /* All characters were digits, return 1 (true) */
    return 1;
}

float ConvertStringToFloat(char* inputString)
{
    char* end;
    return (float)strtol(inputString, &end, 10);
}

void SaveDatabase(const database* dataB, const char* filename)
{
    	/* Open the file for writing in binary mode */
	FILE* fp = fopen(filename, "wb");   

	
	/* If the file fails to open, function is stopped */
	if (!fp) {  
		return;
	}

	/* Write the entire library struct with all its
	 member variables */ 
	fwrite(dataB, sizeof(database), 1, fp);

	/* Close the file to save changes */
	fclose(fp);
}



/*--------------------------------------------------------------*/
/*	Function: loadFromFile	
 * This function loads (reads) library data from a binary file.
 * It replaces the current contents of the library with the saved data.
 *
 *	Input: 
 *		- 'lib' : refrence to library in main
 *      - 'filename' : string name of databse file
 *
 *	Output:
 *	- reads data from binary file name and sets it's contents
 *  into current library variable in main
 */
/*--------------------------------------------------------------*/
void loadFromFile(database* dataB, const char* filename) 
{
    /* Open the file for reading in binary mode ("rb") */
    FILE* fp = fopen(filename, "rb");

    /* Check if the file could not be opened */
    if (!fp) {  
		/* if fialed to open, print error message and 
		exit function early */
        printf("Read error\n"); 
        return;                 
    }


    fread(dataB, sizeof(database), 1, fp);

    /* Close the file after reading */
    fclose(fp);
    /* print sucessfull load  */
    printf("Database loaded from file.\n");
}