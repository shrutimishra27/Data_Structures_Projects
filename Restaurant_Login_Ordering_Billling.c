#include <stdio.h>
#include <string.h>

//struct of userdetails
struct userdetails{
        char username[50];
        char email[20];
        char phonenumber[10];
        char password[12];
    };
    typedef struct userdetails USER;
    USER u;

//using nested struct (struct in struct) 
struct FoodItem //main struct
{
    struct Burger
    {
        char name[20];
        int quantity;
        float price;
    } br;   //alias name for burger

    struct Panipuri
    {
        char name[20];
        int quantity;
        float price;
    } pp;  //alias name for panipuri


    struct Pizza
    {
        char name[20];
        int quantity;
        float price;
    } pz; //alias name for pizza


    struct Sandwich
    {
        char name[20];
        int quantity;
        float price;
    } sn;  //alias name for sandwich


    struct Momos
    {
        char name[20];
        int quantity;
        float price;
    } mo;  //alias name for momos


    struct French_Fries
    {
        char name[20];
        int quantity;
        float price;
    } ff;  //alias name for french-fries


    struct Manchurian
    {
        char name[20];
        int quantity;
        float price;
    } mn;   //alias name for manchurian

} fd;

//passwordgenerator function
void passswordgenerator()
{

    printf("Your generated password is:");
    
    //using random module 
    //ASCII VALUE of A(65) to z(122)
    for (int i = 0; i < 6; i++)
    {
        int num = (rand() %(121 - 65 + 1)) +65;
        printf("%c ", (char)(num));
    }

    //printing random numbers
    for (int i = 0; i < 3; i++)
    {
        int num = (rand() % 10);
        printf("%d ", num);
    }
    //  ! 33 , @ 64 , # 35 , $ 36 , % 37 , ^ 94 , & 38 , * 42
    // this are characters used in passwords given policy by ibm

    int special[8] = {33, 64, 35, 36, 37, 94, 38, 42};
    char digit[3];
    for (int i = 0; i < 3; i++)
    {
        int randomnumber = rand() % 10;
        digit[i] = (char)(special[randomnumber]);
        printf("%c ", digit[i]);
    }
}

//login function
void login(){
    
    printf("Enter your name: ");
    gets(u.username);

    printf("enter your email Id: ");
    gets(u.email);

    printf("Enter your phone number : ");
    gets(u.phonenumber);

    printf("\n");
    printf("\n");
    printf("\t\t\t WELCOME TO HOTEL VINAYAK");
    printf("\nUSER-NAME: %s",u.username);
    printf("\nE-MAIL:  %s",u.email);
    printf("\nPHONE-NUMBER: %s",u.phonenumber);
    printf("\n");

}

void menu()  // function for menu-card
{
    // declaring the given food item and its price

    strcpy(fd.br.name, "Burger");  
    fd.br.price = 50.00;

    strcpy(fd.pp.name, "Panipuri");
    fd.pp.price = 20.00;

    strcpy(fd.pz.name, "Pizza");
    fd.pz.price = 299.00;

    strcpy(fd.sn.name, "Sandwich");
    fd.sn.price = 120.00;

    strcpy(fd.mo.name, "Momos");
    fd.mo.price = 70.00;

    strcpy(fd.ff.name, "French-Fries");
    fd.ff.price = 79.00;

    strcpy(fd.mn.name, "Manchurian");
    fd.mn.price = 130.00;

    //printing the menu card
    printf("\n\n |######################## Hotel Vinayak  #############################|\n");
    printf("\n                        ____________ Menu Card  _________________\n\n");

    printf("\n              1) BURGER                             50.00Rs\n");
    printf("\n              2) PANIPURI                           20.00Rs\n");
    printf("\n              3) PIZZA                              299.00Rs\n");
    printf("\n              4) SANDWICH                           120.00Rs\n");
    printf("\n              5) MOMOS                              70.00Rs\n");
    printf("\n              6) FRENCH-FRIES                       79.00Rs\n");
    printf("\n              7) MUNCHURIAN                         130.00Rs\n");
    printf("\n              0) TO EXIT FROM MENU\n");

    printf("\n------------------------------------------------------------------------------\n");

    int  m, flag = 1, n;
    
    //Establishing switch case in while loop
    while (flag)
    {
        printf("Enter the item number: ");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
            printf("Quantity of Burger: ");
            scanf("%d", &fd.br.quantity);
            printf("%d Burger added.\n", fd.br.quantity);
            break;

        case 2:
            printf("Quantity of PaniPuri: ");
            scanf("%d", &fd.pp.quantity);
            printf("%d Panipuri added.\n", fd.pp.quantity);
            break;

        case 3:
            printf("Quantity of Pizza: ");
            scanf("%d", &fd.pz.quantity);
            printf("%d Pizza added.\n", fd.pz.quantity);
            break;

        case 4:
            printf("Quantity of Sandwich: ");
            scanf("%d", &fd.sn.quantity);
            printf("%d Sandwich added.\n", fd.sn.quantity);
            break;

        case 5:
            printf("Quantity of Momos: ");
            scanf("%d", &fd.mo.quantity);
            printf("%d Momos added.\n", fd.mo.quantity);
            break;

        case 6:
            printf("Quantity of French Fries: ");
            scanf("%d", &fd.ff.quantity);
            printf("%d French Fries added.\n", fd.ff.quantity);
            break;

        case 7:
            printf("Quantity of Manchurian: ");
            scanf("%d", &fd.mn.quantity);
            printf("%d Munchurian added.\n", fd.mn.quantity);
            break;

        default:
            flag = 0;
            break;
        }
    }
}

