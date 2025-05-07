#include <stdio.h>
#include "nbtrees.h"
#include "nbtrees.c"


int main() {
    Isi_Tree tree;

    tree[1] = (nbtree){'A', 2, 0, 0};
    tree[2] = (nbtree){'B', 4, 3, 1};
    tree[3] = (nbtree){'C', 0, 0, 1};
    tree[4] = (nbtree){'D', 0, 5, 2};
    tree[5] = (nbtree){'E', 0, 0, 2};

    PrintTree(tree);
    
}