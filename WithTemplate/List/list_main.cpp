#include <iostream>
#include "list_exceptions.h"
#include "list.h"

int main()
{
    ds::list::list<int> *p_list = new ds::list::list<int> ();
    p_list->insert_start(30);
    p_list->insert_start(20);
    p_list->insert_start(10);

    p_list->show();
}