//bill function
void bill()
{
    float total = 0, gst = 0;
    printf("\n\n |######################## Hotel Vinayak  #############################|\n");
    printf("\n---------------------------------------------------------------------------------");
    printf("\nName of item \t\t\t Qty \t\t\t Price total");
    printf("\n---------------------------------------------------------------------------------\n");
    //Printing the quantity and price for Burger
    if (fd.br.quantity != 0)
    {

        printf("\n%s \t\t\t\t %d \t\t\t %.2f", fd.br.name, fd.br.quantity, (fd.br.quantity * fd.br.price));
        total = total + (fd.br.quantity * fd.br.price);
    }
    //Printing the quantity and price for Pani Puri
    if (fd.pp.quantity != 0)
    {

        printf("\n%s \t\t\t %d \t\t\t %.2f", fd.pp.name, fd.pp.quantity, (fd.pp.quantity * fd.pp.price));
        total = total + (fd.pp.quantity * fd.pp.price);
    }
    //Printing the quantity and price for Pizza
    if (fd.pz.quantity != 0)
    {

        printf("\n%s \t\t\t\t %d \t\t\t %.2f", fd.pz.name, fd.pz.quantity, (fd.pz.quantity * fd.pz.price));
        total = total + (fd.pz.quantity * fd.pz.price);
    }
    //Printing the quantity and price for Sandwich
    if (fd.sn.quantity != 0)
    {

        printf("\n%s \t\t\t %d \t\t\t %.2f", fd.sn.name, fd.sn.quantity, (fd.sn.quantity * fd.sn.price));
        total = total + (fd.sn.quantity * fd.sn.price);
    }
    //Printing the quantity and price for Momos
    if (fd.mo.quantity != 0)
    {

        printf("\n%s \t\t\t\t %d \t\t\t %.2f", fd.mo.name, fd.mo.quantity, (fd.mo.quantity * fd.mo.price));
        total = total + (fd.mo.quantity * fd.mo.price);
    }
    //Printing the quantity and price for French Fries
    if (fd.ff.quantity != 0)
    {

        printf("\n%s \t\t\t %d \t\t\t %.2f", fd.ff.name, fd.ff.quantity, (fd.ff.quantity * fd.ff.price));
        total = total + (fd.ff.quantity * fd.ff.price);
    }
    //Printing the quantity and price for Manchurian
    if (fd.mn.quantity != 0)
    {

        printf("\n%s \t\t\t %d \t\t\t %.2f", fd.mn.name, fd.mn.quantity, (fd.mn.quantity * fd.mn.price));
        total = total + (fd.mn.quantity * fd.mn.price);
    }
    //Printing the total price without GST
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\nPRICE                                                    %.2f", total);
    // Calculating GST and adding it to total price
    gst = total * 0.18;
    total = total + gst;
    printf("\nGST                                                      %.2f", gst);
    printf("\n---------------------------------------------------------------------------------");
    //Printing the total price including GST
    printf("\nTOTAL PRICE                                              %.2f", total);

    printf("\n---------------------------------------------------------------------------------");
}

//main function
int main()
{
    
    login();
    passswordgenerator();
    menu();
    printf("----------------------------------------------------------------");

    bill();
    return 0;
}