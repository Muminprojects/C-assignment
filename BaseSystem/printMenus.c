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
        "1. Add Client to system\n"
        "2. Update client balance\n"
        "3. Remove Client from system\n"
        "4. Display list of clients\n"
        "5. Produce Textfile with a list of clients\n"\
        "6. Exit terminal application\n"
        "Enter your choice>\n");

    getUserInput_MainMenu(dataB);
}
/*--------------------------------------------------------------*/
/* Author: Nestor Batoon */
/*	Function: getUserInput_MainMenu	*/
/*	Takes user inputs of integer digits and executes functions
    assigned to them

    inputs:
    - 'lib' : takes library_t pointer to pass on to other functions
       that will need access to the struct
    - 'dbFileName' : string of file name for file-related functions*/
/*--------------------------------------------------------------*/

void getUserInput_MainMenu(database* dataB)
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
            InitalizeNewEntity(dataB); 
            SaveDatabase(dataB, dataB->dbFileName);
            break;
        case 2:
            UpdateClientDetailsMenu(dataB)
            break;
        case 3:
            char* ClientName;
                do {
                GetUserInput(ClientName, 21, "Enter New Client's Name");
            } while (!isInputValid(ClientName, 20));

            Entity* client = FindClient(ClientName, database);
            if(client == NULL)
            {
                printf("\n Error! Client not found! \n");
                return;
            }
            DeleteClient(ClientName, dataB);
            break;
        case 4:
            DisplayClientList_Terminal(dataB);
            break;
        case 5:
            Clientlist_TextFile(dataB);
            return;
        case 6:
            exit(0); 
            return;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    PrintFinanceMenu(dataB);
    SaveDatabase(dataB, dataB->dbFileName);
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
void UpdateClientDetailsMenu(database* dataB) {
    printf("\nBusiness Management System\n"
        "1. Add amount to client balance\n"
        "2. Remove amount from client balance\n"
        "3. Return to Main Menu\n"
        "Enter your choice>\n");

    getUserInput_UpdateClientDetailsMenu(dataB);
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


void getUserInput_UpdateClientDetailsMenu(database* dataB) {
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
            DisplayClientList_Terminal(dataB);
            AddAmountToBalance(dataB);
            break;
        case 2:
            DisplayClientList_Terminal(dataB);
            RemoveAmountFromBalance(dataB);
            break;
        case 3:
            printMainMenu();
            return;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    UpdateClientDetailsMenu(dataB);
}
