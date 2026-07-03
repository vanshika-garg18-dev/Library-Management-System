#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

void addContact();
void viewContacts();
void searchContact();
void deleteContact();

int main()
{
    int choice;

    do
    {
        printf("\n==================================================\n");
        printf("          CONTACT MANAGEMENT SYSTEM\n");
        printf("==================================================\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("==================================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                viewContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                printf("\nThank you for using Contact Management System.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}

void addContact()
{
    FILE *fp;
    struct Contact c;

    fp = fopen("contacts.dat","ab");

    printf("\nEnter Name : ");
    scanf(" %[^\n]", c.name);

    printf("Enter Phone: ");
    scanf("%s", c.phone);

    printf("Enter Email: ");
    scanf("%s", c.email);

    fwrite(&c,sizeof(c),1,fp);

    fclose(fp);

    printf("\nContact Added Successfully!\n");
}

void viewContacts()
{
    FILE *fp;
    struct Contact c;
    int count = 1;

    fp = fopen("contacts.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n=============== CONTACT LIST ===============\n");

    while(fread(&c,sizeof(c),1,fp))
    {
        printf("\nContact %d\n",count++);
        printf("Name  : %s\n",c.name);
        printf("Phone : %s\n",c.phone);
        printf("Email : %s\n",c.email);
        printf("--------------------------------------------\n");
    }

    fclose(fp);
}

void searchContact()
{
    FILE *fp;
    struct Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]",name);

    while(fread(&c,sizeof(c),1,fp))
    {
        if(strcmp(c.name,name)==0)
        {
            printf("\nContact Found\n");
            printf("Name  : %s\n",c.name);
            printf("Phone : %s\n",c.phone);
            printf("Email : %s\n",c.email);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nContact Not Found!\n");

    fclose(fp);
}

void deleteContact()
{
    FILE *fp,*temp;
    struct Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.dat","rb");

    if(fp==NULL)
    {
        printf("\nNo contacts available.\n");
        return;
    }

    temp = fopen("temp.dat","wb");

    printf("\nEnter Name to Delete: ");
    scanf(" %[^\n]",name);

    while(fread(&c,sizeof(c),1,fp))
    {
        if(strcmp(c.name,name)!=0)
        {
            fwrite(&c,sizeof(c),1,temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.dat");
    rename("temp.dat","contacts.dat");

    if(found)
        printf("\nContact Deleted Successfully!\n");
    else
        printf("\nContact Not Found!\n");
}