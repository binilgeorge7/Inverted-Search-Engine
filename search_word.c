#include "header.h"

void search_word(Mainnode* arr[])
{
    char word[46];
    printf("Enter word : ");
    scanf(" %[^\n]", word);

    for (int i = 0; i < 27; i++)
    {
        if (arr[i] == NULL)
        {
            continue;
        }
        

        Mainnode *mtemp = arr[i];
        while (mtemp != NULL)
        {
            if(strcmp(mtemp->word, word) == 0) //compares with word
            {
                printf("Word Found\n");
                printf("\n=============================================================================================================\n");
                printf("%-15s  %-15s  %-30s \n","word", "File Count", "file name:Count");
                printf("=============================================================================================================\n");
                printf("%-15s  %-15d",mtemp->word, mtemp->file_count);

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
                printf("\n-------------------------------------------------------------------------------------------------------------\n");
                return;
            }
            printf("\n");
            mtemp = mtemp->mainlink;
        }
    }
    printf("\nword not found!!\n");
}
