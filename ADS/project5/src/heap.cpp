#include "heap.hpp""
#include <iostream>
hheap Emptyheap(int size)
{
    hheap Mheap;
    Mheap = new struct huffmanheap;
    Mheap->size = 0;
    Mheap->tree = new tnode[size+1];
    
    tnode guard = new struct huffmanNode;
    guard->fre = -1;
    guard->left = guard->right = NULL;

    Mheap->tree[Mheap->size] = guard;

    return Mheap;
}


void Insert(hheap Mheap, tnode node)
{
    Mheap->size++;
    int i = Mheap->size;

    while(node->fre < Mheap->tree[i/2]->fre)
    {
        Mheap->tree[i] = Mheap->tree[i/2];
        i /= 2;
    }
    Mheap->tree[i] = node;
    //std::cout<<(i)<< std::endl;
}

huffmantree deletenode(hheap Mheap)
{
    huffmantree tree = Mheap->tree[1];
    
    Mheap->tree[1] = Mheap->tree[(Mheap->size)--];
    //std::cout<<(Mheap->tree[7]->fre)<< std::endl;
    int parent = 1, child = 2;
    while (child <= Mheap->size)
    {
        
        if ((child+1 <= Mheap->size) && (Mheap->tree[child+1]->fre < Mheap->tree[child]->fre))
        {
            ++child;
        }
        
        huffmantree tmp;
        //std::cout<<(Mheap->tree[1]->fre)<< std::endl;
        if ( Mheap->tree[child]->fre < Mheap->tree[parent]->fre)
        {
            //printf("%d ok3\n",Mheap->size);
            tmp = Mheap->tree[child];
            Mheap->tree[child] = Mheap->tree[parent];
            Mheap->tree[parent] = tmp;
            parent = child;
            child *= 2;
            
        }
        else
        {
            //printf("%d ok3\n",Mheap->size);
            break;
        }
        
    }
    
    return tree;
}

huffmantree construct(hheap Mheap)
{
    int Loop = Mheap->size-1;
    //printf("ok\n");
    huffmantree t0, t1, t;
    for ( int i = 0; i < Loop; ++i )
    {
        t = new struct huffmanNode;
        t0 = deletenode(Mheap);
        //printf("ok1\n");
        t1 = deletenode(Mheap);
        //printf("ok2\n");
        t->fre = t0->fre + t1->fre;
        t->left = t0, t->right = t1;

        Insert(Mheap, t);
        
    }

    return deletenode(Mheap);
}

int calculateWPL(huffmantree node, int height)
{
    if(!node->left && !node->right)
    {
        return node->fre * height;
    }
    else
    {
        return calculateWPL( node->left, height+1) + calculateWPL(node->right, height+1);
    }
}

bool Judge(std::string a, std::string b)
{
    for ( int i = 0; i < a.length() && i < b.length(); ++i )
    {
        if (a[i] != b[i])
        {
            return true;
        }
    }
    return false;
}