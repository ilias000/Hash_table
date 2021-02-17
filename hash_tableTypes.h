#ifndef __hash_tableTypes__
#define __hash_tableTypes__

typedef int HTItem;
typedef int TableSize;

typedef char* KeyType;
typedef struct HTable *HTHash;

#define PITEM_FALSE 0;
#define PITEM_TRUE 1;

#ifdef HT_IMPL_SEPARATE_CHAIN
    // use seperate chain
	struct SCInfo;
	struct SCHTableEntry;
	struct HTable;
	
#else
    // use open adressing
    
#endif

//typedef void(*BTFun)(BTTree tree, BTNode node);

#endif