#ifndef FINANCE_H
#define FINANCE_H

#define maxHistoryCount 20
#define MAX_INPUT 50

#include "inventory.h" 
#include "gneralHelperMethods.h" 

/*	Card Struct	*/
struct CardInformation{
    char brandName[21];
    char cardholderName[21];
    int CreditCardNumber;
    expiry_Date expireDate;
    int SecurityCode;
};
typedef struct CardInformation card_Information;


/* Billing Information	*/

struct BillingInformation{
    card_Information cardInformation;
    char BillingAddress [26];
    char Country [16];
    char City[16];
    char State[16];
    int PostalCode ;
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

typedef struct{
    char keyName[21];
    Entity* entity;
    int index;
} EntityDictionaryDefinition;

typedef struct {
    EntityDictionary clientList[20];
    int count;
} Finance;

/*	Databases	*/
typedef struct{
    Iventory inventory;
    Finance finance;
    const char* dbFileName = "database";
} database;

 

///////////////////////////////////////
/*    Helper Functions Defintions   */
//////////////////////////////////////

void DeleteClient(Entity* client, Database* database);
void AddClient(Database* database);
Entity* FindClient(const char name[21], const Database* database);
card_Information* GetCardInformation(const char name[21], const Database* database);
void InitalizeNewEntity(Database* database);
card_Information* InitalizeNewCardInfomration(char* CardholderName[21]);
void ProcessNewOrder(const char ClientName[21], Recipt newOrder, const Database* database);
void ReorderList(int removedElement, Database* database);
#endif 
