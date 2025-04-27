#ifndef STRUCTS_H
#define STRUCTS_H

#define maxHistoryCount 20
#define MAX_INPUT 50

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
    card_Information currentCardInformation;
    Recipt recipt[maxHistoryCount];
    int count;
} Entity;


/*	Database	*/
typedef struct {
    Entity history[];
    int count;
} Databse;

///////////////////////////////////////
/*    Helper Functions Defintions   *//
//////////////////////////////////////

Entity* FindClient(const char name[21], const Database* database);
card_Information* GetCardInformation(const char name[21], const Database* database);
void InitalizeNewEntity(Database* database);
card_Information* InitalizeNewCardInfomration(char* CardholderName[21]);
void ProcessNewOrder(const char ClientName[21], Recipt newOrder, const Database* database);
void GetUserInput(char* inputString, int inputSize, const char* prompt);
int ConvertStringToInt(char* inputString);
int isInputValid(const char* input, int length);
int isAllDigits(const char* str);

#endif //STRUCTS_H
