#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

//creating a struct for singer details
struct node
{
    int data;
    int vote;
    char DOB[15];
    char name[20];
    long long int Ph_no;
    long long int Aadhar_no;
    struct node *next;
};

struct node *head;

//creating a struct for audiance details
struct node1
{
    int data;
    int vote;
    char name[20];
    struct node1 *next;
};

struct node1 *head1;

//creating a function for entering singer details
void lastinsertsinger()
{
    struct node *ptr, *temp;
    char item[15];
    char name1[20];
    long long int Ph_no1;
    long long int Aadhar_no1;
    int data1;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        int count1 = 0;
        int count = 0;
        printf("Enter serial number of singer :");
        scanf("%d", &data1);
        printf("\nEnter the name of Signer :\n");
        scanf("%s", &name1);

        printf("\nEnter DOB for given singer :\n");
        scanf("%s", &item);

        printf("\nEnter Phone number :\n");  // phone number should be of 10 digit
        scanf("%lld", &Ph_no1);
        // printf("%lld",Ph_no1);

        printf("\nEnter Aadhar number :\n");  // aadhar  number should be of 12 digit
        scanf("%lld", &Aadhar_no1);

        count1 = (log10(Ph_no1) + 1);  
        // printf("%d", count1);
        count = (log10(Aadhar_no1) + 1);
        // printf("%d", count);

        if (count1 != 10 && count != 12)
        {
            printf("Invalid input");
        }
        else
        {
            ptr->data = data1;
            ptr->Ph_no = Ph_no1;
            ptr->Aadhar_no = Aadhar_no1;
            strcpy(ptr->DOB, item);
            strcpy(ptr->name, name1);

            // printf("%lld",Ph_no1);

            if (head == NULL)
            {
                ptr->next = NULL;
                head = ptr;
                printf("\nNode inserted");
            }

            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
                ptr->next = NULL;
                printf("\nNode inserted");
            }
        }
    }
}

//function to display the singer details that are inserted in node
void displayfullsinger()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\nSerial Number : %d", ptr->data);
            printf("\nName : %s", ptr->name);
            printf("\nDate Of Birth : %s", ptr->DOB);
            printf("\nPhone Number : %lld", ptr->Ph_no);
            printf("\nAadhar Number : %lld", ptr->Aadhar_no);
            // free(ptr);
            printf("\n");
            ptr = ptr->next;
        }
    }
}

//function to display the singer details so the audience can choose from the options available
void displayofsingerforaudience()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\nSerial Number : %d", ptr->data);
            printf("\nName : %s", ptr->name);
            // free(ptr);
            printf("\n");
            ptr = ptr->next;
        }
    }
}

// void sortList()
// {
//     // Node current will point to head
//     struct node *current = head, *index = NULL;
//     int temp;
//     long long int i;
//     char t[20];

//     if (head == NULL)
//     {
//         return;
//     }
//     else
//     {
//         while (current != NULL)
//         {
//             // Node index will point to node next to current
//             index = current->next;

//             while (index != NULL)
//             {
//                 // If current node's data is greater than index's node data, swap the data between them
//                 if (current->data > index->data)
//                 {
//                     temp = current->data;
//                     current->data = index->data;
//                     index->data = temp;

//                     temp1 = current->vote;
//                     current->vote = index->vote;
//                     index->vote = temp1;

//                     i = current->Ph_no;
//                     current->Ph_no = index->Ph_no;
//                     index->Ph_no = i;

//                     i = current->Aadhar_no;
//                     current->Aadhar_no = index->Aadhar_no;
//                     index->Aadhar_no = i;

//                     strcpy(t, current->name);
//                     strcpy(current->name, index->name);
//                     strcpy(index->name, t);

//                     strcpy(t, current->DOB);
//                     strcpy(current->DOB, index->DOB);
//                     strcpy(index->DOB, t);
//                 }
//                 index = index->next;
//             }
//             current = current->next;
//         }
//     }
// }

