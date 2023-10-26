#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Tree data structure for question A
typedef struct btree_s
{
    int data;
    struct btree_s *parent;
    struct btree_s *lson;
    struct btree_s *rson;
} btree_t;

//Macro definitions for question A
#define BTREE_PARENT(n) (n)->parent 
#define BTREE_LSON(n) (n)->lson
#define BTREE_RSON(n) (n)->rson

#define MAX_TAB 20000
static btree_t mem[MAX_TAB];


//Macro definition for question B
//Tests if the adress n->parent is even
#define BTREE_ISFREE(n) ((size_t)BTREE_PARENT(n) % 2 == 0)?false:true


//Function definition for question C
btree_t *btree_alloc(void)
{
    for (int i = 0; i<MAX_TAB; i++)
    {
        //Looks for a free entry of mem
        if (BTREE_ISFREE(mem + i))
        {
            btree_t tree;
            mem[i] = tree;
            return mem+i;
        }
    }
    //If no free entry was found
    return NULL;
}

//Function definition for question D
unsigned int btree_gc(btree_t* vars[])
{
    
}

int main()
{
    bool res = BTREE_ISFREE(mem);
    if(res) printf("ok \n");
    return 0;
}
