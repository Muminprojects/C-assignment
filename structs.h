#ifndef STRUCTS_H
#define STRUCTS_H

#define maxHistoryCount 20
#define MAX_INPUT 50

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

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


/*	Card Struct	*/
struct CardInformation{
    char brandName[21];
    char cardholderName[21];
    int CreditCardNumber[17];
    expiry_Date expireDate;
    int SecurityCode[3];
};
typedef struct CardInformation card_Information;


/* Billing Information	*/

struct BillingInformation{
    card_Information cardInformation;
    char BillingAddress [26];
    char Country [16];
    char City[16];
    char State[16];
    int PostalCode [4];
    phone_Number PhoneNumber
};
typedef struct BillingInformation billing_Info;



/*	Purchase Order	*/
typedef struct{
    Dictionary order;
    int totalCost;
}PurchaseOrder;


/*	Purchase Information	*/
struct recipt {
    normal_Date dateOfPurchase;
    PurchaseOrder purchaseOrder;
    billing_Info BillingInformation;
} typedef struct recipt Recipt;


/*	Database Dictionary	*/
typedef struct {
    char ClientName[21];
    card_Information cardInformation;
    Recipt recipt[maxHistoryCount];
    int count;
} Entity;


/*	Database	*/
typedef struct {
    Entity history[];
    int count;
} Databse;

////////////////////////////
/*    Helper Functions    */
////////////////////////////

Entity* FindClient(const char name[21], const Database* database)
{
    int i, length = database -> count;
    for( i = 0; i < length; i++)
    {
        Entity temp =  databse -> Entity[i];
        if(strcmp(name, temp -> ClientName))
        {
            return temp;
        }
    }
    return null;
}

card_Information* GetCardInformation(const char name[21], const Database* database)
{
    Entity clientHistory = FindClient(name, database);
    if(clientHistory == null)
        return null;

    return CardInformation* cardInformation = clientHistory -> cardInformation;
}

void InitalizeNewEntity(Database* database)
{
    /* inalizes new Entity variable who's fields are set to default values    */
    Entity newEntity = {0};

    /*    initalize client Name    */
    char* CardholderName[21];
    GetUserInput(CardholderName, 21, "Enter New Client's Name");
    if(isInputValid(CardholderName, 21) != 0)
        strcpy(newEntity.ClientName, CardholderName);

    /*    initalize client card information    */
    newEntity.cardInformation = InitalizeNewCardInfomration(CardholderName);
    database -> history[ database -> count ] = newEntity;
}

card_Information* InitalizeNewCardInfomration(char* CardholderName[21])
{
    /* TODO: MUST COMPLETE THIS FUNCTION!!! NOT YET COMPLETE */
    card_Information newCard;

    char BrandName[21], CreditCardNumber[17],
    ExpiryMonth[3], ExpiryYear[5], SecurityCode[4];


}


void ProcessNewOrder(const char ClientName[21], Recipt newOrder, const Database* database)
{
    Entity historyToUpdate* = FindClient(ClientName, database);
    int emptyIndex* = historyToUpdate -> count;
    historyToUpdate -> recipt[emptyIndex] = newOrder;
    emptyIndex++;
}

void GetUserInput(char* inputString, int inputSize, const char* prompt)
{
    printf("%s\n", prompt);
    /* fgets reads line given by stdin (user keyboard input)
        and sets the pointer (inputString) to the user input
    */
    if (fgets(inputString, inputSize, stdin) != NULL)
    {
        int len = strlen(buffer);
        /* Replace newline from user pressing 'Enter' into null terminator*/
        if (len > 0 && inputString[len - 1] == '\n')
        {
            inputString[len - 1] = '\0';
        }
    }
}



int ConvertStringToInt(char* inputString)
{
    char* end;
    return (int)strtol(inputString, &end, 10); // x = 456
}
/*--------------------------------------------------------------*/
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

#endif //STRUCTS_H
