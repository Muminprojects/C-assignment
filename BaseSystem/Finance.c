#include"database.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
EntityDictionaryDefinition* FindClient(const char name[21], database* db)
{
    int i, length = db -> finance.count;
    for( i = 0; i < length; i++)
    {
        EntityDictionaryDefinition* entity = &db -> finance.clientList[i];
        if(strcmp(entity->keyName, name) == 0)
        {
            return entity;
        }
    }
    return NULL;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
card_Information* GetCardInformation(const char name[21], const database* database)
{
    EntityDictionaryDefinition* clientHistory = FindClient(name, database);
    if(clientHistory == NULL)
        return NULL;

    return &clientHistory -> entity -> currentCardInformation;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
void InitalizeNewEntity(database* db)
{
    // 1) get a valid name buffer
    char CardholderName[21];
    do {
        GetUserInput(CardholderName, 21, "Enter New Client's Name");
    } while (!isInputValid(CardholderName, 20));

    // 2) allocate a new Entity on the heap
    Entity* newEnt = malloc(sizeof(Entity));
    if (!newEnt) {
        fprintf(stderr, "Error: out of memory\n");
        return;
    }
    memset(newEnt, 0, sizeof(*newEnt));

    strcpy(newEnt->ClientName, CardholderName);
    newEnt->currentCardInformation = InitalizeNewCardInfomration(CardholderName);
    newEnt->BillingInformation = InitalizeNewBillingInformaTion();

    int idx = db->finance.count;
    if (idx >= maxHistoryCount) {
        printf("Client list full!\n");
        free(newEnt);
        return;
    }

    EntityDictionaryDefinition* entry = &db->finance.clientList[idx];
    strcpy(entry->keyName, CardholderName);
    entry->entity = newEnt;
    entry->index  = idx;

    db->finance.count++;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
billing_Info InitalizeNewBillingInformaTion()
{
    billing_Info BillingInformation = {0};

    char billAddress[26], cntry[16], city[16], state[16], postalCode[6];

    GetUserInput(billAddress, 26, "Enter address");
    strcpy(BillingInformation.BillingAddress, billAddress);
    while (!isInputValid(billAddress, 21) != 0) {
        GetUserInput(billAddress, 26, "Enter address");
        strcpy(BillingInformation.BillingAddress, billAddress);
    }

    GetUserInput(postalCode, 5, "Enter post code");
    BillingInformation.postalCode = ConvertStringToInt(postalCode);
    while(!isInputValid(postalCode, 5) != 0)
    {
        GetUserInput(postalCode, 5, "Enter post code");
        BillingInformation.postalCode = ConvertStringToInt(postalCode);
    }

    GetUserInput(cntry, 16, "Enter country");
    strcpy(BillingInformation.Country, cntry);
    while(!isInputValid(cntry, 16) != 0)
    {
        GetUserInput(cntry, 16, "Enter country");
        strcpy(BillingInformation.Country, cntry);
    }

    GetUserInput(city, 16, "Enter City");
    strcpy(BillingInformation.City, city);
    while(!isInputValid(city, 16) != 0)
    {
        GetUserInput(city, 16, "Enter City");
        strcpy(BillingInformation.City, city);
    }

    GetUserInput(state, 16, "Enter State");
    strcpy(BillingInformation.State, state);
    while(!isInputValid(state, 16) != 0)
    {
        GetUserInput(state, 16, "Enter State");
        strcpy(BillingInformation.State, state);
    }

    return BillingInformation;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
card_Information* InitalizeNewCardInfomration(char* CardholderName[21])
{
    card_Information newCard = {0};

    char* BrandName[21], CreditCardNumber[17],
    ExpiryMonth[3], ExpiryYear[5], SecurityCode[5];

    GetUserInput(BrandName, 21, "Enter Card Provider's Name");
    strcpy(newCard.brandName, BrandName);
    while(!isInputValid(BrandName, 21) != 0)
    {
        GetUserInput(BrandName, 21, "Enter Card Provider's Name");
        strcpy(newCard.brandName, BrandName);
    }

    GetUserInput(CreditCardNumber, 17, "Enter CreditCard Number");
    newCard.CreditCardNumber = ConvertStringToInt(CreditCardNumber);
    while(!isInputValid(BrandName, 17) != 0)
    {
        GetUserInput(CreditCardNumber, 17, "Enter CreditCard Number");
        newCard.CreditCardNumber = ConvertStringToInt(CreditCardNumber);
    }

    expiry_Date newExpiry_Date;

    GetUserInput(ExpiryMonth, 3, "Enter CreditCard's Month of Expiry");
    newExpiry_Date.month = ConvertStringToInt(ExpiryMonth);
    while(!isInputValid(ExpiryMonth, 3) != 0)
    {
        GetUserInput(ExpiryMonth, 3, "Enter CreditCard's Month of Expiry");
        newExpiry_Date.month = ConvertStringToInt(ExpiryMonth);
    }

    GetUserInput(ExpiryYear, 5, "Enter CreditCard's Year of Expiry");
    newExpiry_Date.year = ConvertStringToInt(ExpiryYear);
    while(!isInputValid(ExpiryYear, 5) != 0)
    {
        GetUserInput(ExpiryYear, 5, "Enter CreditCard's Year of Expiry");
        newExpiry_Date.year = ConvertStringToInt(ExpiryYear);
    }

    newCard.expireDate = newExpiry_Date;

    GetUserInput(SecurityCode, 5, "Enter CreditCard's Month of Expiry");
    newCard.SecurityCode = ConvertStringToInt(ExpiryMonth);
    while(isInputValid(SecurityCode, 5) != 0)
    {
        GetUserInput(SecurityCode, 5, "Enter CreditCard's Month of Expiry");
        newCard.SecurityCode = ConvertStringToInt(ExpiryMonth);
    }

    return &newCard;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void ProcessNewOrder(const database* database)
{
    char* ClientName[21];
    int choice;

    GetUserInput(ClientName, 21, "Enter client's name");

    Entity client = *FindClient(ClientName, database);

    if(client == NULL)
    {
        printf("\n Client not found in system. Would you like to inialize new client?"
            "\n1. Yes"
            "\n2. No\n ");

        int choice;
        int result = scanf("%d", &choice);
        if (result == 1)
        {
            switch(choice)
            {
                case 1:
                    client = InitalizeNewEntity(database);
                    break;

                case 2:
                    printf("\n returning to finance menu...");
                    printFinanceMenu(database);
                    break;

                default:
                printFinanceMenu(database);
                break;
            }
        }
    }

    InvntoryItem* invItem;
    ProduceStockItemList_Terminal();
    int amount, uniqueStockID;
    printf("\n Enter the Unique Stock ID of the item ordered\n ");
    scanf("%d", &choice);
    invItem = GetInventoryItem(uniqueStockID, database);

    if(invItem == NULL)
    {
        printf("\n Stock ID invalid... terminating operation and returning to menu");
        //return to previous menu
        return;
    }

    printf("\n Enter amount ordered\n ");
    scanf("%d", &amount);
    float cost = amount * item -> stock.sellingPrice;
    printf("\n%s has order %d of %s for %f ", client.ClientName, amount, invItem-> stock.stockName);
    RemoveAmountFromStocckTotal(amount, invItem);
    database->finance.totalBalance += cost;
    SaveDatabase(database, database->dbFileName);
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void DeleteClient(const char ClientName[21], database* database)
{
    EntityDictionaryDefinition* client = FindClient(ClientName, database);
    int clientToDelete_Index = client->index;
    database -> finance.clientList[clientToDelete_Index].entity = NULL;
    ReorderList(clientToDelete_Index, database);
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void ReorderList(int removedElement, database* database)
{
    int length = database->finance.count;
    database -> finance.clientList[removedElement].entity = NULL;
    for(int i = removedElement; i < length - 1; i++)
    {

        EntityDictionaryDefinition entity = database -> finance.clientList[i + 1];
        database -> finance.clientList[i] = entity;
    }
    database -> finance.clientList[length-2].entity = NULL;
    database -> finance.count--;
}

void DisplayClientList_Terminal(const database* database){

    if (database->finance.count == 0){
        printf("The Client list is Empty\n");
        return;
    }

    printf("\nEntity"                           "Card Information"                          "Billing Address"                   "Phone Number\n");
    printf("-------------------- ---------------------------------------- -------------------------------------------------- -------------------------\n");

    printf("%20s %-15s %-18s %-10s %-12s %-15s %-15s %-15s %-15s %-12s %-12s %-15s\n",
           "Client Name", "Brand Name", "CreditCard Number", "Expiry Date", "Security Code",
           "Billing Address", "Country", "City", "State", "PostalCode", "Country Code", "Phone Number");

    printf("-------------------- --------------- ------------------ ---------- ------------ --------------- --------------- --------------- --------------- ------------ ------------ ---------------\n");

    int i;
    for (int i = 0; i < database->finance.count; ++i){

        if (database->finance.clientList[i].entity == NULL){
            continue;

        }
        Entity* client = database->finance.clientList[i].entity;

        char expiryDate[10];
        printf("expiryDate, %02d/%02d",
               client->currentCardInformation.expireDate.month
               client->currentCardInformation.expireDate.year % 100);

        printf("%-20s %-15s %-16d %-10s %-12d ",
               client->ClientName,
               client->currentCardInformation.brandName,
               client->currentCardInformation.CreditCardNumber,
               expiryDate,
               client->currentCardInformation.SecurityCode);




        if (client->count > 1){
            printf("%-15s %-15s %-15s %-15s %-12d %-12d %-15d\n",
                   client-> &BillingInformation.BillingAddress,
                   client-> &BillingInformation.Country,
                   client-> &BillingInformation.City,
                   client-> &BillingInformation.State,
                   client-> &BillingInformation.PostalCode,
                   client-> &BillingInformation.PhoneNumber.countryCode,
                   client-> &BillingInformation.PhoneNumber.phoneNumber);

        }else{
            printf("%-15s %-15s %-15s %-15s %-12s %-12s %-15s\n",
                   "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A");
        }



    }
    printf("-------------------- --------------- ---------------- ---------- ------------ --------------- --------------- --------------- --------------- ------------ ------------ ---------------\n");
}

void Clientlist_TextFile(const database* database){
    FILE* file = fopen("output/clientinformation.txt", "w");

    if (file == NULL){
        printf("Error for Opening file for Writing\n");
        return;
    }

    if (database->finance.count == 0){
        fprintf("The Client list is Empty\n");
        fclose(file);
        printf("File created: output/clientinformation.txt\n");
        return;
    }

    fprintf("\nEntity"                           "Card Information"                          "Billing Address"                   "Phone Number\n");
    fprintf("-------------------- ---------------------------------------- -------------------------------------------------- -------------------------\n");

    fprintf("%20s %-15s %-18s %-10s %-12s %-15s %-15s %-15s %-15s %-12s %-12s %-15s\n",
           "Client Name", "Brand Name", "CreditCard Number", "Expiry Date", "Security Code",
           "Billing Address", "Country", "City", "State", "PostalCode", "Country Code", "Phone Number");

    fprintf("-------------------- --------------- ------------------ ---------- ------------ --------------- --------------- --------------- --------------- ------------ ------------ ---------------\n");

    int i;
    for (int i = 0; i < database->finance.count; ++i){
        if (database->finance.clientList[i].entity == NULL){
            continue;

        }
        Entity* client = database->finance.clientList[i].entity;

        char expiryDate[10];
        printf("expiryDate, %02d/%02d",
               client->currentCardInformation.expireDate.month
               client->currentCardInformation.expireDate.year % 100);

        fprintf("%-20s %-15s %-16d %-10s %-12d ",
               client->ClientName,
               client->currentCardInformation.brandName,
               client->currentCardInformation.CreditCardNumber,
               expiryDate,
               client->currentCardInformation.SecurityCode);




        if (client->count > 1){
            fprintf("%-15s %-15s %-15s %-15s %-12d %-12d %-15d\n",
                   client-> &BillingInformation.BillingAddress,
                   client-> &BillingInformation.Country,
                   client-> &BillingInformation.City,
                   client-> &BillingInformation.State,
                   client-> &BillingInformation.PostalCode,
                   client-> &BillingInformation.PhoneNumber.countryCode,
                   client-> &BillingInformation.PhoneNumber.phoneNumber);


        }else{
            printf("%-15s %-15s %-15s %-15s %-12s %-12s %-15s\n",
                   "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A");

        }

    }

        fprintf("-------------------- --------------- ---------------- ---------- ------------ --------------- --------------- --------------- --------------- ------------ ------------ ---------------\n");

        fclose(file);
        printf("Client information is saved and stored in output/clientinformation.txt file successfully\n");
}
