#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "database.h"

int main()
{
    database theDatabase = {0};
    theDatabase.dbFileName = "database";
    loadFromFile(theDatabase, theDatabase.dbFileName);
    getUserInput_MainMenu(&theDatabase);
    return 0;
}


 