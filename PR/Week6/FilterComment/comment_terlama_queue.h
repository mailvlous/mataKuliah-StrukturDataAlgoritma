#include "comment.h"
#include <stdbool.h>

typedef address Terlama;

bool isCommentTerlamaEmpty(address p);

address createCommentTerlama(char *comment);

void enqueue_Comment(address *p, address Pnew);

// void Ins_AkhirTerlama(address *p, address Pnew);

void dequeue_Comment(address *p, infotype *x);

// void Del_AkhirTerlama(address *p, infotype *x);

void printCommentTerlama(address p);





