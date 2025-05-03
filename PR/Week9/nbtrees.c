#include <stdio.h>
#include "nbtrees.h"



void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    printf("Masukkan data node (level-order):\n");
    for (i = 1; i <= Jml_Node; i++) {
        printf("Node ke-%d:\n", i);
        printf("  Info (char): ");
        scanf(" %c", &X[i].info);
        
        printf("  Index anak pertama (0 jika tidak ada): ");
        scanf("%d", &X[i].ps_fs);

        printf("  Index saudara berikutnya (0 jika tidak ada): ");
        scanf("%d", &X[i].ps_nb);

        printf("  Index parent (0 jika root): ");
        scanf("%d", &X[i].ps_pr);
    }

    for (int i = 1; i <= Jml_Node; i++) {
        printf("Node %d: info = %c, child = %d, sibling = %d, parent = %d\n",
               i, X[i].info, X[i].ps_fs, X[i].ps_nb, X[i].ps_pr);
    }
}

bool isEmpty(Isi_Tree P) {
    return
}

// void Preorder(Isi_Tree P, address idx) {
//     if (idx == 0) return;
//     bool resmi;

//     printf("%c ", P[idx].info);
//     resmi = true;
//     if (P[idx].ps_fs != 0 && resmi) {
//         idx = P[idx].ps_fs;
//         printf("%c", P[idx].info);
//     } else if (P[idx].ps_nb != 0){
//         idx = P[idx].ps_nb;
//         printf("%c", P[idx].info);
//         resmi = true;
//     } else {
//         idx = P[idx].ps_pr;
//         resmi = false;
//     }

// }

void Preorder(Isi_Tree P, address idx) {
    address Pcur = idx; // mulai dari root (biasanya 1)
    bool resmi = true;

    printf("%c ", P[Pcur].info); 

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            printf("%c ", P[Pcur].info);
        } else if (P[Pcur].ps_nb != 0) {
            Pcur = P[Pcur].ps_nb;
            printf("%c ", P[Pcur].info);
            resmi = true;
        } else {
            Pcur = P[Pcur].ps_pr;
            resmi = false; // numpang lewat
        }
    } while (P[Pcur].ps_pr != 0); // berhenti jika sudah balik ke root
}

void Postorder(Isi_Tree P, address idx) {
    address Pcur = idx;
    bool resmi = true;

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            resmi = true;
        } else if (P[Pcur].ps_nb != 0 && resmi == false) {
            Pcur = P[Pcur].ps_nb;
            
            resmi = true;
        } else {
            printf("%c", P[Pcur].info);
            Pcur = P[Pcur].ps_pr;
            resmi = false;
        }
    } while (P[Pcur].ps_pr != 0 && resmi == false); 
}

void Postorder(Isi_Tree P, address idx) {
    address Pcur = idx;
    bool resmi = true;

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            resmi = true;
        } else if (P[Pcur].ps_nb != 0 && resmi == false) {
            Pcur = P[Pcur].ps_nb;
            
            resmi = true;
        } else {
            printf("%c", P[Pcur].info);
            Pcur = P[Pcur].ps_pr;
            resmi = false;
        }
    } while (P[Pcur].ps_pr != 0 && resmi == false); 
}

void Postorder(Isi_Tree P, address idx) {
    address Pcur = idx;
    bool resmi = true;

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            resmi = true;
        } else if (P[Pcur].ps_nb != 0 && resmi == false) {
            Pcur = P[Pcur].ps_nb;
            
            resmi = true;
        } else {
            printf("%c", P[Pcur].info);
            Pcur = P[Pcur].ps_pr;
            resmi = false;
        }
    } while (P[Pcur].ps_pr != 0 && resmi == false); 
}

void Postorder(Isi_Tree P, address idx) {
    address Pcur = idx;
    bool resmi = true;

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            resmi = true;
        } else if (P[Pcur].ps_nb != 0 && resmi == false) {
            Pcur = P[Pcur].ps_nb;
            
            resmi = true;
        } else {
            printf("%c", P[Pcur].info);
            Pcur = P[Pcur].ps_pr;
            resmi = false;
        }
    } while (P[Pcur].ps_pr != 0 && resmi == false); 
}

void Inorder(Isi_Tree P, address idx) {
    address Pcur = idx;
    bool resmi = true;

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            resmi = true;
        } else {
            // CETAK NODE di sini
            printf("%c ", P[Pcur].info);

            if (P[Pcur].ps_nb != 0) {
                Pcur = P[Pcur].ps_nb;
                resmi = true;
            } else {
                Pcur = P[Pcur].ps_pr;
                resmi = false;
            }
        }
    } while (Pcur != 0);
}

