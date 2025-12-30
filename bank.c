#include <stdio.h>
#include <stdlib.h>

struct bank {
    int accNo;
    char name[50];
    float balance;
};

struct bank b[100];
int count = 0;

void createAccount() {
    printf("\nEnter Account Number: ");
    scanf("%d", &b[count].accNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", b[count].name);

    printf("Enter Initial Balance: ");
    scanf("%f", &b[count].balance);

    count++;
    printf("\nAccount Created Successfully!\n");
}

void deposit() {
    int acc, i, found = 0;
    float amt;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Amount to Deposit: ");
    scanf("%f", &amt);

    for (i = 0; i < count; i++) {
        if (b[i].accNo == acc) {
            b[i].balance += amt;
            found = 1;
            printf("\nAmount Deposited Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nAccount Not Found!\n");
}

void withdraw() {
    int acc, i, found = 0;
    float amt;

    printf("\nEnter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amt);

    for (i = 0; i < count; i++) {
        if (b[i].accNo == acc) {
            if (b[i].balance >= amt) {
                b[i].balance -= amt;
                printf("\nWithdrawal Successful!\n");
            } else {
                printf("\nInsufficient Balance!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nAccount Not Found!\n");
}

void display() {
    int i;

    printf("\n--- Account Details ---\n");

    for (i = 0; i < count; i++) {
        printf("\nAccount No: %d", b[i].accNo);
        printf("\nName: %s", b[i].name);
        printf("\nBalance: %.2f\n", b[i].balance);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====");
        printf("\n1. Create Account");
        printf("\n2. Deposit");
        printf("\n3. Withdraw");
        printf("\n4. Display Accounts");
        printf("\n5. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!");
        }
    } while (choice != 5);

    return 0;
}
