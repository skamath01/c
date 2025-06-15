#include <stdio.h>
#include <stdlib.h>
#define FILENAME "expenses.txt"

void addExpense() 
{
    char desc[50];
    float amount;
    FILE *fp = fopen(FILENAME, "a");

    if (fp == NULL) 
    {
        printf("File not found.\n");
        return;
    }

    printf("\n Enter description: ");
    scanf(" %[^\n]", desc);       // Read string with spaces

    printf("\n Enter amount: ");
    scanf("%f", &amount);

    fprintf(fp, "%s %.2f\n", desc, amount);
    fclose(fp);

    printf("\n Expense added!\n");
}

void viewExpenses() 
{
    char desc[50];
    float amount;
    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL) 
    {
        printf("\n No expenses found.\n");
        return;
    }

    printf("\n--- All Expenses ---\n");
    while (fscanf(fp, "%s %f", desc, &amount) != EOF) 
    {
        printf("%-20s %.2f\n", desc, amount);
    }
    fclose(fp);
}

void totalExpenses() 
{
    char desc[50];
    float amount, total = 0;
    FILE *fp = fopen(FILENAME, "r");

    if (fp == NULL) 
    {
        printf("\n No expenses found.\n");
        return;
    }

    while (fscanf(fp, "%s %f", desc, &amount) != EOF) 
    {
        printf("%-20s %.2f\n", desc, amount);
        total =total + amount;
    }
    fclose(fp);
    printf("Total Expenses:     %.2f \n", total);
}

int main() 
{
    int choice;
     printf("\n    Github :skamath01 \n\n");

    do 
    {
        printf("\n=== Daily Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addExpense();
        else if (choice == 2)
            viewExpenses();
        else if (choice == 3)
            totalExpenses();
        else if (choice == 4)
            printf("\n THANK YOU!!\n");
        else
            printf("\n Invalid choice. Try again.\n");

    } 
    while (choice != 4);
    return 0;
}