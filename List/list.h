#ifndef _LIST_H
#define _LIST_H

namespace ds {

namespace list {
typedef int data_t;
typedef bool ret_t;

class node {
    friend class dclist;
    private:
    data_t data;
    node *next;
    node *prev;
    node(data_t data = 0, node *next_node = nullptr, node *prev_node = nullptr) : data(data), next(next_node), prev(prev_node) {}
};

class dclist {
    node *head_node;

     //auxillary functions
    static ret_t generic_insert(node *p_beg, node *p_mid, node *p_end);
    static ret_t generic_delete(node *p_delete_node);

    public:
    dclist() : head_node(new node){
        head_node->prev = head_node;
        head_node->next = head_node;
    }
    ret_t insert_beg(data_t data);
    ret_t insert_end(data_t data);
    void show_list();
};

}
}
#endif /* _LIST_H */