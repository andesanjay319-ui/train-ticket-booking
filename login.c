#include<stdio.h>
#include<string.h>

void signup()
{
    FILE *fp;
    char user[20],pass[20];

    printf("Enter User : ");
    scanf("%s",user);

    printf("Enter Pass : ");
    scanf("%s",pass);

    fp=fopen("users.txt","a");

    fprintf(fp,"%s %s\n",user,pass);

    fclose(fp);

    printf("Account Created\n");
}

int signin()
{
    FILE *fp;
    char user[50],pass[50];
    char u[50],p[50];

    printf("User : ");
    scanf("%s",user);

    printf("Pass : ");
    scanf("%s",pass);

    fp=fopen("users.txt","r");

    while(fscanf(fp,"%s%s",u,p)!=EOF)
    {
        if(strcmp(user,u)==0 &&
           strcmp(pass,p)==0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    printf("Invalid Login\n");

    return 0;
}
