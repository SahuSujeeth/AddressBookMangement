#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    
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
    printf("Enter the Name:");
    scanf(" %[^\n]",addressBook->contacts->name);
    printf("The name is : %s\n",addressBook->contacts->name);
    int i=0;
    int nameValidate = 0;
    int length_Name = strlen(addressBook->contacts->name);
    //printf("The lenght of the name %d\n",length);
    
    while(addressBook->contacts->name[i] != '\0')
    {
        if(addressBook->contacts->name[i] >= '0' && addressBook->contacts->name[i] <= '9' || addressBook->contacts->name[i] >= 'a' && addressBook->contacts->name[i] <= 'z' || addressBook->contacts->name[i] >= 'A' && addressBook->contacts->name[i] <= 'Z')
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
    if(nameValidate == 1 && length_Name >= 2)
    {
       printf("Enter the Phone Number:");
       scanf("%s",addressBook->contacts->phone);
       printf("The phone number is :%s\n",addressBook->contacts->phone);
       int length_PhNo = strlen(addressBook->contacts->phone);
       printf("%d\n",length_PhNo);
       if(length_PhNo == 10 && addressBook->contacts->phone[0] >= '6' && addressBook->contacts->phone[0] <= '9')
       {
        // printf("Phone number is valid\n");
        printf("Enter mail id:");
        scanf("%s",addressBook->contacts->email);
        int lenght_mail = strlen(addressBook->contacts->email);
        int mailValidate = 1;
        int i = 0;
        int atCount = 0;
        int atPosition = -1;
        while(addressBook->contacts->email[i] != '\0')
        {
            if(addressBook->contacts->email[i] >= 'A' && addressBook->contacts->email[i] <= 'Z')
            {
                mailValidate = 0;
                break;
            }
            if(addressBook->contacts->email[i] == '@')
            {
                atCount++;
                atPosition = i;
            }
            i++;
        }
        if(atCount != 1)
        {
            mailValidate = 0;
        }
        if(addressBook->contacts->email[0] == '@')
        {
            mailValidate = 0;
        }
        if(lenght_mail < 4)
        {
            mailValidate = 0;
        }
        else
        {
            if(addressBook->contacts->email[lenght_mail - 4] != '.' || addressBook->contacts->email[lenght_mail - 3] != 'c' || addressBook->contacts->email[lenght_mail - 2] != 'o' || addressBook->contacts->email[lenght_mail - 1] != 'm')
            {
                mailValidate = 0;
            }
        }
        if(atPosition + 1 >= lenght_mail - 4)
        {
            mailValidate = 0;
        }
        if(mailValidate == 1)
        {
            printf("Mail is valid\n");
            
        }
        else
        {
            printf("Mail is not valid\n");
            
        }

       }
       else
       {
        printf("Phone number is not valid\n");
        
       }  
    }
    else
    {
        printf("Name is invalid please enter valid name!!\n");
        
    }
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}

