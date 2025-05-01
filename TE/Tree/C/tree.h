#include <stdio.h>
#include <malloc.h>

#define Data(T) (T)->data
#define Children(T) (T)->children

#define Child(T) (T)->child
#define Next(T) (T)->next

typedef struct TreeNode *Tree;
typedef struct ChildNode *Child;

typedef struct ChildNode {
    struct TreeNode *child;
    struct ChildNode *next;
} ChildNode;

typedef struct TreeNode {
    int data;
    Child children;
} TreeNode;

Tree createNode(int data) {
    Tree newNode = (Tree)malloc(sizeof(TreeNode));
    Data(newNode) = data;
    Children(newNode) = NULL;

    return newNode;
}

void addChild(Tree parent, Tree child){
    if (parent == NULL) return;

    Child newChild = (Child)malloc(sizeof(ChildNode));
    Child(newChild) = child;
    Next(newChild) = NULL;

    if (Children(parent) == NULL) {
        Children(parent) = newChild;
    } else {
        Child temp = Children(parent);
        while (Next(temp) != NULL) {
            temp = Next(temp);
        }
        Next(temp) = newChild;
    }
}

void printTree(Tree root, int depth) {
    if (root == NULL) return;

    // Cetak spasi sesuai depth
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%d\n", Data(root));

    // Traverse semua children
    Child temp = Children(root);
    while (temp != NULL) {
        printTree(Child(temp), depth + 1);
        temp = Next(temp);
    }
}

void freeTree(Tree root) {
    if (root == NULL) return;

    Child temp = Children(root);
    while (temp != NULL) {
        Child next = Next(temp);
        freeTree(Child(temp)); // Bebaskan child subtree
        free(temp);            // Bebaskan ChildNode
        temp = next;
    }

    free(root); // Bebaskan TreeNode
}





