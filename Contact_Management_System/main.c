/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ishan Kansara 
 *
 * Created on July 18, 2020, 6:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creating structure as linked list
struct Node{
    char custName[50];
    char phoneNum[20];
    char custAddress[100];
    char custEmail[50];
    struct Node *nxt;
    struct Node *back;
}*root = NULL;

//Creatig new nodes and initializing
struct Node *addTemp = NULL;
struct Node *addNewNode = NULL;

/**
 * @description This function is used to add new contacts in linked list
 * @param na
 * @return void
 */
void addContact()
{
    //declaring and initializing variables
    char cName[50];
    char cAddress[100];
    char cEmail[50];
    char cPhone[20];
    printf("Enter contact name: \n");
    scanf(" %[^\t\n]s",cName);
    printf("Enter contact phone number: \n");
    scanf(" %[^\t\n]s",cPhone);
    printf("Enter address: \n");
    scanf(" %[^\t\n]s",cAddress);
    printf("Enter email address: \n");
    scanf(" %[^\t\n]s",cEmail);

    //Condition to check if root is null, if yes, allocate space and create root node
    if(root == NULL)
    {
        root = (struct Node*)malloc(sizeof(struct Node));
        strcpy(root->custName,cName);
        strcpy(root->custAddress,cAddress);
        strcpy(root->custEmail,cEmail);
        strcpy(root->phoneNum,cPhone);
        root->nxt = NULL;
        root->back = NULL;
    }
    else
    {
        addTemp = root;
        while(addTemp->nxt != NULL)
        {
            addTemp = addTemp->nxt;
        }
        addNewNode = (struct Node*)malloc(sizeof(struct Node));
        strcpy(addNewNode->custName,cName);
        strcpy(addNewNode->custAddress,cAddress);
        strcpy(addNewNode->custEmail,cEmail);
        strcpy(addNewNode->phoneNum,cPhone);
        addNewNode->nxt = NULL;
        addTemp->nxt = addNewNode;
        addNewNode->back = addTemp;
    }
    printf("*******Contact Added!!*******\n");
}

/**
 * @description This function is used to list all the contacts using linked list.
 * @param struct
 * @return void
 */
void listContacts(struct Node *listNode)
{
    printf("*******************************\n");
    printf("\tList of contacts\t\n");
    printf("*******************************\n\n");
    //Declaring and initializing variables
    struct Node *listTempNode = NULL;
    listTempNode = listNode;
    int serialNo = 1;
    //Logic to iterate through linked list
    while(listNode != NULL)
    {
        printf("[%d]\n"
                "Name: %s \n"
                "Phone: %s \n"
                "Address: %s \n"
                "Email: %s \n",serialNo,listNode->custName,listNode->phoneNum,
                listNode->custAddress,listNode->custEmail);
        serialNo++;
        listNode = listNode->nxt;
    }
}

/**
 * @description This function will help in searching a particular contact and display all the details
 * of that particular contact
 * @param searchNode
 * @return void
 */
void searchContacts(struct Node *searchNode)
{
    //Declaring and initializing variables
    struct Node *tempSearchNode = NULL;
    tempSearchNode = searchNode;
    char searchName[50];
    printf("Enter name to search contact: \n");
    scanf(" %[^\t\n]s",searchName);
    printf("*******Customer Details*******\n");
    //Logic to iterate through all the contacts and display details when particular contact is found
    while(tempSearchNode != NULL)
    {
        if(strcmp(tempSearchNode->custName,searchName) == 0)
        {
            printf(
                "Name: %s \n"
                "Phone: %s \n"
                "Address: %s \n"
                "Email: %s \n",tempSearchNode->custName,tempSearchNode->phoneNum,
                tempSearchNode->custAddress,tempSearchNode->custEmail);
        }
        tempSearchNode = tempSearchNode->nxt;
    }
}

/**
 * @description This function edits details of a particular contact.
 * @param editNode
 * @return void
 */
void editContacts(struct Node *editNode)
{
    //Declaring and initializing variables
    struct Node *tempEditNode = NULL;
    tempEditNode = editNode;
    int editOptions = 0;
    char editName[50];
    printf("Enter name to edit contact: \n");
    scanf(" %[^\t\n]s",editName);
    //Logic to find a particular contact and once found, edit all the details
    while(tempEditNode != NULL)
    {
        if(strcmp(tempEditNode->custName,editName) == 0)
        {
            break;
        }   
        tempEditNode = tempEditNode->nxt;
    }
    
    printf("Enter 1 to edit contact name\n"
           "Enter 2 to edit contact address\n"
           "Enter 3 to edit contact email\n"
           "Enter 4 to edit contact phone\n");
    printf("Enter option: ");
    scanf("%d",&editOptions);
    if(editOptions == 1)
    {
        char newName[50];
        printf("Enter new name: \n");
        scanf(" %[^\t\n]s",newName);
        strcpy(tempEditNode->custName,newName);
    }
    else if(editOptions == 2)
    {
        char newAddress[100];
        printf("Enter new address: \n");
        scanf(" %[^\t\n]s",newAddress);
        strcpy(tempEditNode->custAddress,newAddress);
    }
    else if(editOptions == 3)
    {
        char newEmail[50];
        printf("Enter new email: \n");
        scanf(" %[^\t\n]s",newEmail);
        strcpy(tempEditNode->custEmail,newEmail);
    }
    else if(editOptions == 4)
    {
        char newPhone[50];
        printf("Enter new phone: \n");
        scanf(" %[^\t\n]s",newPhone);
        strcpy(tempEditNode->phoneNum,newPhone);
    }
    else
    {
        return;
    }
    printf("*********Customer Edited!!*********\n");
}

