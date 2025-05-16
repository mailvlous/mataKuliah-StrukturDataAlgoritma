#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_STRING_LENGTH 100


typedef struct Node* address;
typedef struct Node {
    char info[MAX_STRING_LENGTH];
    address left;
    address right;
    address pr;
}Node;


address createNode(const char* info);

void addLeft(address parent, address left_node);

void addRight(address node, address right_node);

void addChild(address parent, address child);

void preorder(address node);

void postorder(address node);

void inorderTraversal(address node);

// void level_order(address root);

void traverse(address node, char *prefix, int isLast);

void PrintTree(address root);


address findNode(address root, const char* target);
/// code

// const char* codeTable[26] = {
//     ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  // A-I
//     ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
//     "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
// };

#endif // !BINARYTREE_H