#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Base_System/finance.h"
#include "Base_System/inventory.h"

void print_MainMenu(database* dataB);
void print_FinanceMenu(database* dataB);
void print_InventoryMenu(database* dataB);

void getUserInput_MainMenu(database* dataB);
void getUserInput_FinanceMenu(database* dataB);
void getUserInput_InventoryMenu(database* dataB);

int main()
{
    database theDatabase = {0};
    getUserInput_MainMenu(&theDatabase);
    return 0;
}

void printMainMenu(database* dataB) {
    printf("\nBusiness Management System\n"
        "1. Finance section\n"
        "2. Inventory section\n"
        "3. End Program\n"
        "Enter your choice>\n");

    getUserInput_MainMenu(dataB);
}

void PrintFinanceMenu(database* dataB)
{
    printf("\nBusiness Management System: Finance Management\n"
    "1. Finance section\n"
    "2. Inventory section\n"
    "3. End Program\n"
    "Enter your choice>\n");
}
/*--------------------------------------------------------------*/
/* Author: Nestor Batoon */
/*	Function: getUserInput	*/
/*	Takes user inputs of integer digits and executes functions
    assigned to them

    inputs:
    - 'lib' : takes library_t pointer to pass on to other functions
       that will need access to the struct
    - 'dbFileName' : string of file name for file-related functions 										*/
/*--------------------------------------------------------------*/


void getUserInput_MainMenu(database* dataB) {
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
            //TODO: Implement Applicatoin termination
            PrintFinanceMenu(dataB);
            break;
        case 2:
            //TODO: Implement Applicatoin termination
            printInventoryMenue(dataB);
            break;
        case 3:
            //TODO: Implement Code termination
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}

/*--------------------------------------------------------------*/
/* Author: Ashwin Jacob */
/*	Function: getUserInput	*/
/*	Takes user inputs of integer digits and executes functions
    assigned to them

    inputs:
    - 'lib' : takes library_t pointer to pass on to other functions
       that will need access to the struct
    - 'dbFileName' : string of file name for file-related functions 										*/
/*--------------------------------------------------------------*/
void printInventoryMenue(database* dataB){
 printf("\nBusiness Management System: Inventory Management System\n"
    "1.Display Inventory\n"
    "2.Add New Inventory Item\n"
    "3.Delete Inventory Item\n"
    "4.Export Inventory to Textfile\n"
    "Enter your choice>\n");
}

/*
void SelectedchoiceInventory(database* dataB){
    int choice;
    int selectoption = scanf("%d",choice);

    swicth(choice){
        case 1:
        DisplayInventory(dataB);
        break;

        case 2:
        CreateNewInventoryItem(dataB);
        break;

        case 3:
        DeleteInventoryItem(InventoryItem* invItem, Databse* database);
        break;

        case 4:
        ProduceStockItemTextFile(cost Database* database);
        break;

        case 5:
        ProduceDeliveryInvoicTextFile(const Database* database);
        break;
        // checking my work

    }
}
*/