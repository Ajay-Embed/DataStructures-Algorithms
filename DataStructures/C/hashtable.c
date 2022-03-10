#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Try changing this */
#define TABLE_SIZE 4UL

/* Hash function  */
unsigned long hash (const char *key)
{
    unsigned long int value = 0; 
    unsigned int i = 0;
    unsigned int key_len = strlen(key);
   
    for(i=0; i<key_len; i++)
    {
        value = value*59 + key[i];
    }
    
    /* This value is the index/key of the hash table entry */
    value = value % TABLE_SIZE;

    return value; 
}

/* Struct to store one element of the hash table */
typedef struct ht_entry_t
{
    char *key;
    char value;
    /* For chaining to the next */
    struct ht_entry_t* next;

} ht_entry_t;

typedef struct
{
    ht_entry_t** table;

}hashtable_t;

hashtable_t* create(void)
{
    hashtable_t* ht = malloc(sizeof(hashtable_t));

    ht->table = malloc(sizeof(ht_entry_t)*TABLE_SIZE);

    int i; 

    for(i=0; i<TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }

    return ht;
}

void ht_insert(hashtable_t* hashtable, const char* key, char value)
{
    unsigned long int slot = hash(key);
    
    ht_entry_t* entry = malloc(sizeof(ht_entry_t));
    
    entry->key = malloc(strlen(key) + 1);
    strcpy(entry->key, key); 

    entry->value = value;
    entry->next = NULL;

    if(hashtable->table[slot] == NULL)
    {
        hashtable->table[slot] = entry; 
        return;
    }

    ht_entry_t* head = hashtable->table[slot]; 
    
    while(head->next)
    {
        if (strcmp(head->key, key) == 0) 
        {
            head->value = value;
            printf("HERE: ");
            return; 
        }

        head = head->next;
    }
    
    if (strcmp(head->key, key) == 0) 
    {
        head->value = value;
        return; 
    }

    else
        head->next = entry; 

    return;
}

char ht_getkey(hashtable_t* hashtable, const char* key)
{
    unsigned long int slot = hash(key); 

    if(hashtable->table[slot] == NULL)
    {
        return 0;
    }

    ht_entry_t* entry = hashtable->table[slot];

    while(entry)
    {
        if(strcmp(entry->key, key)== 0)
        {
            return entry->value;
        }

        entry = entry->next;
    }
    
    return 0; 
}

void print(hashtable_t* ht)
{
    int i; 

    for(i=0; i<TABLE_SIZE; i++)
    {
        ht_entry_t* entry = ht->table[i];
        
        if(entry == NULL)
        {
            continue;
        }

        printf("Slot[%4d]: ", i);

        while(entry)
        {
            printf("%s = %d", entry->key, entry->value);
            entry = entry->next;
        }

        printf("\n");
    }
}

int main()
{
    hashtable_t *ht = create();
 
    ht_insert(ht, "PJ", 20);

    //printf("PJ : %d\n", ht_getkey(ht, "PJ"));

    ht_insert(ht, "PJ", 40);
    ht_insert(ht, "PJE", 30);
    ht_insert(ht, "Pizza", 20);
    ht_insert(ht, "Hashtable", 90);
    ht_insert(ht, "Pasta", 50);



    print(ht);
    //printf("PJ: %d\n", ht_getkey(ht, "PJ"));
    //printf("PJE: %d\n", ht_getkey(ht, "PJE"));

    return 0; 
}
