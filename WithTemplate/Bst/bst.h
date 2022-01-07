#ifndef _BST_H
#define _BST_H

#include <list>
#include <stack>
#include <iostream>

typedef int status_t;

const int SUCCESS = 1;
const int STACK_EMPTY = 2;

namespace ds {
    namespace bst {

        enum color
        {
            WHITE = 0,
            GREY,
            BLACK
        };

        template <typename T>
        class bst;

        template <typename T>
        class bst_stack;

        template <typename T>
        class bst_node_t;

        template <typename T>
        class bst_node
        {
            friend class bst<T>;
        private:
            T data;
            bst_node* left;
            bst_node* right;
            bst_node* parent;

            bst_node(T new_data) : data(new_data), left(nullptr), right(nullptr), parent(nullptr) {}
            bst_node(const bst_node<T>& other_node) {}
        };

        template <typename T>
        class bst
        {
            bst_node<T>* p_root_node;
            size_t nr_elements;

            static void preorder_r(bst_node<T>* p_root_node)
            {
                if (p_root_node == nullptr)
                    return;

                std::cout << "[" << p_root_node->data << "]<->";
                preorder_r(p_root_node->left);
                preorder_r(p_root_node->right);
            }

            static void inorder_r(bst_node<T>* p_root_node)
            {
                if (p_root_node == nullptr)
                    return;

                inorder_r(p_root_node->left);
                std::cout << "[" << p_root_node->data << "]<->";
                inorder_r(p_root_node->right);
            }

            static void postorder_r(bst_node<T>* p_root_node)
            {
                if (p_root_node == nullptr)
                    return;

                postorder_r(p_root_node->left);
                postorder_r(p_root_node->right);
                std::cout << "[" << p_root_node->data << "]<->";
            }

            void destroy_bst_r(bst_node<T>* p_root_node)
            {
                if (p_root_node != nullptr)
                {
                    destroy_bst_r(p_root_node->left);
                    destroy_bst_r(p_root_node->right);
                    delete(p_root_node);
                }
            }

        public:
            bst()
            {
                p_root_node = nullptr;
                nr_elements = 0;
            }

            ~bst()
            {
                destroy_bst_r(this->p_root_node);
                p_root_node = nullptr;
            }

            status_t insert(T new_data)
            {
                bst_node<T>* p_new_node = new bst_node<T>(new_data);
                if (p_root_node == nullptr)
                {
                    p_root_node = p_new_node;
                    nr_elements++;
                    return SUCCESS;
                }

                bst_node<T>* p_run = p_root_node;
                while (true)
                    if (new_data <= p_run->data)
                    {
                        if (p_run->left == nullptr)
                        {
                            p_run->left = p_new_node;
                            p_new_node->parent = p_run;
                            nr_elements++;
                            return SUCCESS;
                        }
                        else {
                            p_run = p_run->left;
                            continue;
                        }
                    }
                    else
                    {
                        if (p_run->right == nullptr)
                        {
                            p_run->right = p_new_node;
                            p_new_node->parent = p_run;
                            nr_elements++;
                            return SUCCESS;
                        }
                        else {
                            p_run = p_run->right;
                            continue;
                        }
                    }
            }

            void preorder_r()
            {
                std::cout << "Preorder recursive     :[START]<->";
                preorder_r(this->p_root_node);
                std::cout << "[END] " << std::endl << std::endl;
            }

            void inorder_r()
            {
                std::cout << "Inorder recursive      :[START]<->";
                inorder_r(this->p_root_node);
                std::cout << "[END] " << std::endl << std::endl;
            }

            void postorder_r()
            {
                std::cout << "Postorder recursive    :[START]<->";
                postorder_r(this->p_root_node);
                std::cout << "[END] " << std::endl << std::endl;
            }

            void preorder_nrc()
            {
                bst_node<T>* p_run = p_root_node;
                bst_stack<bst_node<T>*>* p_stack = new bst_stack<bst_node<T>*>();

                std::cout << "Preorder non-recursive :[START]<->";

                while (true)
                {
                    while (p_run != nullptr)
                    {
                        std::cout << "[" << p_run->data << "]<->";
                        p_stack->push(p_run);
                        p_run = p_run->left;
                    }

                    if (p_stack->pop(&p_run) == STACK_EMPTY)
                        break;

                    p_run = p_run->right;
                }

                std::cout << "[END]" << std::endl << std::endl;
                delete p_stack;
            }

            void inorder_nrc()
            {
                bst_node<T>* p_run = p_root_node;
                bst_stack<bst_node<T>*>* p_stack = new bst_stack<bst_node<T>*>();

                std::cout << "Inorder non-recursive  :[START]<->";

                while (true)
                {
                    while (p_run != nullptr)
                    {
                        p_stack->push(p_run);
                        p_run = p_run->left;
                    }

                    if (p_stack->pop(&p_run) == STACK_EMPTY)
                        break;

                    std::cout << "[" << p_run->data << "]<->";
                    p_run = p_run->right;
                }

                std::cout << "[END]" << std::endl << std::endl;
                delete p_stack;
            }

            void postorder_nrc()
            {
                bst_node<T>* p_run = p_root_node;

                std::stack<bst_node_t<T>*> p_stack;
                bst_node_t<T>* p_stack_run = nullptr;

                std::cout << "Postorder non-recursive:[START]<->";

                while (true)
                {
                    while (p_run != NULL)
                    {
                        bst_node_t<T>* stack_node = new  bst_node_t<T>();
                        stack_node->node = p_run;
                        stack_node->node_color = color::GREY;

                        p_stack.push(stack_node);
                        p_run = p_run->left;
                    }

                    if (p_stack.empty())
                        break;

                    bst_node_t<T>* top_node = p_stack.top();
                    color top_color = top_node->node_color;

                    if (top_color == GREY)
                    {
                        top_node->node_color = color::BLACK;
                        p_run = top_node->node;
                        p_run = p_run->right;
                        continue;
                    }
                    else if (top_color == BLACK)
                    {
                        p_stack.pop();
                        std::cout << "[" << top_node->node->data << "]<->";
                        delete top_node;
                        p_run = NULL;
                    }
                }
                std::cout << "[END]" << std::endl << std::endl;
            }
        };

        template <typename T>
        class bst_node_t
        {
            friend class bst<T>;
            bst_node<T>* node;
            color node_color;

        public:
            bst_node_t() { }

            status_t set_node_color(color new_color)
            {
                this->node_color = new_color;
            }

            color get_node_color()
            {
                return this->node_color;
            }

            ~bst_node_t()
            {
            }
        };

        template <typename T>
        class bst_stack
        {
            std::list<T>* p_stack;
        public:
            bst_stack()
            {
                p_stack = new std::list<T>;
            }

            status_t push(T p_bst_node)
            {
                p_stack->push_back(p_bst_node);
                return SUCCESS;
            }

            status_t top(T* pp_bst_node)
            {
                if (p_stack->empty())
                    return STACK_EMPTY;

                *pp_bst_node = p_stack->back();
                return SUCCESS;
            }

            status_t pop(T* pp_bst_node)
            {
                if (p_stack->empty())
                    return STACK_EMPTY;

                *pp_bst_node = p_stack->back();
                p_stack->pop_back();
                return SUCCESS;
            }

            bool is_empty()
            {
                return p_stack->empty();
            }

            ~bst_stack()
            {
                delete p_stack;
                p_stack = nullptr;
            }
        };

    }
}

#endif /* _BST_H */
