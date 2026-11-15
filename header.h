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




#endif