#ifndef GEN_HELP_METHODS_H
#define GEN_HELP_METHODS_H

/*	Dictionary	*/
typedef struct {
    char key[50];
    int value;
    int amount;
} Dictionary;


/*	Expiry Date	*/
struct expDate {
    int month;
    int year;
};
typedef struct expDate expiry_Date;

void GetUserInput(char* inputString, int inputSize, const char* prompt);
int ConvertStringToInt(char* inputString);
float ConvertStringToFloat(char* inputString);
int isInputValid(const char* input, int length);
int isAllDigits(const char* str);


#endif 