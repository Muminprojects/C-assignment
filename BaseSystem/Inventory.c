#include"database.h"
#include<stdio.h>
#include"generalHelperMethods.h"
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
    InvntoryItem newInvItem = {0};

    Stock newStockVariable = {0};
    int uniqueID, totalStock, currentIndex;
    float costPerUnit, sellingPrice, costOfTotalStock, totalStockWorth;
    char* stockName[21];

    /* Get User Input */
    printf("\n Enter Unique Stock ID of Stock you want to edit.\n ");
    scanf("%d", &uniqueID);
    newStockVariable.uniqueStockID = uniqueID;

    GetUserInput(stockName, 21, "Enter name of new stock item");
    if(isInputValid(stockName, 21) != 0)
        strcpy(newStockVariable.stockName, stockName);

    printf("\n cost per unit.\n ");
    scanf("%f", &costPerUnit);
    newStockVariable.CostPerUnit = costPerUnit;

    printf("\n selling price per unit.\n ");
    scanf("%f", &sellingPrice);
    newStockVariable.sellingPrice = sellingPrice;

    /* Assign the inputs to the member variables of 'newStockVariable' */
    newInvItem -> stock = *newStockVariable;

    printf("\n Enter total stock count.\n ");
    scanf("%d", &totalStock);
    newInvItem -> totalStock = totalStock;
    newInvItem -> costOfTotalStock = costPerUnit * totalStock;
    newInvItem -> totalStockWorth = sellingPrice * totalStock;

    Supplier* newSupplierVariable = {0};
    char* SupplierName;
    GetUserInput(SupplierName, 21, "Enter supplier name");
    if(isInputValid(SupplierName, 21) != 0)
        strcpy(newSupplierVariable.supplierName, SupplierName);

    int uniqueSupplierID;
    printf("\n Enter Unique Stock ID of Stock you want to edit.\n ");
    scanf("%d", &uniqueSupplierID);
    newSupplierVariable.supplierID = uniqueSupplierID;

    newInvItem -> supplier = *newSupplierVariable;
    newInvItem -> currentIndex = database -> inventory.itemItenvoryCount;
    database -> inventory.itemItenvory[database -> inventory.itemItenvoryCount] = newInvItem;
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
    calculateNewStats(invItem);
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
    calculateNewStats(invItem);
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
    calculateNewStats(invItem);
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
    calculateNewStats(invItem);
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
    calculateNewStats(invItem);
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
            printf("%-14d %-21s $%-10.2f $%-12.2f %10d %15s %10d $%12.2f $%-15.2f\n",
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

void DisplayStockItem(InvntoryItem* item)
{
    if (item == NULL){

        printf("Error: Item not found\n");
        return;
    }
    printf("%-14d %-21s $%-10.2f $%-12.2f %10d %15s %10d $%12.2f $%-15.2f\n",
        item->stock.uniqueStockID,
        item->stock.stockName,
        item->stock.costPerUnit,
        item->stock.sellingPrice,
        item->supplier.supplierID,
        item->supplier.supplierName,
        item->TotalStock,
        item->costOfTotalStock,
        item->totalStockWorth);
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
        DisplayStockItem(inv->itemItenvory[i]);
    }
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void PrintStockItemManipulationMenu(database* database)
{
    printf("\nEdit Stock Items\n"
       "1.Edit an Inventory Item's property\n"
       "2.Display Inventory\n"
       "3.return to Inventory menu\n"
       "Enter your choice>\n");
    PrintStockItemManipulationMenu_Input(database);
}

void PrintStockItemManipulationMenu_Input(database* database)
{
    /*	Await user input and store it in choice	*/
    int choice;
    /*	Use result as a boolean to store whether integer was given	*/
    int result = scanf("%d", &choice);

    /*	if result == 0, then an integer was not given. Prints the menu again	*/
    if(result == 1) {

        /*	Executes function tied to int	*/
        switch (choice)
        {
            case 1:
                EditStockPrompt(database);
                break;
            case 2:
                ProduceStockItemList_Terminal(database);
                break;
            case 3:
                PrintInventoryMenu(database);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}


void EditStockPrompt(database* database)
{
    ProduceStockItemList_Terminal(database);
    int input;

    printf("\n Enter Unique Stock ID of Stock you want to edit ");
    scanf("%d", &input);
    Item* item = GetInventoryItem(input, database);
    if (item == NULL)
        {
        printf("Error: Item not found\n");
        PrintStockItemManipulationMenu_Input(database);
    }
    else
    {
        EditStockOptions(GetInventoryItem(input, database), database);
    }
}



void EditStockOptions(InvntoryItem* item, database* database)
{
    DisplayStockItem(item);
    printf("\n Currently editing: %-21s"
        "\n1. Update Cost Per Unit"
        "\n2. Update Selling Price Per Unit"
        "\n3. Set Current Stock Item Count"
        "\n4. Add amount to total Stock count"
        "\n5. Remove amount from total Stock count"
        "\n6. Return"
        , item->stock.stockName);

    EditStock(item, database);
}

void EditStock(InvntoryItem* item, database* database)
{
    int choice;
    int result = scanf("%d", &choice);
    if (result == 1) {
        switch(choice){
            case 1:
                float newCost;
                scanf("%f", &newCost);
                UpdateCostPerUnit(newCost, item);
                DisplayStockItem(item);
                break;

            case 2:
                float newValue;
                scanf("%f", &newValue);
                UpdatesellingPrice(newValue, item);
                DisplayStockItem(item);
                break;

            case 3:
                int newCount;
                scanf("%d", &newCount);
                UpdateStockItemCount(newCount, item);
                DisplayStockItem(item);
                break;

            case 4:
                int amountToAdd;
                scanf("%d", &amountToAdd);
                AddAmountFromStockTotal(amountToAdd, item);
                DisplayStockItem(item);
                break;

            case 5:
                int amountToRemove;
                scanf("%d", &amountToRemove);
                RemoveAmountFromStocckTotal(amountToRemove, item);
                DisplayStockItem(item);
                break;

            case 6:
                PrintStockItemManipulationMenu(database);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
        SaveDatabase(database, database->dbFileName);
        EditStockOptions(item, database);
    }
}
