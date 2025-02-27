#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node node_t;

void print_list(node_t *head) {
    node_t *temp = head;


    while (temp != NULL) {
        printf("%d - ", (*temp).value);
        temp = (*temp).next;
    }
}

node_t *create_node(int value) {
    node_t *new_node = malloc(sizeof(node_t));
    (*new_node).value = value;
    (*new_node).next = NULL;
    return new_node;
}

node_t *insert_node_at_head(node_t **head, node_t *node_to_insert) {
    (*node_to_insert).next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *node_to_insert) {
    (*node_to_insert).next = (*node_to_insert_after).next;
    (*node_to_insert_after).next = node_to_insert;
}

node_t *find_node(node_t *head, node_t *node_to_find) {
    node_t *temp = head;
    while (temp != NULL) {
        if ((*temp).value == (*node_to_find).value) {
            return temp;
            temp = (*temp).next;
        }
    }
    return NULL;
}

node_t *delete_node(node_t *head, node_t *node_to_delete) {
    node_t *temp = head;
    node_t *prev = NULL;
    while (temp != NULL) {
        if ((*temp).value == (*node_to_delete).value) {
            if (prev == NULL) {
                head = (*temp).next;
            } else {
                (*prev).next = (*temp).next;
            }
            return temp;
        }
        prev = temp;
        temp = (*temp).next;
    }
    return NULL;
}



// int main() {
//     node_t *head = NULL;
//     node_t *temp;

//     for (int i = 0; i <= 10; i++) {
//         temp = create_node(i);
//         if (head == NULL) {
//             head = temp;
//         } else {
//             (*temp).next = head;
//             head = temp;
//         }
//     }

//     print_list(head);

//     // temp = create_node(10);
//     // head = temp;
//     // temp = create_node(8);
//     // (*head).next = temp;
//     // temp = create_node(15);
//     // (*temp).next = head;
//     // head = temp;

//     // print_list(head);

//     return 0;

// }



// staticly allocated nodes

int main() {
    node_t n1, n2, n3, n4;
    node_t *head;

    n1.value = 10;
    n2.value = 8;
    n3.value = 15;
    n4.value = 25;

    /* link the nodes
     n1 -> n2 -> n3 
      1(10) -> 2(8) -> 3(15) -> 4(25)
     */ 
    
    n4.next = NULL;
    n3.next = &n4;
    n2.next = &n3;
    n1.next = &n2;
    head = &n1;

    print_list(head);

    printf("\n");

    // try to insert a new node

    node_t new_node;
    new_node.value = 20;

    head = &n1;
    n1.next = &new_node;
    new_node.next = &n2;
    

    print_list(head);

    // head = (*head).next;

    // print_list(head);

    return 0;
}

// int main() {
//     node_t *head = NULL;

//     // Creating nodes using create_node function
//     node_t *n1 = create_node(10);
//     node_t *n2 = create_node(8);
//     node_t *n3 = create_node(15);
//     node_t *n4 = create_node(25);

//     /* link the nodes
//      n1 -> n2 -> n3 -> n4
//       1(10) -> 2(8) -> 3(15) -> 4(25)
//      */ 
//     head = n1;
//     insert_node_at_head(&head, n2);
//     insert_node_at_head(&head, n3);
//     insert_node_at_head(&head, n4);

//     print_list(head);
//     printf("\n");

//     // Try to insert a new node after n2 (in the middle)
//     node_t *new_node = create_node(20);
//     insert_after_node(n2, new_node);

//     print_list(head);
//     printf("\n");

//     return 0;
// }

// int main() {
//     node_t *head = NULL;

//     // Creating nodes using create_node function
//     node_t *n1 = create_node(10);
//     node_t *n2 = create_node(8);
//     node_t *n3 = create_node(15);
//     node_t *n4 = create_node(25);

//     /* link the nodes
//      n1 -> n2 -> n3 -> n4
//       1(10) -> 2(8) -> 3(15) -> 4(25)
//      */ 
//     head = n1;
//     insert_node_at_head(&head, n2);
//     insert_node_at_head(&head, n3);
//     insert_node_at_head(&head, n4);

//     print_list(head);
//     printf("\n");

//     // Try to insert a new node after n2 (in the middle)
//     node_t *new_node = create_node(20);
//     insert_after_node(n2, new_node);

//     print_list(head);
//     printf("\n");

//     // Try to find a node
//     node_t *found_node = find_node(head, n3);
//     if (found_node) {
//         printf("Found node with value: %d\n", found_node->value);
//     } else {
//         printf("Node not found.\n");
//     }

//     // Try to delete a node
//     node_t *deleted_node = delete_node(head, n2);
//     if (deleted_node) {
//         printf("Deleted node with value: %d\n", deleted_node->value);
//         free(deleted_node);
//     } else {
//         printf("Node not found for deletion.\n");
//     }

//     print_list(head);
//     printf("\n");

//     return 0;
// }

