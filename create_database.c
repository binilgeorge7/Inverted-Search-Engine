#include "header.h"

int create_database(Flist* head,  Mainnode* arr[])
{

    Flist* temp = head;
    while(temp != NULL)  //traverse through flist take each valid filename
    {
        if (is_file_present(arr, temp->fname)) //to check if file name is already pressent in database
        {
            temp = temp->link;
            continue;  //skips if pressent
        }

        FILE* fp = fopen(temp->fname, "r");
        if(fp == NULL)
        {
            return FAILURE;
        }

        char word[46];
        while(fscanf(fp, "%s", word) == 1)
        {
            int i = 0;

            //to convert to lowercase characters
            while(word[i] != '\0')
            {
                word[i] = tolower(word[i]);
                i++;
            }
            

            int idx = 26;  //default index 
            if(word[0] >= 'a' && word[0] <= 'z' )
            {
                idx = word[0] - 'a';
            }
            else if(word[0] >= 'A' && word[0] <= 'Z')
            {
                idx = word[0] - 'A';
            }

            if(arr[idx] == NULL)
            {
                //creates subnode
                Subnode* snew = malloc(sizeof(Subnode));
                strcpy(snew->filename, temp->fname);
                snew->word_count = 1;
                snew->sublink = NULL;

                //creates mainnode
                Mainnode* mnew = malloc(sizeof(Mainnode));
                mnew->file_count = 1;
                strcpy(mnew->word, word);
                mnew->sublink = snew;
                mnew->mainlink = NULL;

                arr[idx] = mnew;
            }
            else
            {
                Mainnode* tempm = arr[idx];
                while(!((strcmp(tempm->word, word) == 0) || tempm->mainlink == NULL))
                {
                    tempm = tempm->mainlink;
                }
                if(strcmp(tempm->word, word) == 0)
                {
                    Subnode* temps = tempm->sublink;
                    while(!(!strcmp(temps->filename, temp->fname) || temps->sublink == NULL))
                    {
                        temps = temps->sublink;
                    }
                    if(!strcmp(temps->filename, temp->fname))
                    {
                        temps->word_count++;
                    }
                    else if(temps->sublink == NULL)
                    {
                        //create subnode
                        Subnode* snew = malloc(sizeof(Subnode));
                        strcpy(snew->filename, temp->fname);
                        snew->word_count = 1;
                        snew->sublink = NULL;

                        temps->sublink = snew;
                        tempm->file_count++;
                    }

                }
                else if(tempm->mainlink == NULL)
                {
                    //create subnode
                    Subnode* snew = malloc(sizeof(Subnode));
                    strcpy(snew->filename, temp->fname);
                    snew->word_count = 1;
                    snew->sublink = NULL;

                    //create main node
                    Mainnode* mnew = malloc(sizeof(Mainnode));
                    mnew->file_count = 1;
                    strcpy(mnew->word, word);
                    mnew->sublink = snew;
                    mnew->mainlink = NULL;

                    tempm->mainlink = mnew;
                }
            }
        }


        temp = temp->link;
        fclose(fp);
    }
    printf("\nDatabase Created\n");
}