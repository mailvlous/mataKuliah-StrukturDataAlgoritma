int main() {
//     node_t n1, n2, n3, n4;
//     node_t *head;

//     n1.value = 10;
//     n2.value = 8;
//     n3.value = 15;
//     n4.value = 25;

//     /* link the nodes
//      n1 -> n2 -> n3 
//       1(10) -> 2(8) -> 3(15) -> 4(25)
//      */ 
    
//     n4.next = NULL;
//     n3.next = &n4;
//     n2.next = &n3;
//     n1.next = &n2;
//     head = &n1;

//     print_list(head);

//     printf("\n");

//     // try to insert a new node

//     node_t new_node;
//     new_node.value = 20;

//     head = &n1;
//     n1.next = &new_node;
//     new_node.next = &n2;
    

//     print_list(head);

//     // head = (*head).next;

//     // print_list(head);

//     return 0;
// }