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
Entity* FindClient(const char name[21], const Database* database)
{
    int i, length = database -> count;
    for( i = 0; i < length; i++)
    {
        Entity temp =  databse -> Entity[i];
        if(strcmp(name, temp -> ClientName))
        {
            return temp;
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
    newEntity.cardInformation = InitalizeNewCardInfomration(CardholderName);
    database -> history[ database -> count ] = newEntity;
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

    char BrandName[21], CreditCardNumber[17],
    ExpiryMonth[3], ExpiryYear[5], SecurityCode[4];


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