/**
 * @desccription This function will delete a particular contact from the list
 * @param deleteCust
 * @return void
 */
void deleteContact(struct Node *deleteCust)
{
    //Condition in case where there are no customers in the list i.e all customer records are deleted 
    if(deleteCust == NULL)
    {
        printf("********No customers to be found!!******** \n");
        return;
    }
    //Declaring and initialization
    struct Node *tempDeleteNode = NULL;
    //Storing root node in temporary node to be used indirectly
    tempDeleteNode = deleteCust;
    char deleteContact[50];
    printf("Enter contact name to be deleted: \n");
    scanf(" %[^\t\n]s",&deleteContact);
    //Iterate through whole linked list, if customer key found to be deleted, remove it from the list
    while(tempDeleteNode != NULL)
    {
        //Condition if customer key matches
        if(strcmp(tempDeleteNode->custName,deleteContact) == 0)
        {
            //Condition if there is only one node in the list 
            if(tempDeleteNode->back == NULL && tempDeleteNode->nxt == NULL)
            {
                root = NULL;
                free(tempDeleteNode);
                break;
            }
            //Condition if node to be deleted is 1st node and is linked to other nodes
            else if(tempDeleteNode->back == NULL && tempDeleteNode->nxt != NULL)
            {
                tempDeleteNode->nxt->back = NULL;
                root = tempDeleteNode->nxt;
                tempDeleteNode->nxt = NULL;
                free(tempDeleteNode);
                break;
            }
            //Condition to remove node which is linked to both front and back nodes
            else if(tempDeleteNode->back != NULL && tempDeleteNode->nxt != NULL)
            {
                tempDeleteNode->back->nxt = tempDeleteNode->nxt;
                tempDeleteNode->back = NULL;
                tempDeleteNode->nxt = NULL;
                free(tempDeleteNode);
                break;
            }
            //Condition to remove last node from the list
            else if(tempDeleteNode->nxt == NULL && tempDeleteNode->back != NULL)
            {
                tempDeleteNode->back->nxt = NULL;
                tempDeleteNode->back = NULL;
                free(tempDeleteNode);
                break;
            }
        }
        tempDeleteNode = tempDeleteNode->nxt;
    }
}

/**
 * @description This function will write contact details in particular file
 * @param writeCust
 * @return void
 */
void writeFile(struct Node *writeCust)
{
    //Declaration and initialization
    struct Node *tempWriteNode = NULL;
    tempWriteNode = writeCust;
    FILE *fptr;
    //Creating file pointer, 'r+' mode is to avoid overwriting the file
    fptr = fopen("C:/Users/ishan/NetBeansProjects/Contact_System/Contact_Details.txt","r+");
    //Condition if file do not open
    if(fptr == NULL)
    {
        printf("File opening error!!");
        exit(1);
    }
    int c = getc(fptr);
    //Logic to reach end of file to insert new records after existing ones
    while(c != EOF)
    {
        c = getc(fptr);
    }
    //Iterate through updated linked list and write file
    while(tempWriteNode != NULL)
    {
        fprintf(fptr,"%s %s\n","Customer Name: ", tempWriteNode->custName);
        fprintf(fptr,"%s %s\n","Customer Address: ", tempWriteNode->custAddress);
        fprintf(fptr,"%s %s\n","Customer Email: ", tempWriteNode->custEmail);  
        fprintf(fptr,"%s %s\n","Customer Phone: ", tempWriteNode->phoneNum);
        tempWriteNode = tempWriteNode->nxt;
    }
    fclose(fptr);
}

/*
 * 
 */
int main(int argc, char** argv) {

    printf("\n*******Welcome to Contact Management System*******\n\n");
    while(1)
    {
        
        printf("\tMAIN MENU\t\n");
        printf("=====================\n");
        printf("[1] Add a new contact\n"
               "[2] List all contacts\n"
               "[3] Search for contacts\n"
               "[4] Edit a contact\n"
               "[5] Delete a contact\n"
               "[6] Exit\n"
               "======================\n");
    
        int enterChoice = 0;
        printf("Enter choice: ");
        scanf("%d",&enterChoice);
        
        if(enterChoice == 6)
        {
            printf("Exiting........ \n");
            break;
        }
        switch(enterChoice)
        {
            case 1:
               addContact();
               break;
            case 2:
                listContacts(root);
                break;
            case 3:
                searchContacts(root);
                break;
            case 4:
                editContacts(root);
                break;
            case 5:
                deleteContact(root);
                break;
        }
    }
    return 0;
}

