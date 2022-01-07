 #ifndef _LIST_H
 #define _LIST_H

#include <iostream>
#include "list_exceptions.h"

namespace ds {

namespace list {

const int SUCCESS = 1;

typedef int ret_t;
typedef int len_t;

template <typename T>
class node;

template <typename T>
class list {

private:
    node<T>* p_head_node;
    
    static void generic_insert( node<T>* p_beg, node<T>* p_mid, node<T>* p_end)
    {
        p_mid->next = p_end;
        p_mid->prev = p_beg;
        p_beg->next = p_mid;
        p_end->prev = p_mid;
    }

    static void generic_delete( node<T>* p_delete_node)
    {
        p_delete_node->prev->next = p_delete_node->next;
        p_delete_node->next->prev = p_delete_node->prev;
        delete p_delete_node;
    }

    node<T>* search_node(T s_data)
    {
        for( node<T>* p_run= p_head_node->next; p_run != p_head_node; p_run= p_run->next)
        {
            if(p_run->data == s_data)
                return p_run;
        }
        return nullptr;
    }

public:
    list()
    {
        p_head_node = new node<T>;
        p_head_node->prev = p_head_node;
        p_head_node->next = p_head_node;
    }

    ~list()
    {
        node<T>* p_run = p_head_node->next;
        node<T>* p_run_next;
        for(p_run; p_run != p_head_node; p_run = p_run->next)
        {
            p_run_next = p_run->next;
            delete p_run;
        }
        delete p_head_node;
        p_head_node= nullptr;
    }

    ret_t insert_start(T new_data)
    {
        generic_insert(p_head_node, new node<T>(new_data), p_head_node->next);
        return SUCCESS;
    }

    void show(void)
    {
        std::cout << "[START]<->";
        for(node<T>* p_run = p_head_node->next; p_run != p_head_node; p_run = p_run->next)
            std::cout<< "[" << p_run->data << "] <->";
        std::cout << "[END]" << std::endl;   
    }
};

template <typename T>
class node
{
private:
    friend class list<T>;

    T data;
    node<T>* prev;
    node<T>* next;

    node( T new_data) : data(new_data), prev(nullptr), next(nullptr) {}
    node(void) : prev(nullptr), next(nullptr){}

};

}

}
 #endif /* _LIST_H */