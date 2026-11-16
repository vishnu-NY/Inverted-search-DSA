#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

int hash_function(char* word)
{
    char first_letter = word[0];
    int index;
    if(first_letter >= 'a' && first_letter<='z')
    {
        index = first_letter - 'a';
    }
    else if(first_letter >= 'A' && first_letter<='Z')
    {
        index = first_letter - 'A';
    }
    else
    {
        index = 26;
    }
    return index;
}
int find_duplicate(struct mainnode* head,char* word)
{
    struct mainnode* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->word,word) == 0)
        {
            return 1;
        }
        temp = temp->mainlink;
    }
    return 0;
}
int insert_word(struct mainnode* arr[],char* word,char*filename)
{
    struct mainnode* newmain = malloc(sizeof(struct mainnode));
    struct subnode* newsub = malloc(sizeof(struct subnode));
    newmain->mainlink = NULL;
    strcpy(newmain->word,word);
    strcpy(newsub->filename,filename);
    newmain->filecount = 1;
    newsub->wordcount = 1;
    newsub->link = NULL; 
    newmain->sublink = newsub;
    
    if(arr[hash_function(word)] == NULL)
    {
        arr[hash_function(word)] = newmain;
        return SUCCESS;
    }
    struct mainnode* temp = arr[hash_function(word)];
    while(temp->mainlink !=NULL)
    {
        temp = temp->mainlink;
    }
    temp->mainlink = newmain;

    return SUCCESS;
}

int increment_wordcount(struct mainnode* head,char *word, char* filename)
{
    struct mainnode* maintemp = head;
    struct subnode* subtemp = NULL;
    struct subnode* prev = NULL;
    while(maintemp!=NULL)
    {
        if(strcmp(maintemp->word,word)==0)
        {
            subtemp = maintemp->sublink;
            prev = subtemp;
            while(subtemp!=NULL)
            {
                if(strcmp(subtemp->filename,filename)==0)
                {
                    subtemp->wordcount ++;
                    return SUCCESS;
                } 
                prev = subtemp;
                subtemp = subtemp->link;
            }

            struct subnode* newsub = malloc(sizeof(newsub));
            newsub->link =NULL;
            strcpy(newsub->filename,filename);
            newsub->wordcount = 1;
            prev->link = newsub;

        }
    }
}