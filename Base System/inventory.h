#ifndef INVENTORY_H
#define INVENTORY_H


#define MAX_UNIQUE_INVENTORY 20

#include "finance.h" 
#include "gneralHelperMethods.h"

typedef struct{
    int uniqueStockID;
    char stockName[21];
    float CostPerUnit;
    float sellingPrice;
} Stock;


typedef struct {
    int uniqueInvoiceID;
    Stock stock;
    nomDate dateOfDelivery;
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

InvntoryItem* GetInventoryItem(int uniqueStockID, const Database* database);
Iventory* GetInventory (const Database* database);

/*///////////////*/ 
 
void CreateNewInventoryItem(Databse* database);
void DeleteInventoryItem(InvntoryItem* invItem, Databse* database); 
void ProduceStockItemTextFile(const Database* database);
void ProduceStockItemList_Terminal (const Database* database);

void CreateNewDeliveryInvoice( Database* database);
void UpdateCostPerUnit (float newValue, InvntoryItem* invItem); 
void UpdatesellingPrice (float newValue, InvntoryItem* invItem); 
void UpdateStockItemCount( int newCount, InvntoryItem* invItem);
void RemoveAmountFromStocckTotal (int amountToRemove, InvntoryItem* invItem);
void AddAmountFromStockTotal (int amountToAdd,InvntoryItem* invItem); 
void calculateNewStats(InvntoryItem* invItem);
void RepositionElementsInArray(int indexToStart, Database* database);

#endif 