#ifndef __hash_tableInterface__
#define __hash_tableInterface__

#include "hash_tableTypes.h"

HTHash HTCreate(); //creates an empty hash

int HTSize(HTHash hash); //returns the number of elements in the hash

int HTGet(HTHash hash, KeyType key, HTItem *pitem); //searches for key in the hash. If found, returns true (1) and copies the item in the pitem pointer passed as argument

void HTInsert(HTHash hash, KeyType key, HTItem item); //inserts a key (with its item) in the hash (replace if exists)
/*
HTRemove(hash, key); //removes the key from the hash

HTVisit(hash, visit); //calls visit(hash, key, item) for all entries in the hash (in arbitraryorder). visit is a function given by the user

HTDestroy(hash); //destroys the hash by freeing all reserved memory
*/
#endif