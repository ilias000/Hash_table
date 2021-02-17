#include "hash_tableInterface.h"
#include "hash_tableTypes.h"

#include <stdio.h>
#include <stdlib.h>

#define TableSize 100 //The size of the table


struct SCInfo
{
	int size;//number of elements
	int tablesize;
} SCInfo;

struct SCHTableEntry
{
	KeyType key;
    HTItem item;
    struct SCHTableEntry *next;
} SCHTableEntry;

struct HTable
{
	struct SCInfo *info;
	struct SCHTableEntry *list;
} HTable;


int HashFunction(KeyType key)
{
  int h=0, a=127;
  for (; *key!='\0'; key++)
    h=(a*h + *key) % TableSize;
  return h;
}


HTHash HTCreate() //creates an empty hash
{	
	struct HTable table[TableSize];
	HTHash hthash=NULL;
	int i;

	hthash=table;
	hthash->info= malloc(sizeof(SCInfo));
	hthash->info->size = 0;	
	hthash->info->tablesize = TableSize;

	for(i=0;i<TableSize;i++)
	{
		table[i].info = hthash->info;
		table[i].list = NULL;
	}

	return hthash;
}

int HTSize(HTHash hash) //returns the number of elements in the hash
{
	return hash->info->size;
}


int Search(struct SCHTableEntry **next, KeyType key, HTItem *pitem)
{
	if((*next)->key == key)
	{
		pitem = &(*next)->item;
		return PITEM_TRUE; 
	}
	else 
	{
		if((*next)->next==NULL)
		{
			return PITEM_FALSE;
		}
		else 
		{
			return Search(&((*next)->next), key, pitem);
		}
	}
}


//des giati douleyei me . kai oxi me ->
int HTGet(HTHash hash, KeyType key, HTItem *pitem) //searches for key in the hash. If found, returns true (1) and copies the item in the pitem pointer passed as argument
{
	int h = HashFunction(key);
	int i;

	pitem=NULL;

	for(i=0;i<h;i++)//hash points to the write struct of the table
		hash++;
	if (hash->list==NULL)//an h lista einai kainh
	{
		return PITEM_FALSE;
	}
	if(hash->list->key==key)//an einai sto prwto komvo ths listas
	{
		pitem=&hash->list->item;
		return PITEM_TRUE;
	}
	else 
	{
		if(hash->list->next==NULL)//an h lista exei mono ena komvo
		{
			return PITEM_FALSE;
		}
		else
		{
			return Search(&(hash->list->next), key, pitem); 
		}
	}
}

/*
void last(SCHTableEntry *next, HTable *lastnext)//finds the last node of the list
{
	if(next==NULL)
		lastnext=next;
	else
		last(next->next, last);
}


void HTInsert(HTHash hash, KeyType key, HTItem item) //inserts a key (with its item) in the hash (replace if exists)
{
	int h = HashFunction (key);
	HTItem *pitem=NULL;
	HTable *lastnext;

	if(hash[h]->list==NULL)//h lista einai kainh
	{
		hash[h].list=malloc(sizeof(SCHTableEntry));
		hash[h].list->key=key;
		hash[h].list->item=item;
		hash[h].list->next->NULL;
		hash[h].info->size++;
	}
	else
	{
		if(HTGet(hash,key,pitem)=1)//replace if exists
			*pitem=item;
		else//h lista den einai kainh kai to key den yparxei hdh
		{
			last(hash[h]->list,lastnext);
			lastnext->next=malloc(sizeof(SCHTableEntry));
			lastnext->next->key=key;
			lastnext->next->item=item;
			lastnext->next->next=NULL;
		}
	}
}


HTRemove(HTHash hash, KeyType key); //removes the key from the hash
{

}

HTVisit(HTHash hash, visit); //calls visit(hash, key, item) for all entries in the hash (in arbitraryorder). visit is a function given by the user
{

}

HTDestroy(HTHash hash); //destroys the hash by freeing all reserved memory
{

}
*/