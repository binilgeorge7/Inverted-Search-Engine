#include "header.h"

void update_database(Mainnode* arr[])
{
    char bkp[20];
    printf("Enter backup file name :");
    scanf(" %[^\n]", bkp);

    //opens backupfile
    FILE* fp = fopen(bkp, "r");
    if(fp == NULL)
    {
        printf("%s dont exist\n", bkp);
        return;
    }

    int index;
    char word[46];
    int file_count;
    while(fscanf(fp, "#%d;%[^;];%d;", &index, word, &file_count) == 3) //reads from file
    {

        Mainnode* mnew = malloc(sizeof(Mainnode));
        mnew->file_count = file_count;
        strcpy(mnew->word, word);
        mnew->mainlink = NULL;
        mnew->sublink = NULL;

        if(arr[index] == NULL)
        {
            arr[index] = mnew;
        }
        else
        {
            Mainnode* mtemp = arr[index];
            while(mtemp->mainlink != NULL)
            {
                mtemp = mtemp->mainlink;
            }
            mtemp->mainlink = mnew;
        }

        char file_name[20];
        int word_count;

        Subnode* prev =  NULL;
        for(int i = 0; i < file_count; i++) //reads from file till filecount times

        {

            fscanf(fp, "%[^;];%d;", file_name, &word_count);
            Subnode* snew = malloc(sizeof(Subnode));
            strcpy(snew->filename, file_name);
            snew->word_count = word_count;
            snew->sublink = NULL;

            if(i == 0)
            {
                mnew->sublink = snew;
                prev = snew;
            }
            else
            {
                prev->sublink = snew;
                prev = snew;
            }
        }

        //to skip # end move to end of current line(\n)
        char ch;
        while ((ch = fgetc(fp)) != '\n' && ch != EOF);
    }
    printf("\nDatabase Updated\n");
}