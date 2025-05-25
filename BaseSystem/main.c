#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "database.h"
#include "generalHelperMethods.h"

int main()
{
    database theDatabase = {0};
    theDatabase.dbFileName = "database";
    loadFromFile(&theDatabase, theDatabase.dbFileName);
    printMainMenu(&theDatabase);
    return 0;
}

 