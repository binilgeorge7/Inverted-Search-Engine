#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "header.h"
#include<stdlib.h>

typedef struct flist
{
    char* fname;
    struct flist* link;
} Flist;

typedef struct Sub_Node
{
    char filename[20];
    int word_count;
    struct Sub_Node* sublink;
} Subnode;

typedef struct Main_Node
{
    int file_count;
    char word[46];
    struct Main_Node* mainlink;
    struct Sub_Node* sublink;
} Mainnode;

#define SUCCESS 1
#define FAILURE 0

int insert_at_last(Flist **head, char* fname);
int validate(int argc, char* argv[], Flist** head);
void print_list(Flist *head);
int find_node(Flist *head, char* fname);
int create_database(Flist* head,  Mainnode* arr[]);
void display_database(Mainnode* arr[]);
void search_word(Mainnode* arr[]);
void save_database(Mainnode* arr[]);
void update_database(Mainnode* arr[]);
int is_file_present(Mainnode* arr[], char* fname);
//void clean_word(char *word);

#endif