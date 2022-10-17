#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
     
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:Rs.");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
     
    int sc;
    printf("Enter the acc no.");
    scanf(" %d",&sc);
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\t\t Balance\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
            if(sc== add.acc_no){
           printf("\n%6d\t %10s\t\t%10s\t\t%.0lf \t\t %f",add.acc_no,add.name,add.address,add.phone,add.amt);
            }
           test++;
       }

    fclose(view);
    if (test==0)
        {    
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
             
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                 
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                 
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {    
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
               
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                     
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
       
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
         
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {    
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs. %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {    
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:Rs.%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs..%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {    
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
               
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                         
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
             
            menu();
        }

        else
           {

              
            close();
            }

}


void menu(void)
{   int choice;
     
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

     
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:view_list();
        break;
        case 5:erase();
        break;
        default:
        break;

    }

}

int password()
{
    char pass[10],password[10]="pass";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                 
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                         
                        main();
                    }

            else if (main_exit==0)
                    {
                     
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                     
                    goto login_try;}

        }
        return 0;
}

#define MAX 10
int stack[8];

// Initialising Struct named Stack
typedef struct Stack
{
    int arr[MAX];
    int top;
} Stack;

int top = -1;

// Checking if the stack is empty
int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

// Checking if the stack is full
int isfull()
{

    if (top == MAX)
        return 1;
    else
        return 0;
}

// Inserting elements in stack in LIFO order
int push(int data)
{

    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

// Deleting elements from stack in LIFO order
int pop()
{
    int data;

    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

// Printing all the elements using traverse function
void traverse()
{
    int d;

    if (top == -1)
    {
        printf("The stack is empty.\n\n");
        return;
    }

    printf("There are %d elements in the stack.\n", top + 1);

    for (d = top; d >= 0; d--)
        printf("%d\n", stack[d]);
    printf("\n");
}

// Printing the topmost(last added) element of stack
int peek()
{
    return stack[top];
}

// Function for printing the various Investment options
//  Else-if used inside the for loop for printing
void call(int c)
{
    for (int j = 0; j < c; j++)
    {
        if (stack[j] == 1)
        {
            printf("1: Fixed Deposit\n ");
        }
        else if (stack[j] == 2)
        {
            printf("2: Mutual Funds\n");
        }
        else if (stack[j] == 3)
        {
            printf("3: Gold\n");
        }
        else if (stack[j] == 4)
        {
            printf("4: Home Loan\n");
        }
        else if (stack[j] == 5)
        {
            printf("5: Niffty\n");
        }
    }
}

// Main Function
int main()
{
    password();
    int k, x, y, a, c;

    // Taking the salary from user
    printf("\n Input salary :");
    scanf("%d", &x);

    // Taking the percentage of salary to use from user
    printf("enter percentage of salary to use: ");
    scanf("%d", &k);
    // printf("%d",k);

    // Calculating the amount from salary to be used in the investment
    y = x * (k * 0.01);
    // printf("%d",y);
    printf(" \n\n");
    // Printing the various Investment options to show to user
    printf("Investment choices:\n");
    printf("1: Fixed Deposit \n");
    printf("2: Mutual Funds \n");
    printf("3: Gold\n");
    printf("4: Home Loan\n");
    printf("5: Niffty\n");
    printf("\n");

    // Asking for total number of choices from user
    printf("Please enter total number of choices :");
    scanf("%d", &c);
    printf("\n");

    // For loop used to enter choice
    for (int i = 1; i <= c; i++)
    {
        printf("enter your %d choice:", i);
        scanf("%d", &a);
        push(a);
    }
    printf("\n");

    // Printing all the elements using traverse function
    traverse(); 

    // Initialising div to c(total number of choices)
    int div = c; 

    if (div == 1) //If number of choice is 1
    {
        printf("Your all savings is invested in \n");
        peek();
         call(div);
        printf("\n");
    }

    else if (div == 2) //If number of choices is 2
    {
        y = y * (50 * 0.01); // Income is splited into 2 equal parts
        printf("your half savings  ( Rs.%d ) will be invested equally amongst \n",y );
        pop();
        call(div);
        printf("\n");
    }

    else if (div == 3) //If number of choices is 3
    {
        y = y * (33.34 * 0.01); // Income is splited into 3 equal parts
        printf("your one third savings ( Rs.%d ) will be invested equally amongst \n", y );
        pop();
        call(div);
        printf("\n");
    }

    else if (div == 4) //If number of choices is 4
    {
        y = y * (25 * 0.01); // Income is splited into 4 equal parts
        printf("your one fourth savings (Rs.%d ) will be invested equally amongst \n ", y );
        pop();
        call(div);
        printf("\n");
    }

    else if (div == 5) //If number of choices is 5
    {
        y = y * (20 * 0.01); // Income is splited into 5 equal parts
        printf("your one fifth savings ( Rs.%d ) will be invested equally amongst \n ", y);
        pop();
        call(div);
        printf("\n");
    }
}