#include "header.h"

void save_database(Mainnode* arr[])
{
    char bkp[20]; //backupfile name
    printf("Enter backup file name : ");
    scanf(" %[^\n]", bkp);

    //opens file
    FILE* fp = fopen(bkp, "w");
    if(fp == NULL)
    {
        printf("Error while opening %s\n", bkp);
        return; 
    }
    
    for (int i = 0; i < 27; i++)
    {
        if (arr[i] == NULL)
        {
            continue;
        }
        
        Mainnode *mtemp = arr[i];
        while (mtemp != NULL)
        {
            fprintf(fp, "#");
            fprintf(fp, "%d;", i);
            fprintf(fp, "%s;%d;",mtemp->word, mtemp->file_count);

            Subnode *stemp = mtemp->sublink;

            int flag = 0;  //to print ,
            while (stemp != NULL)
            {
                fprintf(fp, "%s;%d;",stemp->filename, stemp->word_count);
                stemp = stemp->sublink;

                if(flag == 0) //for #
                {
                    flag = 1;
                }
            }
            fprintf(fp, "#\n");
            mtemp = mtemp->mainlink;
        }
    }
    printf("\nDatabase Saved\n");
}
