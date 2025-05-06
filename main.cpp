#include<stdio.h>
#include<string.h>

int main(){

    return 0;
}
void printInventoryMenue(database* dataB){
    printf("\nBusiness Management System: Inventory Management System\n"
        "1.Display Inventory\n"
        "2.Add New Inventory Item\n"
        "3.Delete Inventory Item\n"
        "4.Export Inventory to Textfile\n"
        "Enter your choice>\n"
        )

void SelectedchoiceInventory(database* dataB{
    int choice;
    int selectoption = scanf("%d",choice);

    swicth(choice){
        case 1:
        DisplayInventory(Database* database);
        break;

        case 2:
        CreateNewInventoryItem(Databse* database);
        break;

        case 3:
        DeleteInventoryItem(InventoryItem* invItem, Databse* database);
        break;

        case 4:
        ProduceStockItemTextFile(cost Database* database);
        break;

        case 5:
        ProduceDeliveryInvoicTextFile(const Database* database);
        break;
        // checking my work

    }
})
    

}