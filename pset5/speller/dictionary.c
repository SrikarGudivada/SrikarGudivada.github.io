/**
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct node
{
    struct node *children[27];
    bool is_word;
}node;


int dictionary_words = 0;


struct node* getNewNode(void)
{
    struct node* newNode = (struct node*) calloc(1,sizeof(struct node));
    // newNode->is_word = false;
    // for(int i = 0; i < 27; i++)
    // {
    //     newNode->children[i] = NULL;
    // }
    return newNode;
}

struct node* root = NULL;

void freeNode(struct node* temp)
{
    for(int i = 0; i < 27; i++)
    {
        if(temp->children[i])
        {
            freeNode(temp->children[i]);
        }
    }
    free(temp);
    return;
}

/**
 * Returns true if word is in dictionary else false.
 */

bool check(const char *word)
{
    // TODO
    struct node* temp = root;
    
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        int index = (word[i] == '\'') ? 26 : (int)tolower(word[i]) - (int)'a';
        
        if(!temp->children[index])
        {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp->is_word);
}


/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    root = getNewNode();
    struct node *temp = root;
    FILE *fp = fopen(dictionary, "r");
    char word[LENGTH + 1] = {};
    if(fp == NULL)
    {
        printf("Couldnot open the dictionary\n");
        return false;
    }
     while(fscanf(fp, "%s", word) != EOF)
    {
        dictionary_words += 1;
        for(int i = 0, len = strlen(word); i < len; i++)
        {
            int index = (word[i] == '\'') ? 26 : (int)word[i] - (int)'a';
            
            if(!temp->children[index])
            {
                temp->children[index] = getNewNode();
            }
            temp = temp->children[index];
        }
        temp->is_word = true;
        temp = root;
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return dictionary_words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    freeNode(root);
    return true;;
}
