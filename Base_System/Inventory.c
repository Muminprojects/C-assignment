#include"finance.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
InvntoryItem* GetInventoryItem(int uniqueStockID, const database* database)
{
    Inventory* inv = &database -> inventory;
    int i, length = inv -> itemItenvoryCount;

    for(i = 0; i < length; i++)
    {
        InvntoryItem* item = &inv -> itemItenvory[i];
        if(item -> stock.uniqueStockID == uniqueStockID)
        {
            return item;
        }
    }
    printf("Item Could not be found\n");
    return NULL;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
Inventory* GetInventory (const database* database)
{
    return  &database -> inventory;
}

void CreateNewDeliveryInvoice( database* database)
{
    DeliveryInvoice* deliveryInvoice = {0};
    Stock* newStockVariable = {0};
    normal_Date* dateOfDelivery = {0};
}

void CreateNewInventoryItem(database* database)
{
    InvntoryItem* newInvItem = {0};

    Stock* newStockVariable = {0};
    char* uniqueID, costPerUnit, sellingPrice; char stockName[21];
    /* Get User Input */

    /* Assign the inputs to the member variables of 'newStockVariable' */
    newInvItem -> stock = *newStockVariable;


    Supplier* newSupplierVariable = {0};
    char* SupplierID, SupplierName;

    newInvItem -> supplier = *newSupplierVariable;


    newInvItem -> totalStock = 0;
    newInvItem -> currentIndex = database -> inventory.itemItenvoryCount;
    database -> inventory.itemItenvoryCount++;

}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void DeleteInventoryItem(InvntoryItem* invItem, database* database)
{
    GetInventoryItem(invItem -> stock.uniqueStockID, database);
    int indexOfItemToDelete = invItem -> currentIndex;

    InvntoryItem empty = {0};
    database->inventory.itemItenvory[indexOfItemToDelete] = empty;
    database -> inventory.itemItenvoryCount--;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void UpdateCostPerUnit (float newValue, InvntoryItem* invItem)
{
    invItem -> stock.CostPerUnit = newValue;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void UpdatesellingPrice (float newValue, InvntoryItem* invItem)
{
    invItem -> stock.sellingPrice = newValue;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void UpdateStockItemCount( int newCount, InvntoryItem* invItem)
{
    invItem -> totalStock = newCount;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void RemoveAmountFromStocckTotal (int amountToRemove, InvntoryItem* invItem)
{
    invItem -> totalStock -= amountToRemove;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void AddAmountFromStockTotal (int amountToAdd,InvntoryItem* invItem)
{
    invItem -> totalStock += amountToAdd;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void calculateNewStats(InvntoryItem* invItem)
{
    int multiply = invItem -> totalStock;
    float buyPrice = invItem -> stock.CostPerUnit;
    float SellingPrice = invItem -> stock.sellingPrice;
    invItem -> costOfTotalStock = buyPrice * multiply;
    invItem -> totalStockWorth = SellingPrice * multiply;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void RepositionElementsInArray(int indexToStart, Inventory* inv)
{
    int i, invCount = inv-> itemItenvoryCount;
    for(i = indexToStart; i < invCount - 1; i++)
    {
        InvntoryItem* itemToReplace = &inv -> itemItenvory[i + 1];
        itemToReplace -> currentIndex--;
        inv -> itemItenvory[i] = *itemToReplace;
    }
    InvntoryItem empty = {0};
    inv -> itemItenvory[invCount] = empty;
    invCount--;\
}

void ProduceStockItemTextFile(const database* database)
{

}
void ProduceStockItemList_Terminal (const database* database)
{

}
