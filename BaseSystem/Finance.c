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
        if(entity -> keyName == name)
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
/*--------------------------------------------------------------*/
void InitalizeNewEntity(database* db)
{
    /* inalizes new Entity variable who's fields are set to default values    */
    Entity newEntity = {0};

    /*    initalize client Name    */
    char* CardholderName[21];
    GetUserInput(CardholderName, 21, "Enter New Client's Name");
    if(isInputValid(CardholderName, 21) != 0)
        strcpy(newEntity.ClientName, CardholderName);

    /*    initalize client card information    */
    newEntity.currentCardInformation = *InitalizeNewCardInfomration(CardholderName);
    strcpy(newEntity.currentCardInformation.cardholderName, CardholderName);
    /*
    db->finance.clientList[db->finance.count++] = newEntity;
    */
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
card_Information* InitalizeNewCardInfomration(char* CardholderName[21])
{
    /* TODO: MUST COMPLETE THIS FUNCTION!!! NOT YET COMPLETE */
    card_Information newCard = {0};

    char* BrandName[21], CreditCardNumber[17],
    ExpiryMonth[3], ExpiryYear[5], SecurityCode[5];

    GetUserInput(BrandName, 21, "Enter Card Provider's Name");
    if(isInputValid(BrandName, 21) != 0)
        strcpy(newCard.brandName, BrandName);

    GetUserInput(CreditCardNumber, 17, "Enter CreditCard Number");
    if(isInputValid(BrandName, 17) != 0)
        newCard.CreditCardNumber = ConvertStringToInt(CreditCardNumber);

    expiry_Date newExpiry_Date;

    GetUserInput(ExpiryMonth, 3, "Enter CreditCard's Month of Expiry");
    if(isInputValid(ExpiryMonth, 3) != 0)
        newExpiry_Date.month = ConvertStringToInt(ExpiryMonth);

    GetUserInput(ExpiryYear, 5, "Enter CreditCard's Year of Expiry");
    if(isInputValid(ExpiryYear, 5) != 0)
        newExpiry_Date.year = ConvertStringToInt(ExpiryYear);

    GetUserInput(SecurityCode, 5, "Enter CreditCard's Month of Expiry");
    if(isInputValid(SecurityCode, 5) != 0)
        newCard.SecurityCode = ConvertStringToInt(ExpiryMonth);

    return &newCard;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void ProcessNewOrder(const char ClientName[21], recipt newOrder, const database* database)
{
    EntityDictionaryDefinition historyToUpdate = *FindClient(ClientName, database);
    int emptyIndex = historyToUpdate.index;
    emptyIndex++;
}

void DeleteClient(const char ClientName[21], database* database)
{
    EntityDictionaryDefinition* client = FindClient(ClientName, database);
    int clientToDelete_Index = client->index;
    database -> finance.clientList[clientToDelete_Index].entity = NULL;
    ReorderList(clientToDelete_Index, database);
}

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




