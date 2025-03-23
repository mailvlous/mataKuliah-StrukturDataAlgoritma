#include <stdio.h>
#include <stdlib.h>
#include "comment_terlama_queue.h"
#include "comment_terlama_queue.c"
#include "comment_terbaru_stack.h"
#include "comment_terbaru_stack.c"
#include "comment.h"
#include "comment.c"

int main() {
    address C = NULL;
    address CTerlama = NULL;
    address CTerbaru = NULL;

    Ins_Awal(&C, createComment("apa ya"));
    Ins_Awal(&C, createComment("benar sekali"));
    Ins_Awal(&C, createComment("aku punya ide"));
    Ins_Awal(&C, createComment("idenya adalah"));
    Ins_Awal(&C, createComment("tapi sebenarnya"));

    enqueue_Comment(&CTerlama, createCommentTerlama("apa ya"));
    enqueue_Comment(&CTerlama, createCommentTerlama("benar sekali"));
    enqueue_Comment(&CTerlama, createCommentTerlama("aku punya ide"));
    enqueue_Comment(&CTerlama, createCommentTerlama("idenya adalah"));
    enqueue_Comment(&CTerlama, createCommentTerlama("tapi sebenarnya"));
    
    push_Comment(&CTerbaru, createCommentTerbaru("apa ya"));
    push_Comment(&CTerbaru, createCommentTerbaru("benar sekali"));
    push_Comment(&CTerbaru, createCommentTerbaru("aku punya ide"));
    push_Comment(&CTerbaru, createCommentTerbaru("idenya adalah"));
    push_Comment(&CTerbaru, createCommentTerbaru("tapi sebenarnya"));

    printComment(C);

    printCommentTerlama(CTerlama);

    printCommentTerbaru(CTerbaru);
}