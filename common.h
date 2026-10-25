#ifndef COMMON_H
#define COMMON_H

struct Train
{
    int tno;
    char name[30];
    char source[20];
    char dest[20];
    int seats;
};

void signup();
int signin();

void showTrains();

void reserveTicket();
void cancelTicket();
void bookingDetails();

#endif
