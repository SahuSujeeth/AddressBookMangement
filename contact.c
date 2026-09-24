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
    int length = strlen(addressBook->contacts->name);
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
    if(nameValidate == 1 && length >= 2)
    {
       printf("Nice name is valid");
       printf("Now u can enter the phone number now \n");
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

