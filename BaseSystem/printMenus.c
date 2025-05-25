#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "database.h"

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

void printFinanceMenu(database* dataB)
{
        printf("\nBusiness Management System\n"
        "1.Process New Order\n"
        "2.Display client list\n"
        "3.Produce textfile of client list\n"
        "4.Return to main menu\n"
        "Enter your choice>\n");
        getUserInput_FinanceMenu(dataB);
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

void getUserInput_FinanceMenu(database* dataB)
{
    int choice;
    /*	Use result as a boolean to store whether integer was given	*/
    int result = scanf("%d", &choice);

    /*	if result == 0, then an integer was not given. Prints the menu again	*/
    if(result == 1) {

        /*	Executes function tied to int	*/
        switch (choice)
        {
        case 1:
            ProcessNewOrder(dataB);
            SaveDatabase(dataB, dataB->dbFileName);
            break;
        case 2:
            DisplayClientList_Terminal(dataB);
            break;
        case 3:
            Clientlist_TextFile(dataB);
            break;
        case 4:
            printMainMenu(0);
            return;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    PrintFinanceMenu(dataB);
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
    printMainMenu(dataB);
}


void SelectedchoiceInventory(database* dataB){
    int choice;
    int selectoption = scanf("%d", &choice);
    if (selectoption == 1) {
        switch(choice){
            case 1:
                ProduceStockItemList_Terminal(dataB);
                break;
            case 2:
                CreateNewInventoryItem(dataB);
                SaveDatabase(dataB, dataB->dbFileName);
                break;
            case 3:
                PrintStockItemManipulationMenu(dataB);
                break;
            case 4: {
                printf("\n Deleting item stock...");
                ProduceStockItemList_Terminal(dataB);
                int input;
                printf("\n Enter Unique Stock ID of Stock you want to remove from database ");
                scanf("%d", &input);
                InvntoryItem* item = GetInventoryItem(input, dataB);
                if (item == NULL)
                    printf("Error: Item not found\n");
                else
                    DeleteInventoryItem(item, dataB);
                break;
            }
            case 5:
                ProduceStockItemTextFile(dataB);
                break;
            case 6:
                printMainMenu(dataB);
                return;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    PrintInventoryMenu(dataB);
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
    "3.Edit an Inventory Item\n"
    "4.Delete Inventory Item\n"
    "5.Export Inventory to Textfile\n"
    "6.Return\n"
    "Enter your choice>\n");
    SelectedchoiceInventory(dataB);
}
