#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

int hashFunc (char lastName[])
{
    int seed=31;
    long long hashNum=0;

    while (*lastName)
        hashNum=hashNum*seed+(*lastName++);

    return hashNum%1024;
}

entry *findName(char lastName[], entry *pHead)
{

    int hashNum=hashFunc(lastName);
    entry *find;
    find=hashTable[hashNum].pNext;

    while (find != NULL) {
        if (strcasecmp(lastName, find->lastName) == 0) {
            return find;
        }
        find = find->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{
    entry *Newentry;
    int hashNum=hashFunc(lastName);
    Newentry = (entry *) malloc(sizeof(entry));
    
    entry *current=hashTable[hashNum].pNext;

    while(current!=NULL)
        current=current->pNext; //（*current）.pNext = current->pNext
    hashTable[hashNum].pNext=Newentry;

    strcpy(Newentry->lastName, lastName);

    return e;
}


