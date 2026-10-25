#include<stdio.h>
#include"common.h"

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Signup");
        printf("\n2.Signin");
        printf("\n3.Exit");
        printf("\nChoice : ");
        scanf("%d",&ch);

        if(ch==1)
            signup();

        else if(ch==2)
        {
            if(signin())
            {
                char op;

                do
                {
                    printf("\n\nR-Reserve");
                    printf("\nC-Cancel");
                    printf("\nB-Booking");
                    printf("\nT-Trains");
                    printf("\nQ-Quit");

                    printf("\nOption : ");
                    scanf(" %c",&op);

                    switch(op)
                    {
                        case 'R':
                        case 'r':
                            reserveTicket();
                            break;

                        case 'C':
                        case 'c':
                            cancelTicket();
                            break;

                        case 'B':
                        case 'b':
                            bookingDetails();
                            break;

                        case 'T':
                        case 't':
                            showTrains();
                            break;
                    }

                }while(op!='Q' && op!='q');
            }
        }
        else
            break;
    }

    return 0;
}
