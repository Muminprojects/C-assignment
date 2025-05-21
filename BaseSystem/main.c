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


