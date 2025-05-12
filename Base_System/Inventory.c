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
InvntoryItem* GetInventoryItem(int uniqueStockID, const Database* database)
{
    Inventory* inv = database -> inventory;
    int i, length = inv -> itemInventoryCount;

    for(i = 0; i < length; i++)
    {
        InvntoryItem* item = inventory -> itemInventory[i];
        if(item -> stock -> uniqueStockID == uniqueStockID)
        {
            return item;
        }
    }
    printf("Item Could not be found\n");
    return null:
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
Iventory* GetInventory (const Database* database)
{
    return  database -> inventory;
}

void CreateNewDeliveryInvoice( Database* database)
{
    DeliveryInvoice* deliveryInvoice = {0};
    Stock* newStockVariable = {0};
    nomDate* dateOfDelivery = {0};
}

void CreateNewInventoryItem(Databse* database)
{
    InvntoryItem* newInvItem = {0};

    Stock* newStockVariable = {0};
    char* uniqueID, costPerUnit, sellingPrice; char stockName[21];
    /* Get User Input */

    /* Assign the inputs to the member variables of 'newStockVariable' */
    newInvItem -> stock = newStockVariable;


    Supplier* newSupplierVariable = {0};
    char* SupplierID, SupplierName;

    newInvItem -> supplier = newSupplierVariable;


    newInvItem -> totalStock = 0;
    newInvItem -> currentIndex = database -> itemInventoryCount;
    database -> itemInventoryCount++;

}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void DeleteInventoryItem(InvntoryItem* invItem, Databse* database)
{
    GetInventoryItem(invItem -> stock -> uniqueStockID, database);
    int indexOfItemToDelete = invItem -> currentIndex;

    database -> inventory -> itemItenvory[indexOfItemToDelete] = null;
    database -> inventory -> itemItenvoryCount--;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void UpdateCostPerUnit (float newValue, InvntoryItem* invItem)
{
    invItem -> stock -> CostPerUnit = newValue;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void UpdatesellingPrice (float newValue, InvntoryItem* invItem)
{
    invItem -> stock -> sellingPrice = newValue;
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
    invItem -> totalStock += amountToRemove;
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
    float buyPrice = invItem -> stock -> CostPerUnit;
    float SellingPrice = invItem -> stock -> sellingPrice;
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
    int i, int* invCount = inv-> itemItenvoryCount;
    for(i = indexToStart; i < inv-> invCount - 1; i++)
    {
        InventoryItem* itemToReplace = inv -> itemItenvory[i + 1];
        itemToReplace -> currentIndex--;
        inv -> itemItenvory[i] = itemToReplace;
    }
    inv -> itemItenvory[invCount] = null;
    invCount--;
}

void ProduceStockItemTextFile(const Database* database);
{

}
void ProduceStockItemList_Terminal (const Database* database)
{

}