void sortList()
{
    // Node current will point to head
    struct node *current = head, *index = NULL;
    int temp, temp1;
    long long int i;
    char t[20];

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            // Node index will point to node next to current
            index = current->next;

            while (index != NULL)
            {
                // If current node's data is greater than index's node data, swap the data between them
                if (current->vote > index->vote)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;

                    temp1 = current->vote;
                    current->vote = index->vote;
                    index->vote = temp1;

                    i = current->Ph_no;
                    current->Ph_no = index->Ph_no;
                    index->Ph_no = i;

                    i = current->Aadhar_no;
                    current->Aadhar_no = index->Aadhar_no;
                    index->Aadhar_no = i;

                    strcpy(t, current->name);
                    strcpy(current->name, index->name);
                    strcpy(index->name, t);

                    strcpy(t, current->DOB);
                    strcpy(current->DOB, index->DOB);
                    strcpy(index->DOB, t);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void sort(struct node **h)
{
    int a, b, c;
    long long int i;
    char t[20];

    struct node *temp1;
    struct node *temp2;

    for (temp1 = *h; temp1 != NULL; temp1 = temp1->next)
    {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            a = temp1->data;
            temp1->data = temp2->data;
            temp2->data = a;

            c = temp1->vote;
            temp1->vote = temp2->vote;
            temp2->vote = c;

            i = temp1->Ph_no;
            temp1->Ph_no = temp2->Ph_no;
            temp2->Ph_no = i;

            i = temp1->Aadhar_no;
            temp1->Aadhar_no = temp2->Aadhar_no;
            temp2->Aadhar_no = i;

            strcpy(t, temp1->name);
            strcpy(temp1->name, temp2->name);
            strcpy(temp2->name, t);

            strcpy(t, temp1->DOB);
            strcpy(temp1->DOB, temp2->DOB);
            strcpy(temp2->DOB, t);
        }
    }
}

struct node *copyList(struct node *head) // to take top 3 singer acc to data
{
    int count = 0;
    struct node *current = head; // used to iterate over the original list
    struct node *newList = NULL; // head of the new list
    struct node *tail = NULL;    // point to the last node in a new list

    while (current != NULL && count != 3)
    {
        // special case for the first new node
        if (newList == NULL)
        {
            newList = (struct node *)malloc(sizeof(struct node));
            strcpy(newList->name, current->name);
            strcpy(newList->DOB, current->DOB);
            newList->Ph_no = current->Ph_no;
            newList->Aadhar_no = current->Aadhar_no;
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else
        {
            tail->next = (struct node *)malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->Aadhar_no = current->Aadhar_no;
            strcpy(tail->name, current->name);
            strcpy(tail->DOB, current->DOB);
            tail->Ph_no = tail->Ph_no;
            tail->next = NULL;
        }

        current = current->next;
        count++;
    }

    return newList;
}

//funtion to print the details of the top 3 singers
void printList(struct node *head)
{
    struct node *ptr = head;
    printf("Details of singer top 3");
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        printf("\n%s", ptr->name);
        printf("\n%s", ptr->DOB);
        printf("\n%d", ptr->Ph_no);
        printf("\n%llu", ptr->Aadhar_no);
        ptr = ptr->next;
    }

    printf("NULL");
}

//function to insert the audience data in node
void lastinsertaudience()
{
    struct node1 *ptr, *temp;
    int item;
    char name[20];
    ptr = (struct node1 *)malloc(sizeof(struct node1));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the name of audience:\n");
        scanf("%s", name);

        printf("\nEnter vote for given singer ?\n");
        scanf("%d", &item);

        ptr->vote = item;
        strcpy(ptr->name, name);
        if (head1 == NULL)
        {
            ptr->next = NULL;
            head1 = ptr;
            printf("\nnode1 inserted");
        }
        else
        {
            temp = head1;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nnode1 inserted");
        }
    }
}

//function to display the audience details that were entered in node
void displayaudience()
{
    struct node1 *ptr;
    ptr = head1;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\n%s", ptr->name);
            printf("\n%d", ptr->vote);
            ptr = ptr->next;
        }
    }
}


//function to take the choices of the favourite singer of the audience for voting
void insertaudience()
{
    int choice, flag = 1;
    while (flag)
    {
        printf("\nEnter your choice?\n");
        printf("\n1.Insert the data of auidence\n2.To see list of audience\n3.Exit\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            displayofsingerforaudience();
            lastinsertaudience();
            break;

        case 2:
            displayaudience();
            break;

        case 3:
            flag = 0;
            break;

        default:
            printf("Invalid choice");
        }
    }
}

//function for the singer choices
void functionforsinger()
{
    int choice, flag = 1;
    while (flag)
    {
        printf("\nEnter your choice?\n");
        printf("\n1.Insert the data of Singer\n2.To see list of Singer\n3.Exit\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            lastinsertsinger();
            break;

        case 2:
            displayfullsinger();
            break;

        case 3:
            flag = 0;
            break;

        default:
            printf("Invalid choice");
        }
    }
}

//displaying the data of votes
void function(struct node *head, struct node1 *head1)
{

    struct node *current = head;
    struct node1 *current1 = head1;

    while (current != NULL)
    {
        current->vote = 0;
        while (current1 != NULL)
        {

            if (current1->vote == current->data)
            {
                current->vote++;
            }
            current1 = current1->next;
        }
        current = current->next;
    }
}

int main()
{

    printf("\n\t\t################### Welcome Applicants to the Competition ######################");

    printf("\n");
    
    functionforsinger();

    sortList();

    printf("\n\t\t################### Welcome to the Audience Applicants ######################");

    insertaudience();

    function(head, head1);

    sortList();

    struct node *dup = copyList(head);
    printList(dup);

    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\t\t ****** Winner of the day goes to ******");
    printf("\n\t\t%d", dup->data);
    printf("\n\t\t%s", dup->name);
    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");


    printf("\n !!!!!!! thank you for coming and participating in our concert !!!!!!!");

    return 0;
}