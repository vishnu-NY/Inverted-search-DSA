#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

status add_to_last_ip_files(char* filename,struct ip_file** head )
{
    struct ip_file* newfile = malloc(sizeof(struct ip_file));
    if(newfile == NULL)
    {
        return FAILURE;
    }
    newfile->link = NULL;
    strcpy(newfile->filename,filename); 
    if(*head == NULL)
    {
        *head = newfile;
        return SUCCESS;
    }
    struct ip_file* temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newfile;
    return SUCCESS;

}
