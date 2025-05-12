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


/*	Normal Date	*/
struct nomDate {
    int day;
    int month;
    int year;
};
typedef struct nomDate normal_Date;


/*	Phone Number	*/
struct phoneNumber {
    int CountryCode[2]
    int PhoneNumber[10];
};
typedef struct phoneNumber phone_Number;


void GetUserInput(char* inputString, int inputSize, const char* prompt);
int ConvertStringToInt(char* inputString);
float ConvertStringToFloat(char* inputString);
int isInputValid(const char* input, int length);
int isAllDigits(const char* str);

#endif 