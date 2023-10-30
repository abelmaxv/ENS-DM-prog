/*
_______________________________________
EXERCICE 1 DM PROGRAMMATION ENS L3 INFO
ABEL VERLEY
_______________________________________
*/

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

// Macro definitions for question A
#define BTREE_PARENT(n) (n)->parent
#define BTREE_LSON(n) (n)->lson
#define BTREE_RSON(n) (n)->rson

#define MAX_TAB 20000
static btree_t mem[MAX_TAB];
bool is_initialized = false;

// Set all entries as free
void initialize()
{
    for (int i = 0; i < MAX_TAB; i++)
    {
        mem[i].parent = (btree_t *)1;
    }
    is_initialized = true;
}

// Macro definition for question B
// Tests if the adress n->parent is even
#define BTREE_ISFREE(n) ((size_t)BTREE_PARENT(n) % 2 == 0) ? false : true

// Function definition for question C
btree_t *btree_alloc(void)
{
    if (!is_initialized)
    {
        initialize();
    }
    for (int i = 0; i < MAX_TAB; i++)
    {
        // Looks for a free entry of mem
        if (BTREE_ISFREE(mem + i))
        {
            btree_t tree = {0, NULL, NULL, NULL};
            mem[i] = tree;
            return mem + i;
        }
    }
    // If no free entry was found
    return NULL;
}

// Function definition for question D
void mark_function(char mark_tab[], btree_t *node);
unsigned int btree_gc(btree_t *vars[], int size)
{
    int counter = 0;
    char mark_tab[MAX_TAB];
    // Marks the nodes of the forest accesible via vars
    for (int i = 0; i < size; i++)
    {
        if (vars[i] != NULL)
            mark_function(mark_tab, vars[i]);
    }
    for (int i = 0; i < MAX_TAB; i++)
    {
        // Frees the unvisited occupied nodes
        if (!BTREE_ISFREE(mem + i) && !mark_tab[i])
        {
            BTREE_PARENT(mem + i) = (btree_t *)1;
            counter++;
        }
    }
    return counter;
}

// Recursive function which marks the nodes of the tree which root is node
void mark_function(char mark_tab[], btree_t *node)
{
    // Index of node in mem
    size_t index = ((size_t)node - (size_t)mem) / sizeof(btree_t);
    mark_tab[index] = 1;
    // Indexes of sons in mem
    btree_t *lson = BTREE_LSON(node);
    size_t index_lson = (size_t)lson - (size_t)mem;
    btree_t *rson = BTREE_RSON(node);
    size_t index_rson = (size_t)rson - (size_t)mem;
    // Recurcive calls if node has a not visited son
    if (lson != NULL && !mark_tab[index_lson])
        mark_function(mark_tab, lson);
    if (rson != NULL && !mark_tab[index_rson])
        mark_function(mark_tab, rson);
}

// Code from question E
int main(void)
{
    btree_t *vars[2];
    vars[0] = btree_alloc();
    vars[1] = btree_alloc();
    BTREE_PARENT(vars[0]) = vars[1];
    BTREE_LSON(vars[1]) = vars[0];
    BTREE_RSON(vars[1]) = BTREE_LSON(vars[0]) = BTREE_RSON(vars[0]) = NULL;
    vars[1] = NULL;
    printf("%d collected nodes\n", btree_gc(vars, 2));
    return 0;
}
// Result after execution :
// 1 collected nodes
