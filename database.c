#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

status create_database(struct mainnode* arr[], struct ip_file* ip_head)
{
    
 while(ip_head != NULL)
 {
    FILE *fptr = fopen(ip_head->filename,"r");
    if(fptr == NULL)
    {
        printf("Error: Failed to open the file %s and hence it will be ignored\n",ip_head->filename);
        ip_head = ip_head->link;
        continue;
    }
    printf("Starting to scan the file %s\n",ip_head->filename);
    char word[50];
    int repeat_flag=0;

    while(fscanf(fptr,"%s",word) != EOF)
    {
        char first_letter = word[0];
        int index;
        index = hash_function(word);
        if(find_duplicate(arr[index],word) == 1)
        {
            increment_wordcount(arr[index],word,ip_head->filename);
        }
        else
        {
            insert_word(arr,word,ip_head->filename);
        }
    }
    printf("File %s closed\n",ip_head->filename);
    fclose(fptr);
    ip_head = ip_head->link;
    
 }   

}
status display_database(struct mainnode* arr[])
{
    for(int i=0;i<27;i++)
    {
        struct mainnode* temp = arr[i];
        while(temp != NULL)
        {
            printf("Word: %s, File Count: %d\n", temp->word, temp->filecount);
            struct subnode* subtemp = temp->sublink;
            while(subtemp != NULL)
            {
                printf("\tFilename: %s, Word Count: %d\n", subtemp->filename, subtemp->wordcount);
                subtemp = subtemp->link;
            }
            temp = temp->mainlink;
        }
    }
    return SUCCESS;

}
status search_word(struct mainnode* arr[])
{
    char search_word[50];
    printf("Enter the word to search: ");
    scanf("%s", search_word);
    int index = hash_function(search_word);
    struct mainnode* temp = arr[index];
    while(temp != NULL)
    {
        if(strcmp(temp->word,search_word) == 0)
        {
            printf("Word: %s found in %d files\n", temp->word, temp->filecount);
            struct subnode* subtemp = temp->sublink;
            while(subtemp != NULL)
            {
                printf("\tFilename: %s, Word Count: %d\n", subtemp->filename, subtemp->wordcount);
                subtemp = subtemp->link;
            }
            return SUCCESS;
        }
        temp = temp->mainlink;
    }
    printf("Word: %s not found in the database\n", search_word);
    return NOT_FOUND;
}
status update_database(struct mainnode* arr[])
{
    // Implementation of update_database function
    return SUCCESS;
}
status save_database(struct mainnode* arr[])
{  
    FILE *dptr = fopen("database.txt", "w");
    if(dptr == NULL)
    {
        printf("Error: Failed to open the database file for writing.\n");
        return FAILURE;
    }
}
status display_help_menu()
{
    printf("Input format: ./program_name file1.txt file2.txt ...\n");
    printf("Only .txt files are accepted. Other formats will be ignored.\n");
    return SUCCESS;
}