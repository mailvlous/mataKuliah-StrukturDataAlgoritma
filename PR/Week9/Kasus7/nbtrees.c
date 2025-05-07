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

bool IsEmpty(Isi_Tree P) {
    return (P == NULL);
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

void PreOrder(Isi_Tree P) {
    if (IsEmpty(P)) {
        return;
    }
    address Pcur = 1; // root otomatis = 1
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
            resmi = false;
        }
    } while (P[Pcur].ps_pr != 0);
}


void PreOrderManual(Isi_Tree P) {
    if (IsEmpty(P)) {
        return;
    }

    int current = 1;       // root di indeks 1
    int arah = kebawah;    // mulai turun

    while (current != nil) {
        if (arah == kebawah) {
            printf("%c ", P[current].info);  // kunjungi node

            if (P[current].ps_fs != nil) {
                current = P[current].ps_fs;
                arah = kebawah;
            } else if (P[current].ps_nb != nil) {
                current = P[current].ps_nb;
                arah = kebawah;
            } else {
                arah = keatas;
            }
        } else if (arah == keatas) {
            // cari saudara jika ada
            if (P[current].ps_pr != nil && P[P[current].ps_pr].ps_nb != nil && P[P[current].ps_pr].ps_nb != current) {
                current = P[P[current].ps_pr].ps_nb;
                arah = kebawah;
            } else {
                current = P[current].ps_pr;
                if (current != nil) {
                    arah = keatas;
                }
            }
        }
    }

    printf("\n");
}


void InOrder(Isi_Tree P) {
    if (IsEmpty(P)){
        return;
    }

    address Pcur = 1;
    bool resmi = true;

    do {
        if (P[Pcur].ps_fs != 0 && resmi) {
            Pcur = P[Pcur].ps_fs;
            resmi = true;
        } else {
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

void PostOrder(Isi_Tree P) {
    if(IsEmpty(P)){
        return;
    }

    address Pcur = 1;
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


void Level_order(Isi_Tree X, int Maks_node) {
    if (Maks_node == 0) {
        printf("Tree kosong\n");
        return;
    }

    int queue[jml_maks];
    int front = 0, rear = 0;

    //diasumsikan di indeks 1
    queue[rear] = 1;
    rear++;

    while (front < rear) {
        int current = queue[front];
        front++; // ambil dari antrian

        printf("%c ", X[current].info); 

        // Masukkan semua anak dari simpul saat ini ke queue
        int child = X[current].ps_fs;

        while (child != 0) {
            queue[rear] = child;
            rear++;
            child = X[child].ps_nb;
        }
    }

    printf("\n");
}

// bool Search (Isi_Tree P, infotype X){
//     if (P == NULL) {
//         return;
//     } else if (P[] == X)
// }

bool Search(Isi_Tree T, infotype X) {
    int root = 1;
    if (root == 0) {
        return false;
    }

    if (T[root].info == X) {
        return true;
    }

    address child = T[root].ps_fs;
    while (child != 0) {
        if (Search(T, X)) {
            return true;
        }
        child = T[child].ps_nb;
    }

    return false;
}

int nbElmt (Isi_Tree P){
    int root = 1;
    if (root ==  0) {
        return 0;
    }
    int count = 0;
    for (int i = 1; i<jml_maks; i++){
        if (P[i].info != '\0'){
            count++;
        }
    }
    return count;
}

int nbDaun (Isi_Tree P){
    if (IsEmpty(P)){
        return 0;
    }
    int count = 0;
    int root = 1;
    for (int i = 1;i<jml_maks; i++){
        if (P[i].ps_fs == 0 ) {
            count++;
        }
    }
    return count;
}


int Level(Isi_Tree P, infotype x) {
    if (IsEmpty(P)){
        return 0;
    }

    int queue[jml_maks];
    int level[jml_maks];
    int front = 0, rear = 0;

    queue[rear] = 1;         // root ada di indeks 1
    level[1] = 0;
    rear++;

    while (front < rear) {
        int current = queue[front];
        front++;
        
        if (P[current].info == x) {
            return level[current];
        }

        int child = P[current].ps_fs;
        while (child != 0) {
            queue[rear] = child;
            level[child] = level[current] + 1;
            rear++;
            child = P[child].ps_nb;
        }
    }

    return -1;
}

int DepthRekursif(Isi_Tree P, address root) {
    if (root == 0) {
        return 0;
    }

    int maxChildDepth = 0;
    address child = P[root].ps_fs;

    while (child != 0) {
        int childDepth = DepthRekursif(P, child);
        if (childDepth > maxChildDepth) {
            maxChildDepth = childDepth;
        }
        child = P[child].ps_nb;
    }

    return 1 + maxChildDepth;
}

int Depth(Isi_Tree P) {
    return DepthRekursif(P, 1); // asumsi root ada di indeks 1
}

int Max(infotype Data1, infotype Data2) {
    if (Data1 > Data2) {
        return Data1;
    } else {
        return Data2;
    }
}

void traverse(Isi_Tree P, address node, char *prefix, int isLast) {
    if (node == 0) return;

    printf("%s", prefix);
    if (isLast) {
        printf("|-- ");
    } else {
        printf("+-- ");
    }

    printf("%c\n", P[node].info);

    char newPrefix[100];
    if (isLast) {
        sprintf(newPrefix, "%s    ", prefix);
    } else {
        sprintf(newPrefix, "%s|   ", prefix);
    }

    address child = P[node].ps_fs;
    while (child != 0) {
        address nextSibling = P[child].ps_nb;
        int childIsLast = (nextSibling == 0);
        traverse(P, child, newPrefix, childIsLast);
        child = nextSibling;
    }
}

void PrintTree(Isi_Tree P) {
    traverse(P, 1, "", 1);  // Mulai dari root
}
