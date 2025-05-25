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
void InitalizeNewEntity(database* db)
{
    char CardholderName[21];
    do {
        GetUserInput(CardholderName, 21, "Enter New Client's Name");
    } while (!isInputValid(CardholderName, 20));

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
    BillingInformation.PostalCode = ConvertStringToInt(postalCode);
    while(!isInputValid(postalCode, 5) != 0)
    {
        GetUserInput(postalCode, 5, "Enter post code");
        BillingInformation.PostalCode = ConvertStringToInt(postalCode);
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
card_Information InitalizeNewCardInfomration(char* CardholderName[21])
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

    return newCard;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void AddAmountToBalance(database* database)
{
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
    int amount;
    printf("\nEnter amount to add to client balance:");
    scanf("\n%d", &amount);

    client ->balance +=amount;
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void RemoveAmountFromBalance(database* database)
{
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
    int amount;
    printf("\nEnter amount to remove from client balance:");
    scanf("\n%d", &amount);

    client ->balance -=amount;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void DeleteClient(Entity client, database* database)
{
    int clientToDelete_Index = client.count;
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

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void DisplayClientList_Terminal(const database* database){

    if (database->finance.count == 0){
        printf("The Client list is Empty\n");
        return;
    }

    printf("%20s %-15s %-15s %-18s %-10s %-12s %-15s %-15s %-15s %-15s %-12s %-12s %-15s\n",
           "Client Name", "Balance", "Brand Name", "CreditCard Number", "Expiry Date", "Security Code",
           "Billing Address", "Country", "City", "State", "PostalCode", "Country Code", "Phone Number");

    printf("-------------------- --------------- --------------- ------------------ ---------- ------------ --------------- --------------- --------------- --------------- ------------ ------------ ---------------\n");

    int i;
    for (int i = 0; i < database->finance.count; ++i){

        if (database->finance.clientList[i].entity == NULL){
            continue;

        }
        Entity* client = database->finance.clientList[i].entity;

        char expiryDate[10];
        printf("expiryDate, %02d/%02d",
               client->currentCardInformation.expireDate.month,
               client->currentCardInformation.expireDate.year % 100);

        printf("%-20s %-15s %-16d %-10s %-12d ",
               client->ClientName,
               client->currentCardInformation.brandName,
               client->currentCardInformation.CreditCardNumber,
               expiryDate,
               client->currentCardInformation.SecurityCode);




        if (client->count > 1){
            printf("%-15s %-15s %-15s %-15s %-12d %-12d %-15d\n",
                   client-> BillingInformation.BillingAddress,
                   client-> BillingInformation.Country,
                   client-> BillingInformation.City,
                   client-> BillingInformation.State,
                   client-> BillingInformation.PostalCode);

        }else{
            printf("%-15s %-15s %-15s %-15s %-12s %-12s %-15s\n",
                   "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A");
        }
    }
    printf("-------------------- --------------- --------------- ---------------- ---------- ------------ --------------- --------------- --------------- --------------- ------------ ------------ ---------------\n");
}

/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void Clientlist_TextFile(const database* database){
    FILE* file = fopen("output/clientinformation.txt", "w");

    if (file == NULL){
        printf("Error opening file for writing\n");
        return;
    }

    if (database->finance.count == 0){
        fprintf(file, "The Client list is empty.\n");
        fclose(file);
        printf("File created: output/clientinformation.txt\n");
        return;
    }

    fprintf(file, "%-20s %-15s %-20s %-20s %-10s %-14s %-20s %-15s %-15s %-15s %-12s %-14s %-15s\n",
            "Client Name", "Balance", "Brand Name", "Credit Card Number", "Exp Date", "Security Code",
            "Billing Address", "Country", "City", "State", "Postal Code", "Country Code", "Phone Number");

    fprintf(file, "-------------------- --------------- -------------------- -------------------- ---------- -------------- -------------------- --------------- --------------- --------------- ------------ -------------- ---------------\n");

    for (int i = 0; i < database->finance.count; ++i){
        if (database->finance.clientList[i].entity == NULL){
            continue;
        }

        Entity* client = database->finance.clientList[i].entity;

        // Format expiry date
        char expiryDate[6];
        snprintf(expiryDate, sizeof(expiryDate), "%02d/%02d",
                 client->currentCardInformation.expireDate.month,
                 client->currentCardInformation.expireDate.year % 100);

        fprintf(file, "%-20s %-15.2f %-20s %-20d %-10s %-14d ",
                client->ClientName,
                client->balance,
                client->currentCardInformation.brandName,
                client->currentCardInformation.CreditCardNumber,
                expiryDate,
                client->currentCardInformation.SecurityCode);

        // Write billing info
        if (client->BillingInformation.BillingAddress != NULL){
            fprintf(file, "%-20s %-15s %-15s %-15s %-12d %-14d %-15d\n",
                    client->BillingInformation.BillingAddress,
                    client->BillingInformation.Country,
                    client->BillingInformation.City,
                    client->BillingInformation.State,
                    client->BillingInformation.PostalCode);
        } else {
            fprintf(file, "%-20s %-15s %-15s %-15s %-12s %-14s %-15s\n",
                    "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A");
        }
    }

    fprintf(file, "-------------------- --------------- -------------------- -------------------- ---------- -------------- -------------------- --------------- --------------- --------------- ------------ -------------- ---------------\n");
    fclose(file);
    printf("Client information successfully saved to output/clientinformation.txt\n");
}
