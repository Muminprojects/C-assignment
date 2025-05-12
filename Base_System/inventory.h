#ifndef INVENTORY_H
#define INVENTORY_H


#define MAX_UNIQUE_INVENTORY 20

#include "Base_System/finance.h" 
#include "Base_System/inventory.h"
#include "Base_System/generalHelperMethods.h" 

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

InvntoryItem* GetInventoryItem(int uniqueStockID, const database* database);
Inventory* GetInventory (const database* database);

/*///////////////*/ 
 
void CreateNewInventoryItem(database* database);
void DeleteInventoryItem(InvntoryItem* invItem, database* database); 
void ProduceStockItemTextFile(const database* database);
void ProduceStockItemList_Terminal (const database* database);

void CreateNewDeliveryInvoice( database* database);
void UpdateCostPerUnit (float newValue, InvntoryItem* invItem); 
void UpdatesellingPrice (float newValue, InvntoryItem* invItem); 
void UpdateStockItemCount( int newCount, InvntoryItem* invItem);
void RemoveAmountFromStocckTotal (int amountToRemove, InvntoryItem* invItem);
void AddAmountFromStockTotal (int amountToAdd,InvntoryItem* invItem); 
void calculateNewStats(InvntoryItem* invItem);
void RepositionElementsInArray(int indexToStart, database* database);

#endif 