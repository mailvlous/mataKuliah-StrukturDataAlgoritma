#include <stdio.h>
#include "nbtrees.h"
#include "nbtrees.c"


int main() {
    Isi_Tree tree;

    tree[1] = (nbtree){'4', 2, 0, 0};
    tree[2] = (nbtree){'1', 4, 3, 1};
    tree[3] = (nbtree){'2', 0, 0, 1};
    tree[4] = (nbtree){'3', 0, 5, 2};
    tree[5] = (nbtree){'5', 0, 0, 2};

    int pilihan;
    char target;
    char a, b;
    while(1) {
        printf("\n=== MENU TREE ===\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencali Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 node Tree\n");
        printf("11. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // menghindari masalah newline di scanf

        switch (pilihan)
        {
        case 1:
            PreOrder(tree);
            break;
        case 2:
            InOrder(tree);
            break;
        case 3:
            PostOrder(tree);
            break;
        case 4:
            Level_order(tree, 5);
            break;
        case 5:
            PrintTree(tree);
            break;
        case 6:

            printf("Masukkan karakter yang dicari: ");
            scanf(" %c", &target); // spasi sebelum %c penting
            
            if (!Search(tree, target)) {
                printf("Elemen '%c' tidak ditemukan\n", target);
            } else {
                printf("Elemen '%c' ditemukan\n", target);
            }
            break;
        case 7:

            printf("Jumlah daun: %d", nbDaun(tree));
            
            break;
        case 8:
            printf("Masukkan node: ");
            scanf(" %c", &target); // spasi sebelum %c penting
            
            if (!Search(tree, target)) {
                printf("Elemen '%c' tidak ditemukan\n", target);
            } else {
                printf("Node berada pada level:\n", Level(tree, target));
            }
                
            break;
        case 9:
            printf("Kedalaman tree: %d", Depth(tree));
            
            break;
        case 10:


            printf("Masukkan dua karakter:\n");
            printf("Karakter pertama: ");
            scanf(" %c", &a); 
            printf("Karakter kedua: ");
            scanf(" %c", &b);
            
            char hasil = Max(a, b);
            printf("Max: '%c'\n", hasil);
        
                
            break;
            
        break;
        case 11:
            return 0;
                
            break;
        default:
            break;
        }
    }
    
}