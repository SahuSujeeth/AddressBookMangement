#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"


int validateName(char name[])
{
    int i=0;
    int nameValidate = 1;
    int length_Name = strlen(name);
    while(name[i] != '\0')
    {
        if(length_Name >= 2 && name[i] >= '0' && name[i] <= '9' || name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' ')
        {
            nameValidate = 1;
        }
        else
        {
            nameValidate = 0;
            break;
        }
        i++;
    }
    return nameValidate;
}

int validatePhone(char phone[])
{
    int i=0;
    int phoneValidate = 1;
    int length_PhNo = strlen(phone);
    while(phone[i] != '\0')
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            phoneValidate = 0;
            break;
        }
        i++;
    }
    if(length_PhNo != 10 || phone[0] < '6' || phone[0] > '9')
    {
        phoneValidate = 0;
    }
    return phoneValidate;
}

int validateEmail(char email[])
{
    int lenght_mail = strlen(email);
    int i = 0;

    //This is for the UPPPERCASE of the mail - 1
    int mailValidate = 1;
    while(email[i] != '\0')
    {
        if(email[i] >= 'A' && email[i] <= 'Z')
        {
            mailValidate = 0;
            break;
        }
        i++;
    }
        
    //This is for the first index should not @ - 2
    if(email[0] == '@')
    {
        mailValidate = 0;
    }

    //This is for the last 4 characters should be the .com - 3
        
    char *result = strstr(email,".com");
    if(result == NULL || result != email + lenght_mail - 4)
    {
        mailValidate = 0;    
    }

    //This is for the must contain only one @. - 4
    char *firstAt = strchr(email,'@');
    char *lastAt = strrchr(email,'@');
    if(firstAt == NULL || firstAt != lastAt)
    {
        mailValidate = 0;
    }

    //This is for the atleast contain one character in between the @ and . - 5
    if(firstAt != NULL && firstAt + 1 >= email + lenght_mail - 4)
    {
        mailValidate = 0;
    }
    return mailValidate;
}

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    int criteria;
    printf("Sort based on :\n1.Name\n2.Phone\n3.email\n");
    scanf("%d",&criteria);
    /*
    if 1
       sort based on Name
    if 2
       sort based on Phone
    if 3
       sort based on email
    */
    for(int i=0;i < addressBook -> contactCount; i++)
    {
        printf("%s\t%s\t%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        
    }   
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */

    //FOR THE NAME
    while(1)
    {
       printf("Enter the Name:");
       scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
       if(validateName(addressBook->contacts[addressBook->contactCount].name))
       {
          break;
       }
       else
       {
          printf("Name is invalid, Please valid name!\n");
       }
    }

    //FOR THE PHONE NUMBER
    while(1)
    {
        printf("Enter the Phone Number:");
        scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
        if(validatePhone(addressBook->contacts[addressBook->contactCount].phone))
        {
            break;
        }
        else
        {
           printf("Phone number  is invalid, Please valid number!\n");
        }
    }

    //FOR THE MAIL NOW 
    while(1)
    {
        printf("Enter mail id:");
        scanf("%s",addressBook->contacts[addressBook->contactCount].email);

        if(addressBook->contacts[addressBook->contactCount].email)
        {
            printf("Contact Name : %s\n",addressBook->contacts[addressBook->contactCount].name);
            printf("Phone Number : %s\n",addressBook->contacts[addressBook->contactCount].phone);
            printf("Email Id : %s\n",addressBook->contacts[addressBook->contactCount].email);
            addressBook->contactCount++;
            break;
        }
        else
        {
            printf("Invalid mail!!\n");
            
        }
    }
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    printf("%d\n",addressBook->contactCount);
    
    int choice;
    printf("Search  based on :\n1.Name\n2.Phone\n3.email\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {   
            while(1)
            {
                char searchName[20];
                printf("Enter name to search:");
                scanf(" %[^\n]",searchName);
                int found = 0;
               for(int i=0; i<addressBook->contactCount ; i++)
               {
                   if(strstr(addressBook->contacts[i].name,searchName) != NULL)
                   {
                       printf("%d . %s\n",i+1,addressBook->contacts[i].name);
                       found = 1;
                   }
                }
                if(found == 0)
                {
                    printf("Name does not exist. Please search again.\n"); 
                }
                else
                {
                    break;
                }
            }
        }
        break;
    
        case 2:
        {
            
            while(1)
            {
               char searchName[20];
               printf("Enter name to search:");
               scanf("%[^\n]",searchName);
               for(int i=0; i<addressBook->contactCount ; i++)
               {
                   if(strstr(addressBook->contacts[i].name,searchName) == NULL)
                   {
                        printf("Name is not exist in the contact please search the exit name!!");
                        break;
                   }
                   else
                   {
                        printf("%d . %s\n",i+1,searchName);
                   }
                }
            }
            break;
        }
    }

    }


void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}

