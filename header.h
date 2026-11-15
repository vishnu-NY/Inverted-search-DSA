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
    struct subnode* sublink;
};

create_database(struct mainnode* arr[]);
display_database(struct mainnode* arr[]);
search_word(struct mainnode* arr[]);
update_database(struct mainnode* arr[]);
save_database(struct mainnode* arr[]);


#endif