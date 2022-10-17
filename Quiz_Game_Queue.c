#include <stdio.h>

#define SIZE 5

struct queue
{
    int inp_arr[SIZE];
    int Rear;
    int Front;
};
typedef struct queue QUEUE;
QUEUE q;

int isFull()
{
    if ((q.Front == q.Rear + 1) || (q.Front == 0 && q.Rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if (q.Front == -1)
        return 1;
    return 0;
}

void enqueue(int insert_item)
{
    if (q.Rear == SIZE - 1)
        printf("Full  \n");
    else
    {
        if (q.Front == -1)
            q.Front = 0;

        q.Rear = (q.Rear + 1) % SIZE;
        q.inp_arr[q.Rear] = insert_item;
    }
}

void dequeue()
{
    if (q.Front == -1 || q.Front > q.Rear)
    {
        printf("Empty \n");
        return;
    }
    else
    {
        if (q.Front == q.Rear)
        {
            q.Front = -1;
            q.Rear = -1;
        }
        else
        {
            q.Front = (q.Front + 1) % SIZE;
        }

        printf("Element deleted from the Queue: %d \n", q.inp_arr[q.Front]);
    }
}

int traverse()
{
    int count = 0;
    if (q.Front == -1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        if (q.Front <= q.Rear)
            for (int i = q.Front; i <= q.Rear; i++)
            {
                printf("%d ", q.inp_arr[i]);
                count += 1;
            }
        printf("\n");
        printf("\ncount %d :", count);
    }
    return count;
}

void pattern(int count)
{
    if (count == 1)
    {
        printf("\n#\n");
    }
    else if (count == 2)
    {
        printf("\n # ");
        printf("\n### \n");
    }
    else if (count == 3)
    {
        printf("\n   #  ");
        printf("\n  ### ");
        printf("\n ##### \n");
    }
    else if (count == 4)
    {
        printf("\n    #  ");
        printf("\n   ### ");
        printf("\n  ##### ");
        printf("\n ######## \n");
    }
    else if (count == 5)
    {
        printf("\n    #  ");
        printf("\n   ### ");
        printf("\n  ##### ");
        printf("\n ######## ");
        printf("\n########## \n");
    }
}

void peek()
{
    printf("Front element is %d", q.inp_arr[q.Front]);
}

int *randomarray(int *arr)
{

    int randomnumber;
    srand(time(NULL));
    randomnumber = rand() % 10;
    int num, num1;
    num = num1 = randomnumber;

    for (int i = 0; i < randomnumber; i++)
    {
        arr[i] = num;
        num--;
    }
    for (int j = randomnumber + 1; j <= 10; j++)
    {
        arr[j] = num1 + 1;
        num1++;
    }
    return arr;
}

int main()
{
    q.Front = q.Rear = -1;
    int option, choice, i, num;
    int flag = 1;
    int chk = 1;

    int a[10];
    int *arr1 = randomarray(a);
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\t\t\t\tHello Gamerz");
    printf("\n\t\t\t    It is quick quiz game.");
    printf("\n\t\t    Select your interested subject and go ahead.");
    printf("\n\t\t      You require 5 points to win this game.");
    printf("\n---------------------------------------------------------------------------------");


    printf("\nGiven Options For Quiz\n");
    printf("1. GK\n");
    printf("2. Science\n");
    printf("3. Sports\n");

    while (flag)
    {
        int i, count;
        printf("\nChoose a Topic from 1.GK and 2.Science 3.Sports 0.Exit :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            /* GK */
            i = 0;
            count = 0;

            for (int i = 0; i < 10; i++)
            {
                if (arr1[i] > 10 || arr1[i] < 0)
                    arr1[i] = 10;
                // printf("%d  ", arr1[i]);
                num = arr1[i];
                if (num == 1)
                {
                    printf("Which animal is known as the Ship of the Desert?");
                    printf("\n1.Giraffe \n2.Camel \n3.Ostrich \n4.Sheep");
                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf ("\nRight Ans\n");
                        count++;
                        pattern(count);

                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\n");

                        break;
                    }
                }
                if (num == 2)
                {
                    printf("How many consonants are there in the English alphabet?");
                    printf("\n1.21 \n2.22 \n3.23 \n4.24");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}
                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 3)
                {
                    printf("Name the National fruit of India?");
                    printf("\n1.Banana \n2.Apple \n3.Mango \n4.Orange");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }

                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 4)
                {
                    printf("Name the largest planet of our Solar System?");
                    printf("\n1.Saturn \n2.Jupiter \n3.Earth \n4.Mars");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}
                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 5)
                {
                    printf("Who was the first Prime Minister of India?");
                    printf("\n1.Pandit Jawaharlal Nehru \n2.Mahatma Gandhi \n3.Sardar Vallabhbhai Patel \n4.Indira Gandhi");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}
                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 6)
                {
                    printf("What type of gas is absorbed by plants?");
                    printf("\n1.Oxygen \n2.Carbon Dioxide \n3.Sulphur Dioxide \n4.Nitrogen Dioxide");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}

                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 7)
                {
                    printf("Name the first man to walk on the Moon?");
                    printf("\n1.Kate Simons \n2.William Jones \n3.Neil Armstrong  \n4.Norton Johns");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}

                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 8)
                {
                    printf("Name the National Heritage Animal of India?");
                    printf("\n1.Camel \n2.Elephant \n3.Tiger \n4.Lion");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}

                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 9)
                {
                    printf("Name the largest 'Democracy' of the world?");
                    printf("\n1.USA \n2.Japan \n3.India \n4.Russia");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}
                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 10)
                {
                    printf("Name the hardest substance available on Earth?");
                    printf("\n1.Chromium \n2.Iron \n3.Carbon \n4.Diamond");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (count == 4)
                        {
                            i = 10;
                            break;
                        }
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        // if (count==5) {i=10; break;}

                        printf ("\nRight Ans\n");
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
            }
            // count =count-1;
            if (count <= 0)
                count = 0;
            // pattern(count);

            if (count == 0 || count == 1)
            {
                printf("Had good try");
            }
            else if (count == 2 || count == 3)
            {
                printf("\nPlay again very near to achieve the goal");
            }
            else if (count == 4)
            {
                printf("\nVery Very close to success");
            }
            else
            {
                printf("\nFound a genius in this world");
            }

            break;

        case 2:
            /* SCIENCE */
            i = 0;
            count = 0;
            for (int i = 0; i < 10; i++)
            {
                if (arr1[i] > 10 || arr1[i] < 0)
                    arr1[i] = 10;
                // printf("%d  ", arr1[i]);
                num = arr1[i];
                if (num == 1)
                {
                    printf("1.Which of the following is a non metal that remains liquid at room temperature?");
                    printf("\n1. Phosphorous \n2.Bromine \n3.Chlorine \n4.Helium");
                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf ("\nRight Ans\n");
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 2)
                {
                    printf("The hardest substance available on earth is");
                    printf("\n1.God \n2.Iron \n3.Diamond \n4.Platinum");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 3:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 3)
                {
                    printf("The inert gas which is substituted for nitrogen in the air used by deep sea divers for breathing, is ?");
                    printf("\n1.Argon \n2.Xenon \n3.Helium \n4.Krypton");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }

                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 4)
                {
                    printf("Heavy water is?");
                    printf("\n1.Deuterium oxide \n2.PH 7 \n3.Rain Water \n4.Tritium oxide");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 5)
                {
                    printf("Non stick cooking utensils are coated with");
                    printf("\n1.Teflon \n2.PVC \n3.Black Paint \n4.Polystrene");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 6)
                {
                    printf("Soda Water contains?");
                    printf("\n1.Carbonic acid \n2.Sulphuric acid \n3.Carbon Dioxide \n4.Nitrous Acid");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 7)
                {
                    printf("What is laughing gas?");
                    printf("\n1.Nitrous Oxide \n2.Carbon monoxide \n3.Sulphur Dioxide  \n4. Hydrogen peroxide");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 8)
                {
                    printf("Balloons are filled with");
                    printf("\n1.Nitrogen \n2.helium \n3.Oxygen \n4.Argon");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 9)
                {
                    printf("Which of the following is the lightest metal?");
                    printf("\n1.Mercury \n2.Lithium \n3.Lead \n4.Silver");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 10)
                {
                    printf("From which mineral is radium obtained?");
                    printf("\n1.Rutile \n2.Haematite \n3.Limestone \n4.Pitchblende");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
            }

            if (count <= 0)
                count = 0;
            // pattern(count);

            if (count == 0 || count == 1)
            {
                printf("\nHad good try");
            }
            else if (count == 2 || count == 3)
            {
                printf("\nPlay again very near to achieve the goal");
            }
            else if (count == 4)
            {
                printf("\nVery Very close to success");
            }
            else
            {
                printf("\nFound a genius in this world");
            }
            break;

        case 3:
            /* SCIENCE */
            i = 0;
            count = 0;
            for (int i = 0; i < 10; i++)
            {
                if (arr1[i] > 10 || arr1[i] < 0)
                    arr1[i] = 10;
                // printf("%d  ", arr1[i]);
                num = arr1[i];
                if (num == 1)
                {
                    printf("1.Which of the following terms are used to describe parts of a cricket bat?");
                    printf("\n1. Eye and Toe \n2.Leg and Hand \n3.Shoulders and Toe \n4.Neck and Shoulders");
                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf ("\nRight Ans\n");
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 2)
                {
                    printf("Who is the Head Coach of Indian National Football team?");
                    printf("\n1.Sunil Chettri \n2.Manvir Singh \n3.Stephen Constantine \n4.Bob Houghton");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 3:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 3)
                {
                    printf("Which cricket ground is known as the “Home of Cricket”?");
                    printf("\n1.Melbourne Cricket Ground \n2.Eden Park Cricket Ground \n3.Adelaide Oval Cricket Ground \n4.Lord’s Cricket Ground");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }

                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 4)
                {
                    printf("Which is the most successful team winning the most number of  Kabaddi World Cups?");
                    printf("\n1.Bangladesh \n2.Iran \n3.South Korea \n4.India");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 5)
                {
                    printf("Who is the first Indian female boxer to win a gold medal in the Asian Games?");
                    printf("\n1. Pinki Jangra \n2. Mary Kom \n3.Manisha Moun \n4.Simranjit Kaur");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 2:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 6)
                {
                    printf("The Volleyball sport has been first played in which country?");
                    printf("\n1.Canada\n2.Belgium \n3.Germany\n4.United States of America");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 7)
                {
                    printf("Who was the 1st ODI captain for India?");
                    printf("\n1.Ajit Wadekar\n2.Bishen Singh Bedi\n3.Nawab Pataudi\n4.Vinoo Mankad");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 8)
                {
                    printf("The 'Dronacharya Award' is given to...?");
                    printf("\n1.Sportsmen \n2.Coaches \n3.Umpires \n4.Sports Editors");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 9)
                {
                    printf("Who was the 1st president of BCCI ( Board of Control for Cricket in India )?");
                    printf("\n1.R.E. Grant Govan \n2.Dr. Maharajkumar Sir Vijaya Ananda \n3.Sikandar Hyat Khan \n4.Anthony S. D'Mello");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);

                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }
                        printf ("\nRight Ans\n");
                        break;
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
                if (num == 10)
                {
                    printf("The Asian Games were held in Delhi for the first time in...?");
                    printf("\n1.1951 \n2.1963 \n3.1971 \n4.1982");

                    printf("\nPlease Choose an Option : ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 4:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 2:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 3:
                        if (!isEmpty)
                        {
                            dequeue();
                        }
                        else
                        {
                            chk = 0;
                        }
                        printf("Wrong Ans\n");
                        pattern(count);
                        break;
                    case 1:
                        if (!isFull)
                        {
                            enqueue(1);
                        }
                        else
                        {
                            chk = 0;
                        }
                        count++;
                        pattern(count);
                        if (count == 5)
                        {
                            i = 10;
                            break;
                        }

                        printf ("\nRight Ans\n");
                        break;
                    default:
                        printf("Invalid Option Selected\nSkipping to Next Question\n\n");

                        break;
                    }
                }
            }

            if (count <= 0)
                count = 0;
            // pattern(count);

            if (count == 0 || count == 1)
            {
                printf("\nHad good try");
            }
            else if (count == 2 || count == 3)
            {
                printf("\nPlay again very near to achieve the goal");
            }
            else if (count == 4)
            {
                printf("\nVery Very close to success");
            }
            else
            {
                printf("\nFound a genius in this world");
            }
            break;

        default:
            flag = 0;
            break;
        }
    }
}