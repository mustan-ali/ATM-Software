#include <stdio.h>
#include <stdbool.h>
#include<time.h>     // Library used to output random numbers
#include <Windows.h> // Library used to add time delay


//Function Prototype
void mainMenu();
void checkBalance(int);
int moneyDeposit(int);
int moneyWithdraw(int);
int moneyTransfer(int);
void menuExit();
void errorMessage();
int billPayment(int);
int atmPin();



int main()
{
    srand(time(0));     //using this function for random outputs

    int option,choose;
    int balance = rand()%(15000 - 5000 +1) + 15000;
    bool again = true;

    atmPin();
    sleep(2);  //Adding delay

    system("CLS");
    while (again)
    {
        mainMenu();

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Your Selection:\t");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("CLS");
            checkBalance(balance);
            break;
        case 2:
            system("CLS");
            balance = moneyDeposit(balance);
            break;
        case 3:
            system("CLS");
            balance = moneyWithdraw(balance);
            break;
        case 4:
            system("CLS");
            balance=moneyTransfer(balance);
            break;
        case 5:
            system("CLS");
            balance = billPayment(balance);
            break;
        case 6:
            system("CLS");
            menuExit();
            return 0;
        default:
            errorMessage();
            break;
        }

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n[1] Yes\n[2] No\n");
        scanf("%d", &choose);

        system("CLS");
        if (choose == 2)
        {
            again = false;
            menuExit();
        }
    }
    return 0;
}



//Functions

void mainMenu()
{
    printf("***************Welcome to ATM***************\n");
    printf("***Please choose one of the options below***\n\n");
    printf(" [1]  Check Balance\n");
    printf(" [2]  Deposit\n");
    printf(" [3]  Withdraw\n");
    printf(" [4]  Transfer Money\n");
    printf(" [5]  Bill Payment\n");
    printf(" [6]  Exit\n\n");
}

void checkBalance(int balance)
{
    printf("You Choose to See your Balance\n");
    printf("\n\nYour Available Balance is:   $%d\n\n", balance);
}

int moneyDeposit(int balance)
{
    int deposit;
    printf("You choose to Deposit a money\n");
    printf("Your Balance is: $%d\n\n", balance);
    printf("Enter your amount to Deposit\n");
    scanf("%d", &deposit);

    balance += deposit;

    printf("\nYour New Balance is:   $%d\n\n", balance);
    return balance;

}

int moneyWithdraw(int balance)
{
    int withdraw;
    bool back = true;

    printf("You choose to Withdraw a money\n");
    printf("Your Balance is: $%d\n\n", balance);

    while (back)
    {
        printf("Enter your amount to withdraw:\n");
        scanf("%d", &withdraw);


        if (withdraw <= balance)
        {
            back = false;
            balance -= withdraw;
            printf("\nYour withdrawing money is:  $%d\n", withdraw);
            printf("Your New Balance is:   $%d\n\n", balance);
        }

        else
        {
            printf("+++You don't have enough money+++\n");
            printf("Please contact to your Bank Customer Services\n");
            printf("Your Balance is:   $%d\n\n", balance);
        }
    }

    return balance;
}

int moneyTransfer(int balance)
{
    int transferAccount;
    int transferAmount;
    bool back = true;

    printf("You choose to Transfer money\n");
    printf("Your Balance is: $%d\n\n", balance);

    do
    {
        printf("Enter 6 digit Account Number to Transfer Money\n");
        scanf("%d", &transferAccount);
        if (transferAccount > 999999 || transferAccount < 100000)
        {
            printf("\nInvalid account number please enter again!\n");
        }
    }
    while(transferAccount > 999999 || transferAccount < 100000);

    while (back)
    {
        printf("\nEnter amount to transfer:\n");
        scanf("%d", &transferAmount);

        if (transferAmount <= balance)
        {
            back = false;
            balance -= transferAmount;
            printf("\nYou have transferred:  $%d\n", transferAmount);
            printf("Your New Balance is:   $%d\n\n", balance);

        }

        else
        {
            printf("\n+++You don't have enough money+++\n");
            printf("Please contact to your Bank Customer Services\n");
            printf("Your Balance is:   $%d\n\n", balance);

        }
    }
    return balance;

}


int billPayment(balance)
{
    int electricity,gas,internet,ch,accnum = 1234567890;
    char ch2;

    electricity = rand()%(1000 - 500 +1) + 500; //generating random bills
    gas = rand()%(1000 - 500 +1) + 500;
    internet = rand()%(1000 - 500 +1) + 500;

    printf("+++Bills+++\n1. Electricity\n2. Gas\n3. Internet.\n\nEnter the bill number:\n");
    do
    {
        scanf("%d",&ch);
        if (ch != 1 && ch != 2 && ch != 3)
        {
            printf("Invalid choice! Try again:\n");
        }
    }
    while(ch != 1 && ch != 2 && ch != 3);

    if (ch == 1)
    {
        printf("\nBill Details:\n>>| Account ID: %d | Amount: $%d |<<\n",accnum,electricity);
        printf("Current balance = $%d\n\n",balance);

        printf("Would you like to pay the bill now? (Y/N)\n");
        scanf("%s",&ch2);

        if ( ch2 == 'y' || ch2 == 'Y')
        {
            if (balance >= electricity)
            {
                balance -= electricity;
                printf("\n\nBill Paid\n");
                printf("Remaining balance = $%d\n",balance);
            }
            else
            {
                printf("Insufficient balance!\n");
            }
        }
    }
    else if (ch == 2)
    {
        printf("\nBill Details:\n>>| Account ID: %d | Amount: $%d |<<\n",accnum,gas);
        printf("Current balance = $%d\n\n",balance);
        printf("Would you like to pay the bill now? (Y/N)\n");
        scanf("%s",&ch2);

        if ( ch2 == 'y' || ch2 == 'Y')
        {
            if (balance >= gas)
            {
                balance -= gas;
                printf("\n\nBill Paid\n");
                printf("Remaining balance = $%d\n",balance);
            }
            else
            {
                printf("Insufficient balance!\n");
            }
        }
    }
    else if (ch == 3)
    {
        printf("\nBill Details:\n>>| Account ID: %d | Amount: $%d |<<\n",accnum,internet);
        printf("Current balance = $%d\n\n",balance);
        printf("Would you like to pay the bill now? (Y/N)\n");
        scanf("%s",&ch2);

        if ( ch2 == 'y' || ch2 == 'Y')
        {
            if (balance >= internet)
            {
                balance -= internet;
                printf("\n+++Bill Paid+++\n");
                printf("Remaining balance = $%d\n",balance);
            }
            else
            {
                printf("Insufficient balance!\n");
            }
        }
    }
    return balance;
}

int atmPin()
{
    char pin[4]= {"0000"};
    char pass[5];
    int correct=0;
    printf("Enter four digit pin:\n");

    do
    {
        scanf("%s",&pass);
        for(int i=0; i<4; i++)
        {
            if(pass[i]==pin[i])
            {
                correct++;
            }
        }
        if(correct==4)
        {
            system("CLS");
            printf("Correct Pin!");
        }
        else
        {
            correct=0;
            system("CLS");
            printf("Wrong Pin! Try again:\n");
        }
    }
    while (correct != 4);

    return 0;
}


void menuExit()
{
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
}

void errorMessage()
{
    printf("\t\tERROR\n!!!You selected an invalid number!!!\n");
}
