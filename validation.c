#include "header.h"

int validate(int argc, char* argv[], Flist** head)
{
    if(argc == 1)
    {
        return FAILURE;
    }

    int i = 1;

    char* ptr;
    
    while(argv[i] != NULL)
    {
        ptr = strstr(argv[i], ".txt");  //to check if it is a txt file
        if(ptr == NULL)
        {
            i++;
            continue;
        }
        else if(strcmp(ptr, ".txt") == 0) //to check if extension is .txt
        {
            FILE* fptr = fopen(argv[i], "r");
            if(fptr == NULL)  //if txt file doesnt exist
            {
                printf("%s doess not exist\n", argv[i]);
                //return FAILURE;
            }
            else
            {
                //to check if file is empty
                fseek(fptr, 0, SEEK_END);
                int size = ftell(fptr);
                if(size == 0)
                {
                    printf("%s is empty\n", argv[i]);
                }
                else if(find_node(*head, argv[i]) == FAILURE) //if copy doesnt exist
                {
                    insert_at_last(head, argv[i]);
                }
                fclose(fptr);
            }

        }
        i++;
    }
    return SUCCESS;
}

//to check if file is already pressent in database
int is_file_present(Mainnode* arr[], char* fname)
{
    for (int i = 0; i < 27; i++)
    {
        Mainnode* mtemp = arr[i];
        while (mtemp != NULL)
        {
            Subnode* stemp = mtemp->sublink;
            while (stemp != NULL)
            {
                if (strcmp(stemp->filename, fname) == 0)
                {
                    return 1;   // file pressent
                }
                stemp = stemp->sublink;
            }
            mtemp = mtemp->mainlink;
        }
    }
    return 0;   // file doesent exist
}

int insert_at_last(Flist **head, char* fname)
{
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->fname = fname;
    new->link = NULL;
    
    //If list is empty
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    
    //if list not empty
    Flist* temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    
    //update last node to link
    temp->link = new;
    return SUCCESS;
    
}

void print_list(Flist *head)
{
    
	if (head == NULL)
	{
		printf("INFO : File List is empty\n");
	}
    else
    {
        printf("\n===============================================\n");
        printf("\t\tFile List\n");
        printf("===============================================\n");
	    while (head)		
	    {
		    printf("%s\n", head -> fname);
		    head = head -> link;
	    }
        printf("===============================================\n");
    }
}

int find_node(Flist *head, char* fname)
{
    if(head == NULL)
    {
        return FAILURE;
    }
	Flist* temp = head;
	int i = 1;
    while(temp != NULL)
    {
        if(strcmp(temp->fname, fname) == 0)
        {
            return i;
        }
        temp = temp->link;
        i++;
    }
    return FAILURE;
}

