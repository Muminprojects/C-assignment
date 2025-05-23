#ifndef DATABASE_H
#define DATABASE_H

#define maxHistoryCount 20
#define MAX_INPUT 50
#define MAX_UNIQUE_INVENTORY 20

#include "GeneralHelperMethods.h"

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
    int PostalCode;
};
typedef struct BillingInformation billing_Info;


/*	Purchase Order	*/
typedef struct{
    Dictionary order;
    int totalCost;
    Entity client;
}PurchaseOrder;


/*	Database Dictionary	*/
typedef struct {
    char ClientName[21];
    card_Information currentCardInformation;
    billing_Info BillingInformation;
    int count;
} Entity;

typedef struct{
    char keyName[21];
    Entity* entity;
    int index;
} EntityDictionaryDefinition;

typedef struct {
    float totalBalance;
    EntityDictionaryDefinition clientList[20];
    int count;
} Finance;

typedef struct{
    int uniqueStockID;
    char stockName[21];
    float CostPerUnit;
    float sellingPrice;
} Stock;


typedef struct {
    int uniqueInvoiceID;
    Stock stock;
    normal_Date dateOfDelivery;
    int amountDelivered;
    float paymentToSuppler;
} DeliveryInvoice;


typedef struct{ 
    int supplierID;
    char supplierName[21];
    DeliveryInvoice deliveryHistory[20];
} Supplier;


typedef struct{
    Stock stock; 
    Supplier supplier;
    int totalStock;
    float costOfTotalStock;
    float totalStockWorth;
    int currentIndex;
} InvntoryItem;


typedef struct{
    InvntoryItem itemItenvory[MAX_UNIQUE_INVENTORY];
    int itemItenvoryCount;
} Inventory;


///////////////////////////////////////
/*    Helper Functions Defintions   */
//////////////////////////////////////

/*	Databases	*/
typedef struct{
    Inventory inventory;
    Finance finance;
    char* dbFileName;
} database;

/*    Print Menu Functions */
void printMainMenu(database* dataB);
void printFinanceMenu(database* dataB);
void PrintInventoryMenu(database* dataB);

void getUserInput_MainMenu(database* dataB);
void getUserInput_FinanceMenu(database* dataB);
void getUserInput_InventoryMenu(database* dataB);

/*    Helper Functions Defintions for Finance */

void DeleteClient(Entity* client, database* database);
Entity* FindClient(const char name[21], const database* database);
card_Information* GetCardInformation(const char name[21], const database* database);
void InitalizeNewEntity(database* database);
card_Information* InitalizeNewCardInfomration(char* CardholderName[21]);
billing_Info* InitalizeNewBillingInformaTion();
void ProcessNewOrder(const database* database);
void ReorderList(int removedElement, database* database);

InvntoryItem* GetInventoryItem(int uniqueStockID, const database* database);
Inventory* GetInventory (const database* database);

/*    Helper Functions Defintions for Inventory */
 
void CreateNewInventoryItem(database* database);
void DeleteInventoryItem(InvntoryItem* invItem, database* database);
void ProduceStockItemTextFile(const database* database);
void ProduceStockItemList_Terminal (const database* database);
void DisplayClientList_Terminal(const database* database);
void Clientlist_TextFile(const database* database);

void CreateNewDeliveryInvoice( database* database);
void UpdateCostPerUnit (float newValue, InvntoryItem* invItem); 
void UpdatesellingPrice (float newValue, InvntoryItem* invItem); 
void UpdateStockItemCount( int newCount, InvntoryItem* invItem);
void RemoveAmountFromStocckTotal (int amountToRemove, InvntoryItem* invItem);
void AddAmountFromStockTotal (int amountToAdd,InvntoryItem* invItem); 
void calculateNewStats(InvntoryItem* invItem);
void RepositionElementsInArray(int indexToStart, database* database);

void SelectedchoiceInventory(database* dataB);
void PrintStockItemManipulationMenu(database* database);
void PrintStockItemManipulationMenu_Input(database* database);
void EditStockPrompt(database* database);
void EditStockOptions(InvntoryItem* item, database* database);
void DisplayStockItem(InvntoryItem* item);
void EditStock(InvntoryItem* item, database* database);

void SaveDatabase(const database* dataB, const char* filename);
void loadFromFile(database* dataB, const char* filename);

#endif 