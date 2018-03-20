#include <stdlib.h>
#include <string.h>
#include "phonebook_opt.h"
#include <stdio.h>
#include <stdlib.h>

int hashFunc (char lastName[])
{
    int seed=131;
    int hashNum=0;

    while (*lastName){
        printf("*lastName:%d\n",*lastName);
        printf("hashNum*seed:%d\n",hashNum*seed);

        hashNum=hashNum*seed+(*lastName++);
    }
    printf("%d\n", hashNum%5471);
    return hashNum%5471;
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


