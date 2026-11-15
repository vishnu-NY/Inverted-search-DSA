#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

status validate_arguments(int argc, char* argv[], struct ip_file ** ip_file_head)
{
   if(argc<2) 
   {
    printf("Too few arguments. Please provide the necessary arguments.\n");
    printf("press 6 for help menu\n");
    return FAILURE;
   }
   int i = 1;
   while(argv[i]!=NULL)
   {
        char filenamebuffer[25]; strcpy(filenamebuffer,argv[i]);
        char file[25]; strcpy(file,strtok(filenamebuffer,"."));
        char extension[20]; strcpy(extension,strtok(NULL,"."));
        
        if((strcmp(extension,"txt")== 0) && (strtok(NULL,".")==NULL)) // to confirm there is nothing after txt entention. 
        {
            add_to_last_ip_files(argv[i],ip_file_head);
        }
        else
        {
            printf("Error : Input file - %s is invalid format and will be ignored\n",argv[i]);
        }
        i++;
   }
}