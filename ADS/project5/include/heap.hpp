#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <iostream>

typedef struct huffmanNode
{
    int fre;
    huffmanNode* left = NULL;
    huffmanNode* right = NULL;
}*tnode, *huffmantree;

typedef struct huffmanheap
{
    huffmanNode** tree;
    int size;
} ;

typedef huffmanheap* hheap;

hheap Emptyheap(int size);
void Insert(hheap Mheap, tnode node);
huffmantree deletenode(hheap Mheap);
huffmantree construct(hheap Mheap);
int calculateWPL(huffmantree node, int height);
bool Judge(std::string a, std::string b);

#endif