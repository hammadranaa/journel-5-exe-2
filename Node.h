#pragma once
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* prev;

    node();
    node(int data);
};