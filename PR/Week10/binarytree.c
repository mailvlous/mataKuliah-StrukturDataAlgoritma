#include "binarytree.h"
#include "queue.h"


address createNode(const char* info) {
    address newNode = (address) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(newNode->info, info);
    newNode->left = newNode->right = newNode->pr = NULL;
    return newNode;
}

void addLeft(address parent, address left_node){
    parent->left = left_node;
    left_node->pr = parent;
}

void addRight(address node, address right_node){
    node->right = right_node;
    right_node->pr = node->pr;
}

void addChild(address parent, address child) {
    if (parent->left == NULL) {
        addLeft(parent, child);
    } else {
        address temp = parent->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        addRight(temp, child);
    }
}

void preorder(address node) {
    if (node == NULL) return;

    printf("%s ", node->info); // visit
    address child = node->left;
    while (child != NULL) {
        preorder(child);
        child = child->right;
    }
}

void postorder(address node) {
    if (node == NULL) return;

    address child = node->left;
    while (child != NULL) {
        postorder(child);
        child = child->right;
    }

    printf("%s ", node->info); // visit after children
}

void inorderTraversal(address node) {
    if (node == NULL) return;

    if (node->left != NULL)
        inorderTraversal(node->left);  // traverse first child

    printf("%s", node->info);      // process current node

    if (node->left != NULL) {
        address sibling = node->left->right;
        while (sibling != NULL) {
            inorderTraversal(sibling);  // traverse siblings
            sibling = sibling->right;
        }
    }
}


// void level_order(address root) {
//     if (root == NULL) return;

//     front = rear = 0;
//     enqueue(root);

//     while (!isEmpty()) {
//         address current = dequeue();
//         printf("%s\n", current->info);

//         address child = current->left;
//         while (child != NULL) {
//             enqueue(child);
//             child = child->right;
//         }
//     }
// }


void traverse(address node, char *prefix, int isLast) {
    if (node == NULL) return;

    printf("%s", prefix);
    if (isLast) {
        printf("|-- ");
    } else {
        printf("+-- ");
    }

    printf("%s\n", node->info);  

    char newPrefix[1000];  // cukup panjang
    if (isLast) {
        sprintf(newPrefix, "%s    ", prefix);
    } else {
        sprintf(newPrefix, "%s|   ", prefix);
    }

    address child = node->left;
    while (child != NULL) {
        address nextSibling = child->right;
        int childIsLast = (nextSibling == NULL);
        traverse(child, newPrefix, childIsLast);
        child = nextSibling;
    }
}

void PrintTree(address root) {
    traverse(root, "", 1);  // root adalah pointer langsung
}


address findNode(address root, const char* target) {
    if (root == NULL) return NULL;
    if (strcmp(root->info, target) == 0) return root;

    address found = findNode(root->left, target);
    if (found != NULL) return found;

    return findNode(root->right, target);
}