#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "database.h"

void printMainMenu(database* dataB);
void printFinanceMenu(database* dataB);
void PrintInventoryMenu(database* dataB);

void getUserInput_MainMenu(database* dataB);
void getUserInput_FinanceMenu(database* dataB);
void getUserInput_InventoryMenu(database* dataB);

int main()
{
    database theDatabase = {0};
    getUserInput_MainMenu(&theDatabase);
    return 0;
}

/*--------------------------------------------------------------*/
/* Author: Nestor Batoon */
/*	Function: printMainMenu	*/
/*	prints the options the user can take

    inputs: None
/*--------------------------------------------------------------*/
void printMainMenu(database* dataB) {
    printf("\nBusiness Management System\n"
        "1. Finance section\n"
        "2. Inventory section\n"
        "3. End Program\n"
        "Enter your choice>\n");

    getUserInput_MainMenu(dataB);
}

/*--------------------------------------------------------------*/
/* Author: Nestor Batoon */
/*	Function: getUserInput	*/
/*	Takes user inputs of integer digits and executes functions
    assigned to them

    inputs:
    - 'lib' : takes library_t pointer to pass on to other functions
       that will need access to the struct
    - 'dbFileName' : string of file name for file-related functions*/
/*--------------------------------------------------------------*/
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
/*	Function: getUserInput_MainMenu	*/
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
            PrintFinanceMenu(dataB);
            break;
        case 2:
            PrintInventoryMenu(dataB);
            break;
        case 3:
                exit(0);
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
void PrintInventoryMenu(database* dataB){
 printf("\nBusiness Management System: Inventory Management System\n"
    "1.Display Inventory\n"
    "2.Add New Inventory Item\n"
    "3.Delete Inventory Item\n"
    "4.Export Inventory to Textfile\n"
    "Enter your choice>\n");
}


void SelectedchoiceInventory(database* dataB){
    int choice;
    int selectoption = scanf("%d",choice);
    switch(choice){
        case 1:
        ProduceStockItemList_Terminal(dataB);
        break;

        case 2:
        CreateNewInventoryItem(dataB);
        break;

        case 3:
        DeleteInventoryItem(InventoryItem* invItem, Databse* database);
        break;

        case 4:
        ProduceStockItemTextFile(dataB);
        break;

        default:
            printf("Invalid choice.\n");
            break;
    }
}
