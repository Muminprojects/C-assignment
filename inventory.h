#ifndef INVENTORY_H
#define INVENTORY_H


#define MAX_UNIQUE_INVENTORY 20

#include "finance.h" 
#include "gneralHelperMethods.h"

typedef struct{
    int uniqueStockID[5];
    char stockName[21];
    float CostPerUnit;
    float sellingPrice;
} Stock;


typedef struct {
    int uniqueInvoiceID[5];
    Stock stock;
    nomDate dateOfDelivery;
    int amountDelivered;
    float paymentToSuppler;
} DeliveryInvoice;


typedef struct{ 
    int supplierID[5];
    char supplierName[21];
    DeliveryInvoice deliveryHistory[];
} Supplier;


typedef struct{
    Stock stock; 
    Supplier supplier;
    int totalStock;
    float costOfTotalStock;
    float totalStockWorth;
} InvntoryItem;


typedef struct{
    InvntoryItem itemItenvory[MAX_UNIQUE_INVENTORY];
    int count;
} Inventory;


///////////////////////////////////////
/*    Helper Functions Defintions   */
//////////////////////////////////////

Stock* GetInventoryItem(int uniqueStockID[5], const Database* database);
DeliveryInvoice* GetDeliveryInvoice (int uniqueInvoiceID[5], const Database* database);
Iventory* GetInventory (const Database* database);

/*///////////////*/

void CreateNewDeliveryInvoice( Database* database);
void CreateNewInventoryItem(Databse* database);
void DeleteInventoryItem(InvntoryItem* invItem, Databse* database);

void UpdateStockID (int uniqueStockID[5], InvntoryItem* invItem);
void UpdateStockName (char stockName[21], InvntoryItem* invItem);
void UpdateCostPerUnit (float newValue, InvntoryItem* invItem); 
void UpdatesellingPrice (float newValue, InvntoryItem* invItem); 

void UpdateStockItemCount( int newCount, InvntoryItem* invItem);
void RemoveAmountFromStocckTotal (int amountToRemove, InvntoryItem* invItem);
void AddAmountFromStockTotal (int amountToAdd,InvntoryItem* invItem);
void calculateNewStats(InvntoryItem* invItem);

void ProduceStockItemTextFile(const Database* database);
void ProduceDeliveryInvoiceTextFile (const Database* database);

#endif 