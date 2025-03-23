#ifndef COMMENT_H
#define COMMENT_H
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev

typedef char* infotype;
typedef struct tCommentList *address;
typedef struct tCommentList {
    infotype info;
    address  next;
    address prev;
} CommentList;

void isEmpty(address p);

address createComment(char *comment);

void Ins_Awal(address *p, address Pnew);

void Ins_Akhir(address *p, address Pnew);

void Del_Awal(address *p, infotype *x);

void Del_Akhir(address *p, infotype *x);

void printComment(address p);

#endif // !COMMENT_H
