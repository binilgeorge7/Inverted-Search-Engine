#include "header.h"

void display_database(Mainnode* arr[])
{
    printf("\n\t\t\t\t\tINVERTED SEARCH DATABASE\n");
    printf("=============================================================================================================\n");
    printf("%-15s  %-15s  %-15s  %-30s \n","[index]", "word", "File Count", "file name:Count");
    printf("=============================================================================================================\n");
    for (int i = 0; i < 27; i++)
    {
        if (arr[i] == NULL)
        {
            continue;
        }
        

        Mainnode *mtemp = arr[i];
        while (mtemp != NULL)
        {
            printf("[%d] \t\t", i);
            printf(" %-15s  %-15d ",mtemp->word, mtemp->file_count);

            Subnode *stemp = mtemp->sublink;

            int flag = 0;  //to print ->
            while (stemp != NULL)
            {
                if(flag ==1)
                {
                    printf("->");
                }

                printf(" %s[%d]",stemp->filename, stemp->word_count);
                stemp = stemp->sublink;

                if(flag == 0) //for ->
                {
                    flag = 1;
                }
            }
            printf("\n");
            mtemp = mtemp->mainlink;
        }
    }

    printf("=============================================================================================================\n");
}
