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

}

void CreateNewInventoryItem(Databse* database)
{

}

void DeleteInventoryItem(InvntoryItem* invItem, Databse* database)
{

}


void UpdateStockID (int uniqueStockID, InvntoryItem* invItem)
{

}

void UpdateStockName (char stockName[21], InvntoryItem* invItem)
{

}

void UpdateCostPerUnit (float newValue, InvntoryItem* invItem)
{

}

void UpdatesellingPrice (float newValue, InvntoryItem* invItem)
{

}


void UpdateStockItemCount( int newCount, InvntoryItem* invItem)
{

}

void RemoveAmountFromStocckTotal (int amountToRemove, InvntoryItem* invItem)
{

}

void AddAmountFromStockTotal (int amountToAdd,InvntoryItem* invItem)
{

}

void calculateNewStats(InvntoryItem* invItem)
{

}
