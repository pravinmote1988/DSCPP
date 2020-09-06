#include <iostream>
#include "list.h"

typedef ds::list::node node;
typedef ds::list::dclist dclist;
typedef ds::list::ret_t ret_t;

ret_t dclist::insert_beg(data_t data){    
    generic_insert(head_node, new node(data), head_node->prev);
}
ret_t dclist::insert_end(data_t data){
    generic_insert(head_node->prev, new node(data), head_node);
}

ret_t dclist::generic_insert(node *p_beg, node *p_mid, node *p_end){
    p_beg->next = p_mid;
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_end->prev = p_mid;
}

ret_t dclist::generic_delete(node *p_delete_node) {
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
}

void dclist::show_list() {
    std::cout << "List is -> ";
    node *p_run = head_node->next;
    for(; p_run != head_node; p_run = p_run->next)
        std::cout << " "<< p_run->data << " |";
    std::cout << std::endl;
}