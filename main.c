/*
Name    : Binil George
Date    : 26-12-2025
PROJECT : Inverted Search Engine using Hashing and Linked Lists

DESCRIPTION:
    This project implements an Inverted Search Engine in C that indexes
    words from multiple text files and allows efficient searching of words
    across those files.

    The program builds an inverted index where each unique word is stored
    along with the list of files in which it appears and the corresponding
    word count. Hashing is used to group words based on their starting
    character for faster access.

    The database supports incremental creation, meaning new files can be
    indexed without rebuilding the entire database. It also provides
    persistent storage by saving the database into a backup file and
    restoring it using an update mechanism.

FEATURES:
    -> Indexes words from multiple .txt files
    -> Uses hash table with 27 indices (a–z and special characters)
    -> Stores word frequency for each file
    -> Supports incremental database creation
    -> Search functionality with detailed results
    -> Save and restore database using backup file
    -> Handles punctuation and case normalization
    -> Dynamic memory allocation using linked lists

DATA STRUCTURES USED:
    -> Singly Linked List (File list)
    -> Hash Table (Array of Main Node pointers)
    -> Linked Lists (Main nodes and Sub nodes)

USAGE:
    ./a.out file1.txt file2.txt file3.txt

            or using makefile
    ./invert.out file1.txt file2.txt file3.txt file4.txt

Example:
    ./a.out data1.txt data2.txt
*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>
#include "header.h"

int main(int argc, char* argv[])
{
    Flist* head = NULL;
    validate(argc, argv, &head);
    print_list(head);

    Mainnode* arr[27] = {NULL};

    //to indicate whether database is created
    int create_flag = 0; 
    int update_flag = 0; 

    int opt;
    
    do
    {
        //prompt
        printf("\n====Inverted Search Menu====\n");
        printf("1. Create Database\n2. Display Database\n3. Search Word\n4. Save Database\n5. Update Database\n6. Exit\n");

        printf("Enter choice :");
        scanf("%d", &opt);

        getchar();
        switch(opt)
        {
            case 1:
                if(create_flag == 0)
                {
                    create_database(head, arr);  //function call for create database
                    create_flag = 1;
                }
                else
                {
                    printf("\nDatabase Cannot be created multiple times in same execution!!\n");
                }
                break;
            case 2:
                if(create_flag == 1 || update_flag == 1)
                {
                    display_database(arr);  //function call for display database
                }
                else
                {
                    printf("\nDatabase is Empty!!\n");
                }
                break;
            case 3:
                search_word(arr);   //function call for searching word
                break;
            case 4:
                if(create_flag == 1 || update_flag == 1)
                {
                    save_database(arr);   //saves daatabase
                }
                else
                {
                    printf("\nDatabase is Empty\n");
                }
                break;
            case 5:
                if(create_flag == 0 && update_flag == 0)
                {
                    update_database(arr);  //updates database
                    update_flag = 1;
                }
                else
                {
                    printf("\nDatabase Cannot be updated when database already exists!!\n");
                }
                break;
            case 6:
                break;
            default:
                printf("\nInvalid choice!!\n");
        }
    } while(opt != 6);

}