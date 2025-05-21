#ifndef FINANCE_H
#define FINANCE_H

#define maxHistoryCount 20
#define MAX_INPUT 50

#include "Base_System/inventory.h" 
#include "Base_System/GeneralHelperMethods.h" 

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
typedef struct {
    normal_Date dateOfPurchase;
    PurchaseOrder purchaseOrder;
    billing_Info BillingInformation;
} recipt;


/*	Database Dictionary	*/
typedef struct {
    char ClientName[21];
    card_Information currentCardInformation;
    recipt recipts[maxHistoryCount];
    int count;
} Entity;

typedef struct{
    char keyName[21];
    Entity* entity;
    int index;
} EntityDictionaryDefinition;

typedef struct {
    EntityDictionaryDefinition clientList[20];
    int count;
} Finance;

/*	Databases	*/
typedef struct{
    Inventory inventory;
    Finance finance;
    const char* dbFileName[];
} database;

 

///////////////////////////////////////
/*    Helper Functions Defintions   */
//////////////////////////////////////

void DeleteClient(Entity* client, database* database);
Entity* FindClient(const char name[21], const database* database);
void DisplayClientList_Terminal(const database* database);
void Clientlist_TextFile(const database* database);
card_Information* GetCardInformation(const char name[21], const database* database);
void InitalizeNewEntity(database* database);
card_Information* InitalizeNewCardInfomration(char* CardholderName[21]);
void ProcessNewOrder(const char ClientName[21], recipt newOrder, const database* database);
void ReorderList(int removedElement, database* database);
#endif 
