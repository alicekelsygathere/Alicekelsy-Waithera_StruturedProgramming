

#include <stdio.h>
double balance=1000.00;// the account balance, shared by all functions
// Asks for the PIN (3 attempts).
int login(void)
//variable declaration
{ int pin =1234;
  int userpin;
  int attempts=0;

  while(attempts < 3)

//prompt and declare pin
   {
    printf("Please enter pin\n");
    scanf("%d",&userpin);

    if(pin==userpin)

    { return 1;
    }
     attempts ++;
      printf("Wrong pin. Attempts left:%d\n",3-attempts);
   }
      return 0;
      }
   void showmenu (void) //displays menu
   {
       printf("\n==ATM menu\n");
       printf("1.Balance Inquiry\n");
       printf("2.Deposit\n");
       printf("3.Withdraw\n");
       printf("4.Exit\n");
       printf("Choose option\n");

   }
   void checkbalance(void) //show current amount balance
   {
       printf("Your balance is:%.2f\n", balance);
   }
   void deposit(double amount) //adds amount to the current balance
   {
       if (amount<=0)
       {
           printf("Invalid amount.Must be more 0\n");
       }
       else
       {   balance=balance+amount;
           printf("Deposited %.2f.New balance.%.2f\n",amount,balance);
       }
   }
   void withdraw(double amount) //subtracts amount from current balance
   {
       if (amount<=0)
       {
           printf("Invalid amount.Must be more than 0\n");
       }
       else if (amount>balance)
       {
           printf("Insufficient funds\n");
       }
       else
       {   balance=balance-amount;
           printf("Withdwraw %.2f. New balance %.2f\n" , amount, balance);
       }
   }
int main()
{  int choice;
   double amount;
     if (login() == 1)
    {
        printf("Access granted\n");
        do
        {
        showmenu();
        scanf("%d", &choice); // NEW: listen to choice picked-input from user

        switch (choice)  //look at the pick and jump to corresponding case
        {
        case 1:
            checkbalance();
            break;            //stop and the next case doesn't run
        case 2:
            printf("Enter amount to deposit\n");
            scanf("%lf",&amount);
            deposit(amount);
            break;
        case 3:
            printf("Enter amount to withdraw\n");
            scanf("%lf", &amount);
            withdraw(amount);
            break;
        case 4:
            printf("Goodbye\n");
            break;
        default:
            printf("Invalid choice\n");
        }
        }
        while (choice != 4);                        // NEW: repeat unless Exit
        }
    else
    {
        printf("Too many wrong attempts. Access denied.\n");
    }
    return 0;
}
