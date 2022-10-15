/*
 *  lesson15.3.c
 *
 *  Create a new BankCustomer structure type, which keeps track of customer ID,
 *  type of account (‘c’ for checking, ‘s’ for savings, ‘d’ for deposit), and account balance.
 *  Declare an array of 10 such customers, and read in their data from this file.
 *  At the end, write out:
 *   - The average balance for all checking accounts,
 *   - The average balance for all savings accounts, and
 *   - The average balance for all deposit accounts.
 *
 *  July 17, 2019
 *
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

typedef struct {
    int accountID;
    char accountType;
    int accountBalance;
} BankCustomer;

int main(void) {
    int i;
    FILE *file;
    BankCustomer customer[10];
    int checkingSum = 0,
        checkingCounter = 0,
        savingsSum = 0,
        savingsCounter = 0,
        depositSum = 0,
        depositCounter = 0;
    double checkingAvg = 0,
           savingsAvg = 0,
           depositAvg = 0;

    file = fopen("bank.data", "r");

    if (file == NULL) {
        printf("Error opening bank.data\n");
    }

    for (i = 0; i < 10; i++) {
        fscanf(file, "%d", &customer[i].accountID);
        fscanf(file, " %c ", &customer[i].accountType);
        fscanf(file, "%d", &customer[i].accountBalance);
    }

    for (i = 0; i < 10; i++) {
        printf("%d %c %d\n", customer[i].accountID, customer[i].accountType, customer[i].accountBalance);
    }

    for (i = 0; i < 10; i++) {
        if (customer[i].accountType == 'c') {
            checkingSum += customer[i].accountBalance;
            checkingCounter++;
        } else if (customer[i].accountType == 's') {
            savingsSum += customer[i].accountBalance;
            savingsCounter++;
        } else {
            depositSum += customer[i].accountBalance;
            depositCounter++;
        }
    }

    checkingAvg = (double)checkingSum / checkingCounter;
    savingsAvg = (double)savingsSum / savingsCounter;
    depositAvg = (double)depositSum / depositCounter;

    printf("Checking accounts average: %g\n", checkingAvg);
    printf("Savings accounts average: %g\n", savingsAvg);
    printf("Deposit accounts average: %g\n", depositAvg);

    return 0;
}
