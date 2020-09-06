#include "list.h"

typedef ds::list::node node;
typedef ds::list::dclist dclist;
typedef ds::list::ret_t ret_t;

int main() {

    dclist *p_list = new dclist;
    p_list->insert_beg(10);
    p_list->insert_end(20);    
    p_list->show_list();
}