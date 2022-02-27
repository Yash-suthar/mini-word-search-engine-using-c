#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// global verialbles
typedef struct node1
{
    int lineno;
    char ffname[15];
    struct node1 *next;
} node1;
typedef struct node
{

    char word[20];
    struct node1 *info;
    struct node *next;
} node;

node *root;
node1 *boot;
char filename[20][20];
const int k;

// function for save word
int linkedlist(char cword[], char fname[], int count)
{
    node *ptr;
    node *new;

    node1 *new_node;
    new = (node *)malloc(sizeof(node));
    new_node = (node1 *)malloc(sizeof(node1));

    if (root == NULL)
    {
        new->next = NULL;
        strcpy(new->word, cword);
        new_node->lineno = count;
        strcpy(new_node->ffname, fname);
        new_node->next = NULL;
        new->info = new_node;
        root = new;
    }
    else
    {
        ptr = root;
        while (ptr->next != NULL)
        {
            if (strcmp(ptr->word, cword) == 0)
            {
                node1 *ctr;
                ctr = ptr->info;
                while (ctr->next != NULL)
                {
                    ctr = ctr->next;
                }
                new_node->lineno = count;
                strcpy(new_node->ffname, fname);
                new_node->next = NULL;
                ctr->next = new_node;
                return 0;
            }

            ptr = ptr->next;
        }
        if (strcmp(ptr->word, cword) == 0)
        {
            node1 *ctr;
            ctr = ptr->info;
            while (ctr->next != NULL)
            {
                printf("this is");
                ctr = ctr->next;
            }
            new_node->lineno = count;
            strcpy(new_node->ffname, fname);
            new_node->next = NULL;
            ctr->next = new_node;
            return 0;
        }

        new->next = NULL;
        strcpy(new->word, cword);
        new_node->lineno = count;
        strcpy(new_node->ffname, fname);
        new_node->next = NULL;
        new->info = new_node;
        ptr->next = new;
    }
    return 0;
}
// function for serach word
int searchword(char search[])
{
    node *ptr;
    ptr = root;
    while (ptr->next != NULL)
    {
        if (strcmp(ptr->word, search) == 0)
        {
            node1 *ctr;
            ctr = ptr->info;
            printf("\n");
            printf("\n");
            printf("word found\'%s'", ptr->word);
            printf("\n---------------------------");

            while (ctr->next != NULL)
            {
                printf("\n%s", ctr->ffname);
                printf("\nline no: %d", ctr->lineno);
                printf("\n---------------------------");

                ctr = ctr->next;
            }
            printf("\n%s", ctr->ffname);
            printf("\nline no: %d", ctr->lineno);
            return 0;
        }
        ptr = ptr->next;
    }
    if (strcmp(ptr->word, search) == 0)
    {

        node1 *ctr;
        ctr = ptr->info;
        printf("\n");
        printf("\n");
        printf("word found\'%s'", ptr->word);
        printf("\n---------------------------");

        while (ctr->next != NULL)
        {
            printf("\n%s", ctr->ffname);
            printf("\nline no: %d", ctr->lineno);
            printf("\n---------------------------");

            ctr = ctr->next;
        }
        printf("\n%s", ctr->ffname);
        printf("\nline no: %d", ctr->lineno);
        return 0;
    }
    else
    {
        printf("\n");

        printf("word \'%s\' not found..");
    }

    return 0;
}

// function for list filename from directory

int scanfile(char path[])
{
    int count = 0, i = 0;
    DIR *d;
    char *ext;
    struct dirent *dir;
    d = opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            count++;
            if (count < 3)
                continue;

            ext = strrchr(dir->d_name, '.');

            if (strcmp(ext + 1, "txt") == 0)
            {
                strcpy(filename[i], dir->d_name);
                i++;
            }
        }
        closedir(d);
    }
    return 0;
}

// main function

int main()
{
    FILE *fp;
    char tempc[20], ch, search[20], path[150], cpath[150], sl[3] = "\\", copyfilename[20];
    int i = 0, nofiles, j = 0, l;
    printf("DS PROJECT TEAM MEMBERS");
    printf("\n");
    printf("\nSUTHAR YASH(190220131134)");
    printf("\nVAGHELA SATYENDRA(190220131148)");
    printf("\nPATEL VANDAN(190220131094)");
    printf("\n");
    while (1)
    {
        printf("\nEnter directory Path:");
        // scanf("%s", &path);
        gets(path);
        scanfile(path);
        if (strlen(filename[0]) == 0)
        {
            printf("No txt files in such directory...");
            continue;
        }
        else
        {
            break;
        }
    }
    printf("\nAvailable txt file in this directory");
    printf("\n----------------------------");
    while (strlen(filename[j]) != 0)
    {

        printf("\n%d.%s", j + 1, filename[j]);
        j++;
    }
    printf("\n----------------------------");
    strcpy(path, strcat(path, sl));
    strcpy(cpath, path);
    printf("\n");
    printf("\n1.Scan all files in this directory");
    printf("\n2.Scan manually ");
    printf("\n");
    while (1)
    {
    printf("\nEnter your choice:");
    scanf("%d", &k);
       
    if (k == 1)
    {
        nofiles = j;
        break;
    }
    else if (k == 2)
    {

        printf("\nhow many files you want to scan?(maximum:20 files):");
        scanf("%d", &nofiles);
        break;
    }
    else
    { printf(".............Enter valid input.");
        continue;
    }
    
    }
    

    while (i < nofiles)
    {
        int count = 1;
        strcpy(path, cpath);
        if (k == 1)
        {
            fp = fopen(strcat(path, filename[i]), "r");
            strcpy(copyfilename, filename[i]);
        }
        else if (k == 2)
        {

            printf("\nEnter file index No:");
            scanf("%d", &l);
            fp = fopen(strcat(path, filename[l - 1]), "r");
            strcpy(copyfilename, filename[l - 1]);
        }
        if (fp == NULL)
        {
            printf("file cannot be open..");
            return 0;
        }
        while (1)
        {
            fscanf(fp, "%s", &tempc);

            if (strlen(tempc) > 2)
            {
                linkedlist(tempc, copyfilename, count);
            }

            ch = fgetc(fp);

            if (ch == '\n')
            {
                count++;
            }

            if (ch == EOF)
                break;
        }
        printf("\nfile \'%s\' scanned.", copyfilename);
        i += 1;
        fclose(fp);
    }
    printf("\n");

    while (1)
    {
        printf("\n");
        printf("\nSearch word(For Exit Enter:0):");
        scanf("%s", &search);
        if (strcmp(search, "0") == 0)
            break;
        searchword(search);
    }

    printf("\nexit sucessfully");
    return 0;
}
