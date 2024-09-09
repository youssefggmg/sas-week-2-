#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX_BOOKS 1000

typedef struct b
{
    char title[200];
    char author[200];
    int price;
    int stoke;
} bookes;

// add a book

void toLowerCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// Function to add a book
void addBook(bookes arr[], int num)
{
    int choice, n;
    printf("Do you want to add one book or many books?\n");
    printf("1 - One book\n");
    printf("2 - Many books\n");
    scanf("%d", &choice);

    switch (choice)
    {
    // Add one book
    case 1:
        for (int i = 0; i < num; i++)
        {
            if (strcmp(arr[i].title, "empty") == 0)
            {
                // Add in the empty spaces
                printf("Enter the title of the book: ");
                scanf(" %[^\n]s", arr[i].title);
                getchar();

                toLowerCase(arr[i].title);

                printf("Enter the name of the author: ");
                scanf(" %[^\n]s", arr[i].author);
                getchar();

                toLowerCase(arr[i].author);

                printf("Enter the price of the book: ");
                scanf("%d", &arr[i].price);
                printf("Enter the stock of the book: ");
                scanf("%d", &arr[i].stoke);

                printf("Your book is added successfully\n");
                scanf("%d", &choice);
                if (choice != 1)
                {
                    exit(0);
                }
            }
            else
            {
                // Add in the last space
                printf("Enter the title of the book: ");
                scanf(" %[^\n]s", arr[num].title);
                getchar();

                toLowerCase(arr[num].title);

                printf("Enter the name of the author: ");
                scanf(" %[^\n]s", arr[num].author);
                getchar();

                toLowerCase(arr[num].author);

                printf("Enter the price of the book: ");
                scanf("%d", &arr[num].price);
                printf("Enter the stock of the book: ");
                scanf("%d", &arr[num].stoke);
                num++;

                printf("Your book is added successfully\n");
                scanf("%d", &choice);
                if (choice != 1)
                {
                    exit(0);
                }
            }
        }
        break;

    // Add more than one book
    case 2:
        printf("How many books do you want to add? ");
        scanf("%d", &n);

        for (int i = num; i < num + n; i++)
        {
            if (strcmp(arr[i].title, "empty") == 0)
            {
                // Add in the empty spaces
                printf("Enter the title of the book: ");
                scanf(" %[^\n]s", arr[i].title);
                getchar();

                toLowerCase(arr[i].title);

                printf("Enter the name of the author: ");
                scanf(" %[^\n]s", arr[i].author);
                getchar();

                toLowerCase(arr[i].author);

                printf("Enter the price of the book: ");
                scanf("%d", &arr[i].price);
                printf("Enter the stock of the book: ");
                scanf("%d", &arr[i].stoke);

                printf("Your book is added successfully\n");
                scanf("%d", &choice);
                if (choice != 1)
                {
                    exit(0);
                }
            }
            else
            {
                printf("Enter the title of the book: ");
                scanf(" %[^\n]s", arr[num].title);
                getchar();

                // Convert title to lowercase
                toLowerCase(arr[num].title);

                printf("Enter the name of the author: ");
                scanf(" %[^\n]s", arr[num].author);
                getchar();

                toLowerCase(arr[num].author);

                printf("Enter the price of the book: ");
                scanf("%d", &arr[num].price);
                printf("Enter the stock of the book: ");
                scanf("%d", &arr[num].stoke);
                num++;

                printf("Your book is added successfully\n");
                scanf("%d", &choice);
                if (choice != 1)
                {
                    exit(0);
                }
            }
        }
        num += n;
        break;
    }
}
// delete abook
void deletebook(bookes arr[], char name[], int num)
{
    int choice;
    for (int i = 0; i < num; i++)
    {
        if (strcmp(arr[i].title, name) == 0)
        {
            printf("are you sure you want to delete this book?\n 1.yes\n 2.no\n");

            switch (choice)
            {
            case 1:
                strcpy(arr[i].title, "empty");
                strcpy(arr[i].author, "empty");
                arr[i].price = 0;
                arr[i].stoke = 0;
                printf("booke was deleted succefully\n");
                printf("do you want to continu\n");
                scanf("%d", &choice);
                if (choice != 1)
                {
                    exit(0);
                }
                break;
            default:
                break;
            }
        }
        else
        {
            printf("we did not find this book\n");
            printf("do you want to continu\n");
            scanf("%d", &choice);
            if (choice != 1)
            {
                exit(0);
            }
        }
    }
}
// modefi a book
void modefi(bookes arr[], char name[], int num)
{
    int i, choice;
    char newname[50], newauthor[50];
    int newprice, newstoke;

    // Convert input name to lowercase to ensure case-insensitive matching
    toLowerCase(name);

    for (i = 0; i < num; i++)
    {
        // Convert existing title to lowercase for comparison
        char lowerTitle[200];
        strcpy(lowerTitle, arr[i].title);
        toLowerCase(lowerTitle);

        if (strcmp(lowerTitle, name) == 0)
        {
            printf("What do you want to modify:\n1. Title\n2. Author\n3. Price\n4. Stock\n5. All of them\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("What is the new title: ");
                scanf(" %[^\n]s", newname);
                getchar();

                // Convert new title to lowercase
                toLowerCase(newname);

                // Update the book title
                strcpy(arr[i].title, newname);
                break;

            case 2:
                printf("Who is the new author: ");
                scanf(" %[^\n]s", newauthor);
                getchar();

                // Convert new author name to lowercase
                toLowerCase(newauthor);

                // Update the author name
                strcpy(arr[i].author, newauthor);
                break;

            case 3:
                printf("What is the new price: ");
                scanf("%d", &newprice);
                arr[i].price = newprice;
                break;

            case 4:
                printf("What is the new stock: ");
                scanf("%d", &newstoke);
                arr[i].stoke = newstoke;
                break;

            case 5:
                printf("What is the new title: ");
                scanf(" %[^\n]s", newname);
                getchar();

                // Convert new title to lowercase
                toLowerCase(newname);

                // Update the book title
                strcpy(arr[i].title, newname);

                printf("Who is the new author: ");
                scanf(" %[^\n]s", newauthor);
                getchar();

                // Convert new author name to lowercase
                toLowerCase(newauthor);

                // Update the author name
                strcpy(arr[i].author, newauthor);

                printf("What is the new price: ");
                scanf("%d", &newprice);
                arr[i].price = newprice;

                printf("What is the new stock: ");
                scanf("%d", &newstoke);
                arr[i].stoke = newstoke;

                break;
            }

            printf("Book was modified successfully.\n");
            printf("Do you want to continue? (1 for Yes, other for No): ");
            scanf("%d", &choice);

            if (choice != 1)
            {
                exit(0);
            }
        }
        else if (strcmp(name, "empty") == 0)
        {
            printf("We did not find this book.\n");
            printf("Do you want to continue? (1 for Yes, other for No): ");
            scanf("%d", &choice);

            if (choice != 1)
            {
                exit(0);
            }
        }
        else
        {
            printf("We did not find this book.\n");
            printf("Do you want to continue? (1 for Yes, other for No): ");
            scanf("%d", &choice);

            if (choice != 1)
            {
                exit(0);
            }
        }
    }
}
// search for abook
void search(bookes arr[], char name[], int num)
{
    int i, choice;
    for (size_t i = 0; i < num; i++)
    {
        if (strcmp(arr[i].title, num) == 0)
        {
            printf("the booke name is %s", arr[i].title);
            printf("the booke author is %s", arr[i].author);
            printf("the booke price is %s", arr[i].price);
            printf("the booke stock is %s", arr[i].stoke);
        }
        else if (strcmp(name, "empty") == 0)
        {
            printf("we did not find this book\n");
            printf("do you want to continu\n");
            scanf("%d", &choice);
            if (choice != 1)
            {
                exit(0);
            }
        }

        else
        {
            printf("we did not find this book\n");
            printf("do you want to continu\n");
            scanf("%d", &choice);
            if (choice != 1)
            {
                exit(0);
            }
        }
    }
}
void allbookes(bookes arr[], int num)
{
    int i, choice;
    for (i = 0; i < num; i++)
    {
        if (strcmp(arr[i].title, "empty") == 0)
        {
            printf("we did not find this book\n");
            printf("do you want to continu\n");
            scanf("%d", &choice);
            if (choice != 1)
            {
                exit(0);
            }
        }
        else
        {
            printf("the booke name is %s", arr[i].title);
            printf("the booke author is %s", arr[i].author);
            printf("the booke price is %s", arr[i].price);
            printf("the booke stock is %s", arr[i].stoke);
        }
        printf("thes are all the bookes form our booke store \n");
        printf("do you want to continu\n");
        scanf("%d", choice);
        if (choice != 1)
        {
            exit(0);
        }
    }
}

int main()
{
    int choice;
    bookes bookeList[MAX_BOOKS];
    char name[50];
    int index = 0;

    printf("Welcome to Library Management System\n");
    while (1)
    {
        system("clear");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. modefi\n");
        printf("4. Search Book\n");
        printf("5. View All Books\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBook(bookeList, index);

            break;
        case 2:
            printf("what is the name of the book that you want to delete?\n");
            scanf(" %[^\n]s", &name);
            getchar();
            deletebook(bookeList, name, index);

            break;
        case 3:
            printf("what is the name of the book that you want to delete?\n");
            scanf(" %[^\n]s", &name);
            getchar();
            modefi(bookeList, name, index);
            break;
        case 4:
            printf("what is the name of the book that you'r looking for?\n");
            scanf(" %[^\n]s", &name);
            getchar();
            search(bookeList, name, index);
            break;
        case 5:
            allbookes(bookeList, index);
            break;
        case 6:
            exit(0);
            break;
        }
    }
    return 0;
}
