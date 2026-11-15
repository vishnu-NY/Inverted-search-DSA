#include<stdio.h>
#include<string.h>
#include"header.h"
#include<stdlib.h>

int main (int argc, char **argv)
{
    struct mainnode* arr[27] = {NULL};
    struct ip_file* ip_files_head = NULL;

    int choice=0;

    validate_arguments(argc,argv,&ip_files_head);


    while(choice != 7)
    {
        printf("\n1. Create Database\n2. Display Database\n3. Search Word\n4. Update Database\n5. Save Database\n6. Help menu\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create_database(arr,ip_files_head);
                break;
            case 2:
                display_database(arr);
                break;
            case 3:
                search_word(arr);
                break;
            case 4:
                update_database(arr);
                break;
            case 5:
                save_database(arr);
                break;
            case 6:
                display_help_menu();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    
}