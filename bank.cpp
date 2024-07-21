#include <stdio.h>
#include <stdlib.h>


int max_accounts = 5;
int pins[5] = {0, 0, 0, 0, 0};
int balances[5] = {0, 0, 0, 0, 0};
int acctno[5]={0,0,0,0,0};
char names[5][50];  //Decleared arrays that store the data of 5 different users

void displayMenu() {//function to display menu to user
    printf("----------Bank Management System----------\n");
    printf("\t 1. Create Account\n");
    printf("\t 2. Deposit amount\n");
    printf("\t 3. Withdraw amount\n");
    printf("\t 4. Check Balance\n");
    printf("\t 5. EXIT\n");
    printf("\t 6. Transfer Money\n");
    printf("-------------------------------------------\n");
}

void createAccount() {//it would allow user to create account
    
    long mbl;
     char address[50];
    printf("Welcome to account creation option ");

    int index;
    for (index = 0; index < max_accounts && pins[index] != 0; ++index);//loop iterates until all sers create acct

    if (index < max_accounts) {
getchar();
printf("Enter your name please: ");
fgets(names[index],50,stdin);
printf("Enter your address Mr %s: ",names[index]);
    fgets(address, 50, stdin);

    printf("Enter your phone number Mr %s : ",names[index]);
    scanf("%ld", &mbl);
printf("Enter your acctno: ");
    scanf("%d", &acctno[index]);
        printf(" Mr %s please Enter 4 digit pin for account %d: ", names[index],acctno[index]);
        scanf("%d", &pins[index]);

    // strcpy(names[index], name); // Store the name for the account

        // Print account creation receipt
        printf("\n-------------------\n");
        printf("   ACCOUNT RECEIPT\n");
        printf("-------------------\n");
        printf("Account Holder: %s\n", names[index]);
        printf("Account Number: %d\n", acctno[index]);
        printf("Mobile Number : %ld\n", mbl);
        printf("Address      : %s", address);
        printf("PIN            : %04d\n", pins[index]); // aince it is a 4 digit pin.
        printf("-------------------\n");
        printf("Account created successfully.\n");
        printf("-------------------\n");
    } else {
        printf("--------Sorry, Maximum number of accounts reached----------\n");
    }
}

void deposit() {//allows user to deposit money in his account
    int index, pass;
    printf("Enter account index: ");
    scanf("%d", &index);

    if (index >= 0 && index < max_accounts && pins[index] != 0) {
    pin:
        printf("Enter 4 digit pin: ");
        scanf("%d", &pass);

        if (pass == pins[index]) {
            printf("Enter amount to deposit: ");
            int amount;
            scanf("%d", &amount);
            balances[index] += amount;

            // Print deposit receipt
            printf("\n-------------------\n");
            printf("      DEPOSIT RECEIPT\n");
            printf("-------------------\n");
            printf("Account Holder: %s\n", names[index]);
            printf("Account Number: %d\n", acctno[index]);
            printf("Amount Deposited: %d\n", amount);
            printf("New Balance: %d\n", balances[index]);
            printf("-------------------\n");
            printf("Deposit successful\n");
            printf("-------------------\n");//after successful deposition a receipt would be produced
        } else {
            printf("Wrong pin\n");
            goto pin;
        }
    } else {
        printf("Invalid account index\n");
    }
}

void withdraw() {//allows user to withdraw money from account
    int index, pass;
    printf("Enter account index: ");
    scanf("%d", &index);

    if (index >= 0 && index < max_accounts && pins[index] != 0) {
        printf("Enter 4 digit pin: ");
        scanf("%d", &pass);

        if (pass == pins[index]) {
            printf("Enter amount to withdraw: ");
            int amount;
            scanf("%d", &amount);

            if (amount <= balances[index]) {
                balances[index] -= amount;

                // Print withdrawal receipt
                printf("\n-------------------\n");
                printf("   WITHDRAW RECEIPT\n");
                printf("-------------------\n");
                printf("Account Holder: %s\n", names[index]);
                printf("Account Number: %d\n", acctno[index]);
                printf("Amount Withdrawn: %d\n", amount);
                printf("New Balance: %d\n", balances[index]);
                printf("-------------------\n");
                printf("Withdrawal successful\n");
                printf("-------------------\n");
            } else {
                printf("Insufficient balance\n");
            }
        } else {
            printf("Wrong pin\n");
        }
    } else {
        printf("Invalid account index\n");
    }
}

void checkBalance() {//allows user to check hi cuurent balance 
    int index, pass;
    printf("Enter account index: ");
    scanf("%d", &index);


    if (index >= 0 && index < max_accounts && pins[index] != 0) {
        printf("Enter 4 digit pin: ");
        scanf("%d", &pass);

        if (pass == pins[index]) {
            // Print balance receipt
            printf("\n-------------------\n");
            printf(" BALANCE ENQUIRY\n");
            printf("-------------------\n");
            printf("Account Holder: %s\n", names[index]);
            printf("Account Number: %d\n", acctno[index]);
            printf("Balance: %d\n", balances[index]);
            printf("-------------------\n");
        } else {
            printf("Wrong pin\n");
        }
    } else {
        printf("Invalid account index\n");
    }
}

void transfer() {//allow user to send money
    int sourceIndex, destIndex, pass;
    printf("Enter  account index you want to send money from : ");//soucendex is sender index and destIndex is receiver index
    scanf("%d", &sourceIndex);
    

    if (sourceIndex >= 0 && sourceIndex < max_accounts && pins[sourceIndex] != 0) {
    pin:
        printf("Enter 4 digit pin for source account: ");
        scanf("%d", &pass);

        if (pass == pins[sourceIndex]) {
            printf("Enter account index you want to send money to : ");
            scanf("%d", &destIndex);

            if (destIndex >= 0 && destIndex < max_accounts) {
                printf("Enter amount to transfer: ");
                int amount;
                scanf("%d", &amount);

                if (amount <= balances[sourceIndex]) {
                    balances[sourceIndex] -= amount;
                    balances[destIndex] += amount;
                    printf("\n-------------------\n");
            printf(" TRANSFER REACEIPT \n");
            printf("-----------------------\n");
            printf("SENDER : %s\n", names[sourceIndex]);
            printf("RECEIVER: %s\n", names[destIndex]);
            printf("SENDER ACCOUNT: %d\n",acctno[sourceIndex]);
            printf("RECEIVER ACCOUNT: %d\n",acctno[destIndex]);
            printf("Balance of sender: %d\n", balances[sourceIndex]);
            printf("Balance of receiver: %d\n", balances[destIndex]);
            printf("------------------------\n");
                    

                } else {
                    printf("Insufficient balance in source account\n");
                }
            } else {
                printf("Invalid destination account index\n");
            }
        } else {
            printf("Wrong pin for source account\n");
            goto pin;
        }
    } else {
        printf("Invalid source account index\n");
    }
}

int main() {
    int choice;
    system("color 73");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("-----------Thank you for using our service-------------\n");
                break;
            case 6:
                transfer();
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}