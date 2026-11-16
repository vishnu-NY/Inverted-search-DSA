#ifndef HEADER
#define HEADER

struct mainnode
{
    char word[25];
    int filecount;
    struct mainnode* mainlink;
    struct subnode* sublink;
};

struct subnode
{
    char filename[25];
    int wordcount;
    struct subnode* link;
};

struct ip_file
{
    char filename[26];
    struct ip_file* link;
};

typedef enum
{
    SUCCESS,
    FAILURE,
    DUPLICATE,
    EMPTY,
    NOT_FOUND
} status;

status create_database(struct mainnode* arr[], struct ip_file* ip_head);
status display_database(struct mainnode* arr[]);
status search_word(struct mainnode* arr[]);
status update_database(struct mainnode* arr[]);
status save_database(struct mainnode* arr[]);
status display_help_menu();

status validate_arguments(int argc, char* argv[], struct ip_file ** ip_file_head);
status add_to_last_ip_files(char* filename,struct ip_file** head );

int increment_wordcount(struct mainnode* head,char *word, char* filename);
int insert_word(struct mainnode* arr[],char* word, char* filename);
int find_duplicate(struct mainnode* head,char* word);
int hash_function(char* word);

#endif