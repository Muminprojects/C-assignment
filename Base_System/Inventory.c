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
    FILE* file = fopen("stock_items.txt", "w");

    if(file == NULL){
        printf("Error! opening the file to write\n");
        return;
    }
   
    Inventory* inv = GetInventory(database);

    if (inv->itemItenvoryCount == 0){
        fprintf("List is Empty\n");
        fclose();

        printf("File created:stock_tems.txt\n");
        return;

        fprintf(file,"\nSTOCK ITEMS:\n");
        fprintf(file,"%-14s %-15s %-12s %-12s %-15s %-10s %-15s %-15s\n",
        "uniqueStockID", "stockName", "costPerUnit", "sellingPrice", "supplierID", "supplierName", "TotalStock", "costOfTotalStock", "totalStockWorth");
        fprint(file,"-------------- --------------- ------------ ------------ --------------- ---------- --------------- ---------------");

        int i;
        for (i = 0; i < inv->itemItenvoryCount; ++i){

            InvntoryItem* item = inv->itemItenvory[i];

            if(item == NULL){
                continue;
            }
            printf("%-14d %-15s $%-10.2f $%-12.2f %10d %15s %10d $%12.2f $%-15.2f\n",
            item->stock.uniqueStockID,
            item->stock.stockName,
            item->stock.costPerUnit,
            item->stock.sellingPrice,
            item->stock.supplierID,
            item->stock.supplierName,
            item->stock.TotalStock,
            item->stock.costOfTotalStock,
            item->stock.totalStockWorth);

        }

        fclose(file);
        printf("Stock items saved succesfully to the file stock_items.txt\n");





    }


}
void ProduceStockItemList_Terminal (const database* database)
{
     Inventory* inv = GetInventory(database);

    if (inv -> itemItenvoryCount == 0){
        printf("Given List is Empty");
        
        return;

    }

    printf("\nSTOCK ITEMS:\n");

    printf("%-14s %-15s %-12s %-12s %-15s %-10s %-15s %-15s\n",
        "uniqueStockID", "stockName", "costPerUnit", "sellingPrice", "supplierID", "supplierName", "TotalStock", "costOfTotalStock", "totalStockWorth");

    printf("-------------- --------------- ------------ ------------ --------------- ---------- --------------- ---------------");

    int i;
    for (i = 0; i < inv->itemItenvoryCount; ++i){

        InvntoryItem* item = inv->itemItenvory[i];

        if (item == NULL){
            continue;
        }
        printf("%-14d %-15s $%-10.2f $%-12.2f %10d %15s %10d $%12.2f $%-15.2f\n",
            item->stock.uniqueStockID,
            item->stock.stockName,
            item->stock.costPerUnit,
            item->stock.sellingPrice,
            item->stock.supplierID,
            item->stock.supplierName,
            item->stock.TotalStock,
            item->stock.costOfTotalStock,
            item->stock.totalStockWorth);
    
        else{
             printf("Error\n");
            }

    }

    

}


