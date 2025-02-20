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
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 10;
    n2.value = 8;
    n3.value = 15;

    // link
    head = &n1;
    n3.next = NULL;
    n2.next = &n3;
    n1.next = &n2;

    // print_list(head);

    // try to insert a new node
    node_t n4;
    n4.value = 20;
    n4.next = &n3;
    n2.next = &n4;

    print_list(head);

    // head = (*head).next;

    // print_list(head);

    return 0;
}