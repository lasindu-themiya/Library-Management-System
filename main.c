#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
//.............................................................

void studentReg(int *studentCount)
{
    char name[30];
    char Batchnum[30];
    FILE *studentpoint = fopen("studentDetails.txt", "a");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    while (1)
    {
        printf("Enter Student Name (or 'NO' to finish): ");
        scanf(" %s", name);

        //for upper case............................
        //\0 is used for checking null characters....................

        for(int i = 0; name[i] != '\0'; i++)
        {
            name[i] = toupper(name[i]);
        }

        if (strcmp(name, "NO") == 0)
        {
            break;
        }

        printf("Enter Your Batch Number: ");
        scanf(" %s", Batchnum);

         for(int i = 0; Batchnum[i] != '\0'; i++)
        {
            Batchnum[i] = toupper(Batchnum[i]);
        }
        sleep(1);
        fprintf(studentpoint, "%s\t%s\t%d-%02d-%02d:-at:%0.2d.%0.2d.%0.2d\n\n", name, Batchnum, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
        (*studentCount)++;
        printf("Student Registered Successfully!!!!!!!!\n\n");
        sleep(1);
    }

    printf("\nNumber of Students Registered: %d\n\n", *studentCount);
    sleep(2);
    fclose(studentpoint);
}


//............................................................................

void studentdetails()
{
    char name[60];
    char Batchnum[60];
    char date[20];

    FILE *studentpoint = fopen("studentDetails.txt", "r");
    while (fscanf(studentpoint, "%s\t%s\t%s", name, Batchnum, date) == 3)
    {
        printf("\nStudent Name: %s\n", name);
        printf("Batch Number: %s\n", Batchnum);
        printf("Date and Time Registered: %s\n", date);
    }

    fclose(studentpoint);
}


//......................................................................................

void Books(int *bookCount)
{
    FILE *bookpoint = fopen("books.txt", "a");
    char name[60];
    char author[60];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    while (1)
    {
        printf("Enter Book Title (or 'NO' to finish): ");
        scanf(" %s", name);

        if (strcmp(name, "NO") == 0)
        {
            break;
        }

        printf("Enter Author Name: ");
        scanf(" %s", author);
    sleep(1);
        fprintf(bookpoint, "%s\t%s\t%d-%02d-%02d:-at:%0.2d.%0.2d.%0.2d\n\n", name, author, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
        (*bookCount)++;
        printf("Book Added Successfully!!!!!!!!\n\n");
        sleep(1);
    }
    printf("\nNumber of Books Added: %d\n", *bookCount);

    fclose(bookpoint);
}


//........................................................................

void displayBooks()
{
    char name[60];
    char author[60];
    char date[20];

    FILE *bookpoint = fopen("books.txt", "r");
    while (fscanf(bookpoint, "%s\t%s\t%s", name, author, date) == 3)
    {
        printf("\n\nBook Title: %s\n", name);
        printf("Author Name: %s\n", author);
        printf("Date and Time Added: %s\n", date);
    }

    fclose(bookpoint);
}


//.......................................................................


void bookborrow()
{
    char bBorrow[60];
    char name[60];
    char author[60];
    char date[20];
    int found = 0;

    printf("Enter the Book Title You Want to Borrow: ");
    scanf("%s", bBorrow);

    FILE *bookpoint = fopen("books.txt", "r");
    while (fscanf(bookpoint, "%s\t%s\t%s", name, author, date) == 3)
    {
        if (strcmp(name, bBorrow) == 0)
         {
            found = 1;
            break;
        }
    }
    fclose(bookpoint);

    if (found)
    {
        printf("Book '%s' by '%s' is available for borrowing.\n", name,author);
    }
    else
    {
        printf("Sorry, the book '%s' you Are searching for is not available in the library.\nTherefore You Cannot borrow it!!!!!!\n",bBorrow);
    }
}

//..................................................................

void fine()
{
    int borrowmonth;
    int borrowdate;
    int returnmonth;
    int returndate;
    int delay;
    printf("Enter Your Borrow Month:");
    scanf("%d",&borrowmonth);
    printf("Enter Borrow Date:");
    scanf("%d",&borrowdate);
    printf("Enter Return Month:");
    scanf("%d",&returnmonth);
    printf("Enter Return Date:");
    scanf("%d",&returndate);
    int month=returnmonth-borrowmonth;
    int date= returndate-borrowdate;
    int totdays;
    if (month>0)
    {
         totdays=(30*month)+date;
    }
    else
    {
        totdays=date;
    }
    float fine;
    delay=totdays-20;
    if(totdays>20)
    {
        fine=delay*10.25;
        printf("You Must Return The Book Within 20 Days from Borrowed Days!!!!!!!!!!\n");
        printf("You will be charged Rs.10.25 per Day!!!!!!!!!!!!!!!!\n\n");
        printf("Number of Days Delayed: %d\n\n",delay);
        sleep(2);
        printf("Your Fine Is %.2f/=",fine);
        sleep(3);
        result(&fine);
    }
    else
    {
        printf("You Don't Need To Pay Any Fine!!!!!!!!!!\n");
    }
}

void result(float *amount)
{
    char status[20];
    system("CLS");
    printf("\n\n\nEnter Your Payment Status('paid or not_paid'):");
    scanf("%s",&status);
    if(strcmp(status,"paid")==0)
    {
        printf("\nYou have paid %.2f as your Fine Successfully!!!!\nThank You!!!!!!!!!!!\n",*amount);
        sleep(3);
    }
    else
    {
        printf("\n\nWARNING!!!!!!!!!!!!!\n");
        printf("You Have To pay %.2f as the Fine\n",*amount);
    }
}

//..................................................................

int main()
{
    int studentCount= 0;
    int bookCount = 0;
    int choice;
    do
    {
        system("COLOR 06");
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t************\n");
        printf("\t\t\t\t\t\t\t\t\t\t WELCOME TO\n\t\t\t\t\t\t\t\t\t\tABCD LIBRARY\n");
        printf("\t\t\t\t\t\t\t\t\t\t************\n\n");
        printf("\n\t\t\t\t\t\t\t\t\t  Library Management System\n\n");
        printf("To Display Books Press 1\n");
        printf("To Add a Book Press 2\n");
        printf("To Display Registered Students Press 3\n");
        printf("For Student Registration Press 4\n");
        printf("To Borrow a Book Press 5\n");
        printf("To Calculate Your Fine Press 6\n");
        printf("To Exit Press 7\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nDisplaying Books That Are In the Library!!!!!!!!\n\n");
                sleep(1);
                displayBooks();
                sleep(3);
                break;
            case 2:
                Books(&bookCount);
                sleep(3);
                system("CLS");
                break;
            case 3:
                printf("\nDisplaying Students That Are Registered in the Library!!!!!!!!\n\n");
                sleep(1);
                studentdetails();
                sleep(3);
                break;
            case 4:
                studentReg(&studentCount);
                sleep(3);
                system("CLS");
                break;
            case 5:
                bookborrow();
                sleep(6);
                system("CLS");
                sleep(1);
                break;
            case 6:
                fine();
                sleep(3);
                system("CLS");
                break;
            case 7:
                system("CLS");
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tThank You For Using Our Library and Come Again!!!\n\n\n\n");
                sleep(3);
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                sleep(2);
                system("CLS");
        }
    }
     while (choice != 7);

    return 0;
}
