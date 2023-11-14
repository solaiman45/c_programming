/*
* A program that formats information entered by the user into a table
*   Item        Unit        Purchase
*               Price       Date
*   583         $  13.50    10/24/2010
*/



#include <stdio.h>


int main(void)
{
    int item, m, d, y;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("    \t\tPrice\t\tDate\n");
    printf("%-d\t\t$%7.2f\t%-2d/%-2d/%-d", item, price, m, d, y);


    return 0;
}