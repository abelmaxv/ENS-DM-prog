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

//Code from question E
int main(void) 
{
    btree_t* vars[2];
    vars[0] = btree_alloc();
    vars[1] = btree_alloc();
    BTREE_PARENT(vars[0]) = vars[1];
    BTREE_LSON(vars[1]) = vars[0];
    BTREE_RSON(vars[1]) = BTREE_LSON(vars[0]) = BTREE_RSON(vars[0]) = NULL; vars[1] = NULL;
    printf("%d collected nodes\n", btree_gc(vars));
    return 0;
}
// Result after execution : 
/*


*/

