#include "comment.h"
#include "comment_terbaru_stack.h"

bool isCommentTerbaruEmpty(address p){
    isEmpty(p);
}

address createCommentTerbaru(char *comment){
    address Pnew = createComment(comment);
    return Pnew;
}

void push_Comment(address *p, address Pnew){
    Ins_Awal(p, Pnew);
}

// void Ins_AkhirTerbaru(address *p, address Pnew){
//     Ins_Akhir(p, Pnew);
// }

void pop_Comment(address *p, infotype *x){
    Del_Awal(p, x);
}

// void Del_AkhirTerbaru(address *p, infotype *x){
//     Del_Akhir(p, x);
// }  

void printCommentTerbaru(address p){
    printf("Comment Terbaru: \n");
    printComment(p);
}