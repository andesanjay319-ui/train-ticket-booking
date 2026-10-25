#include<stdio.h>

void reserveTicket()
{
    FILE *fp;

    int tno;
    char name[50];

    printf("Train No : ");
    scanf("%d",&tno);

    printf("Passenger : ");
    scanf("%s",name);

    fp=fopen("booking.txt","a");

    fprintf(fp,"%d %s\n",tno,name);

    fclose(fp);

    printf("Booked Successfully\n");
}

void cancelTicket()
{
    FILE *fp, *temp;
    int trainNo, tno;
    char pname[30], name[30];
    int found = 0;

    printf("\nEnter Train Number : ");
    scanf("%d", &trainNo);

    printf("Enter Passenger Name : ");
    scanf("%s", pname);

    fp = fopen("booking.txt", "r");

    if(fp == NULL)
    {
        printf("No Booking Records Found\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    while(fscanf(fp, "%d %s", &tno, name) != EOF)
    {
        if(tno == trainNo && strcmp(name, pname) == 0)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s\n", tno, name);
    }

    fclose(fp);
    fclose(temp);

    remove("booking.txt");
    rename("temp.txt", "booking.txt");

    if(found)
        printf("Ticket Cancelled Successfully\n");
    else
        printf("Booking Not Found\n");
}

void bookingDetails()
{
    FILE *fp;
    char ch;

    fp=fopen("booking.txt","r");

    if(fp==NULL)
    {
        printf("No Booking");
        return;
    }

    while((ch=fgetc(fp))!=EOF)
        putchar(ch);

    fclose(fp);
}
