#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

status create_database(struct mainnode* arr[], struct ip_files* ip_head)
{
    
 while(ip_head != NULL)
 {
    FILE *fptr = fopen(ip_head->filename,"r")
    if(fptr == NULL)
    {
        printf("Error: Failed to open the file %s and hence it will be ignored\n");
        ip_head = ip_head->link;
        continue;
    }
    char word[25];
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
            insert_word(&arr,word,ip_head->filename);
        }
    }
    
 }   

}
status display_database(struct mainnode* arr[])
{
    
}
status search_word(struct mainnode* arr[])
{
    // Implementation of search_word function
    return SUCCESS;
}
status update_database(struct mainnode* arr[])
{
    // Implementation of update_database function
    return SUCCESS;
}
status save_database(struct mainnode* arr[])
{   
    // Implementation of save_database function
    return SUCCESS;
}
status display_help_menu()
{
    // Implementation of display_help_menu function
    return SUCCESS;
}