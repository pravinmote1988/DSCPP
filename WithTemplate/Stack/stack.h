#ifndef _STACK_H
#define _STACK_H

#include <stdexcept>
#include <cstdio>

using std::runtime_error;

class stack_full : public runtime_error
{
    public:
    stack_full (const char * msg) : std::runtime_error(msg) {}
};

class stack_empty : public runtime_error
{
    public:
    stack_empty( const char *msg) : std::runtime_error(msg) {}
};

template <typename T>
class stack
{
    private:
    T* p_err;
    size_t size;
    int top;

    public:
    stack(size_t size) : p_err(new T[size]), size(size), top(-1) {}

    void push(T new_data)
    {
        if(top + 1 == size)
            throw stack_full("stack is full");
        top +=1;
        p_err[top] = new_data;
    }

    void pop(T *new_data)
    {
        if(top == -1)
            throw stack_empty("stack is empty");

        *new_data = p_err[top];
        top -= 1;
    }

    void get_top(T *new_data)
    {
        if(top == -1)
            throw stack_empty("stack is empty");

        *new_data = p_err[top];
    }

    bool is_empty() const
    {
        return top == -1;
    }

    ~stack()
    {
        delete[] p_err;
    }
};

#endif /* _STACK_H */