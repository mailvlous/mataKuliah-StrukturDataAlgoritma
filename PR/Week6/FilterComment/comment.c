#include "comment.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>



void isEmpty(address p) {
    if (p == NULL) {
        printf("CommentList masih kosong\n");
    }
}

address createComment(char *comment) {
    address P = (address)malloc(sizeof(CommentList)); 
    if (P != NULL) {
        Info(P) = (char *)malloc(strlen(comment) + 1); 
        if (Info(P) != NULL) {
            strcpy(Info(P), comment); 
        }
        Next(P) = NULL;
        Prev(P) = NULL;
    }
    return P;
}

void Ins_Awal(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = *p;
    *p = Pnew;
}

void Ins_Akhir(address *p, address Pnew) {
    if (Pnew == NULL) return;

    Next(Pnew) = NULL;

    if (*p == NULL) {
        *p = Pnew;
    } else {
        address last = *p;
        while (Next(last) != NULL) {
            last = Next(last);
        }
        Next(last) = Pnew;
    }
}

void Del_Awal(address *p, infotype *x) {
    if (*p == NULL) return;

    else {
        address temp = *p;
        Next(temp) = NULL;
        *x = Info(temp);
        *p = Next(*p);
        free(temp);
    }

}

void Del_Akhir(address *p, infotype *x) {
    if (*p == NULL) return;

    else if (Next(*p) == NULL) {
        *x = Info(*p);
        free(*p);
        *p = NULL;
    } else {
        address prev = NULL;
        address curr = *p;
        while (Next(curr) != NULL) { //selama belum mencapa nextnya null
            prev = curr;
            curr = Next(curr);
        }
        *x = Info(curr);
        Next(prev) = NULL;
        free(curr);
    }
}

void printComment(address p) {
    if (p == NULL) {
        printf("CommentList masih kosong\n");
    } else {
        while (p != NULL) {
            printf("[%s]\n", Info(p));
            p = Next(p);
        }
    }
    printf("\n");
}