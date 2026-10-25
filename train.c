#include<stdio.h>

void showTrains()
{
    FILE *fp;
    char ch;

    fp=fopen("trains.txt","r");

    if(fp==NULL)
    {
        printf("No Train Data");
        return;
    }

    while((ch=fgetc(fp))!=EOF)
        putchar(ch);

    fclose(fp);
}
