#include "bst.h"

int main()
{
    ds::bst::bst<double> *bstree = new ds::bst::bst<double>();

    bstree->insert(100.1);
    bstree->insert(50.1);
    bstree->insert(150.1);
    bstree->insert(25.1);
    bstree->insert(75.1);
    bstree->insert(125.1);
    bstree->insert(175.1);
    bstree->insert(65.1);
    bstree->insert(130.1);

    bstree->postorder_r();
    bstree->postorder_nrc();
    bstree->preorder_r();
    bstree->preorder_nrc();
    bstree->inorder_r();
    bstree->inorder_nrc();

    delete bstree;
}