#include <iostream>
#include <string>
#include "stack.h"


int main()
{
    stack<std::string> stringStack(3);

    stringStack.push("First");
    stringStack.push("Second");
    
    std::string top;
    stringStack.get_top(&top);
    std::cout << "Stack top : " << top << std::endl;

    stringStack.push("Third");
    stringStack.pop(&top);
    std::cout << "Stack top : " << top << std::endl;

    return 0;
}