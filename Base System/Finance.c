#include"finance.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
EntityDictionaryDefinition* FindClient(const char name[21], const Database* database)
{
    int i, length = database -> count;
    for( i = 0; i < length; i++)
    {
        EntityDictionaryDefinition* entity = database -> finance -> clientList[i];
        if(entity.keyName == name)
        {
            return entity;
        }
    }
    return null;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
card_Information* GetCardInformation(const char name[21], const Database* database)
{
    Entity clientHistory = FindClient(name, database);
    if(clientHistory == null)
        return null;

    return CardInformation* cardInformation = clientHistory -> cardInformation;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void InitalizeNewEntity(Database* database)
{
    /* inalizes new Entity variable who's fields are set to default values    */
    Entity newEntity = {0};

    /*    initalize client Name    */
    char* CardholderName[21];
    GetUserInput(CardholderName, 21, "Enter New Client's Name");
    if(isInputValid(CardholderName, 21) != 0)
        strcpy(newEntity.ClientName, CardholderName);

    /*    initalize client card information    */
    newEntity. = InitalizeNewCardInfomration(CardholderName);
    strcpy(newEntity.cardInformation.cardholderName&, CardholderName);
    database -> finance -> clientList[ database -> count ] = newEntity;
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
    card_Information newCard;

    char* BrandName[21], CreditCardNumber[17],
    ExpiryMonth[3], ExpiryYear[5], SecurityCode[5];

    GetUserInput(BrandName, 21, "Enter Card Provider's Name");
    if(isInputValid(BrandName, 21) != 0)
        strcpy(newCard.brandName, BrandName);

    GetUserInput(CreditCardNumber, 17, "Enter CreditCard Number");
    if(isInputValid(BrandName, 17) != 0)
        newcard.CreditCardNumber = ConvertStringToInt(CreditCardNumber);

    expiry_Date newExpiry_Date;

    GetUserInput(ExpiryMonth, 3, "Enter CreditCard's Month of Expiry");
    if(isInputValid(ExpiryMonth, 3) != 0)
        newExpiry_Date.month = ConvertStringToInt(ExpiryMonth);

    GetUserInput(ExpiryYear, 5, "Enter CreditCard's Year of Expiry");
    if(isInputValid(ExpiryYear, 5) != 0)
        newExpiry_Date.year = ConvertStringToInt(ExpiryYear);

    GetUserInput(SecurityCode, 5, "Enter CreditCard's Month of Expiry");
    if(isInputValid(SecurityCode, 5) != 0)
        newcard.SecurityCode = ConvertStringToInt(ExpiryMonth);

    return newCard;
}


/*--------------------------------------------------------------*/
/*  Author: Nestor Batoon
    Function:

    Input:

    Output:						*/
/*--------------------------------------------------------------*/
void ProcessNewOrder(const char ClientName[21], Recipt newOrder, const Database* database)
{
    Entity historyToUpdate* = FindClient(ClientName, database);
    int emptyIndex* = historyToUpdate -> count;
    historyToUpdate -> recipt[emptyIndex] = newOrder;
    emptyIndex++;
}

void DeleteClient(const char ClientName[21], Database* database);
{
    EntityDictionaryDefinition* client = FindClient(ClientName, database);
    int clientToDelete_Index = client->count;
    database -> finance-> clientList[clientToDelete_Index] = null;
    ReorderList(clientToDelete_Index, database);
}

void AddClient(Database* database)
{

}

void ReorderList(int removedElement, Database* database)
{
    int length = database -> count;
    database -> finance -> clientList[removedElement] = null;
    for(int i = removedElement; i < length - 1; i++)
    {

        EntityDictionaryDefinition entity = database -> finance -> clientList[i + 1];
        database -> finance -> clientList[i] = entity;
    }
    database -> finance -> clientList[length-2] = null;
    database -> finance-> count--;
}




