#include "Node.h"

node::node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}

node::node(int data)
{
    this->data = data;
    next = NULL;
    prev = NULL;
}