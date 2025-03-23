#include "comment.h"
#include "comment_terlama_queue.h"



bool isCommentTerlamaEmpty(address p){
    isEmpty(p);
}

address createCommentTerlama(char *comment){
    address Pnew = createComment(comment);
    return Pnew;
}

void enqueue_Comment(address *p, address Pnew){
    Ins_Akhir(p, Pnew);
}

// void Ins_AkhirTerlama(address *p, address Pnew){
//     Ins_Akhir(p, Pnew);
// }

void dequeue_Comment(address *p, infotype *x){
    Del_Awal(p, x);
}

// void Del_AkhirTerlama(address *p, infotype *x){
//     Del_Akhir(p, x);
// }  

void printCommentTerlama(address p){
    printf("Comment Terlama: \n");
    printComment(p);
}

