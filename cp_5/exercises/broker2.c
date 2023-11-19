/*
* A program that calculates a broker's commission by asking the user,
* number of shares traded and the price per share.
* The program produces an ouput as a comparison with a competing brokers commission.
*/



#include <stdio.h>


int main(void)
{
    float price, num_of_shares, value_a, value_b, commission_broker_a, commission_broker_b;

    printf("Enter the price of share: ");
    scanf("%f", &price);

    printf("Enter the number of shares: ");
    scanf("%f", &num_of_shares);

    value_a = price * num_of_shares;

    if (value_a < 2500.00f)
    {
        commission_broker_a = 30.00f + 0.017f * num_of_shares;
    }
    else if (value_a < 6250.00f)
    {
        commission_broker_a = 56.00f + 0.0066f * num_of_shares;
    }
    else if (value_a < 20000.00f)
    {
        commission_broker_a = 76.00f + 0.0034f * num_of_shares;
    }
    else if (value_a < 50000.00f)
    {
        commission_broker_a = 100.00f + 0.0022f * num_of_shares;
    }
    else if (value_a < 500000.00f)
    {
        commission_broker_a = 155.00f + 0.0011f * num_of_shares;
    } else {
        commission_broker_a = 255.00f + 0.0009f * num_of_shares;
    }

    if (commission_broker_a < 39.00f)
    {
        commission_broker_a = 39.00f;
    }

    if (value_b < 2000.00f)
    {
        commission_broker_b = 33.00f + 0.003 * num_of_shares;
    } else {
        commission_broker_b = 33.00f + 0.002 * num_of_shares;
    }

    printf("-------------------- | -------------------\n");
    printf("| Comission broker A | Comission broker B | \n");
    printf("|%12.2f\t     |%11.2f\t  |\n", commission_broker_a, commission_broker_b);
    printf("|=================== | ===================|\n");
    
    return 0;
}
