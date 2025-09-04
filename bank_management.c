#include <stdio.h>
#include <string.h>

struct Account {
    int acc_no;
    char name[50];
    float balance;
};

struct Account accounts[100];  // max 100 accounts
int count = 0;

// Function to create a new account
void createAccount() {
    if (count >= 100) {
        printf("Cannot create more accounts.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accounts[count].acc_no);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", accounts[count].name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &accounts[count].balance);

    count++;
    printf("Account created successfully!\n");
}

// Function to display all accounts
void displayAccounts() {
    if (count == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < count; i++) {
        printf("Acc No: %d | Name: %s | Balance: %.2f\n", 
               accounts[i].acc_no, accounts[i].name, accounts[i].balance);
    }
}

// Function to deposit money
void depositMoney() {
    int acc, found = 0;
    float amt;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < count; i++) {
        if (accounts[i].acc_no == acc) {
            printf("Enter Deposit Amount: ");
            scanf("%f", &amt);
            accounts[i].balance += amt;
            printf("Amount Deposited Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int acc, found = 0;
    float amt;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < count; i++) {
        if (accounts[i].acc_no == acc) {
            printf("Enter Withdrawal Amount: ");
            scanf("%f", &amt);

            if (accounts[i].balance >= amt) {
                accounts[i].balance -= amt;
                printf("Amount Withdrawn Successfully!\n");
            } else {
                printf("Insufficient Balance!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
}

// Function to check balance
void checkBalance() {
    int acc, found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    for (int i = 0; i < count; i++) {
        if (accounts[i].acc_no == acc) {
            printf("Acc No: %d | Name: %s | Balance: %.2f\n", 
                   accounts[i].acc_no, accounts[i].name, accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n===== Bank Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: checkBalance(); break;
            case 6: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}