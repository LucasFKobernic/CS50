// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

int NUMBER_OF_WORDS=0;
// Represents a node in a hash table
typedef struct node
{
    char  word[LENGTH + 1];
    struct node *next;
}
node;
//Array with the keys for the hash table
char key[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
// Number of buckets in hash table
const unsigned int N = sizeof(key)/sizeof(key[0]);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int KEY = -1;
    KEY = hash(word);
    if (KEY == -1){
        printf("Cound not get the hash\n");
        return false;
    }
    node* cursor;
    cursor = table[KEY];
    while (cursor != NULL){
        if (strcasecmp(cursor->word, word)==0){
            return true;
        }
        else{
            cursor = cursor->next;
        }

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    for (int i =0; i < N ; i++)
        {
            if (word[0]==key[i] || word[0]== tolower(key[i]))
            {
                return i;
            }
        }
    return 1;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary
    FILE* dict;
    dict = fopen (dictionary, "r");
    if ( dict == NULL){
        printf ("Dictionary could not be open\n");
        return 1;
    }
    //Reading and saving the dictionary data
    char dict_word[LENGTH+1];
    int KEY = -1;
    while (fscanf(dict, "%s", dict_word) != EOF){
        node* new_node = malloc (sizeof(node));
        if (new_node == NULL){
            fclose (dict);
            return false;
        }
        strcpy (new_node -> word, dict_word);
        //Getting the key
        KEY = hash (new_node -> word);
        if (KEY == -1){
            printf ("Could not get the KEY for the HashTable\n");
            fclose(dict);
            return false;
        }
        //Inserting the new node
        if (table[KEY]  == NULL){
            table[KEY] = new_node;
            new_node-> next = NULL;
        }
        else{
            new_node -> next = table[KEY];
            table[KEY] = new_node;
        }
        NUMBER_OF_WORDS +=1;

    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (NUMBER_OF_WORDS ==0){
        return 0;
    }
    return NUMBER_OF_WORDS;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node* tmp;
    node* cursor;
    for (int i=0; i< N; i++){
        cursor = table[i];
        tmp = table[i];
        while (cursor!= NULL){
            cursor= cursor-> next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}

