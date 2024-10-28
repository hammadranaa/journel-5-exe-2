#pragma once
#include "Node.h"

class list {
private:
    node* head;  // Pointer to the head (dummy node) of the list
    node* tail;  // Pointer to the tail of the list for convenience with insert at the end

public:
    /*
        @brief: Constructs an empty list with a dummy head node.
    */
    list();

    /*
        @brief: Destructor that frees the memory allocated for the list.
    */
    ~list();

    /*
        @brief: Checks if the list is empty.
        @return: Returns true if the list is empty, false otherwise.
    */
    bool emptyList();

    /*
        @brief: Inserts a node at the beginning of the list.
        @param val: The value to be inserted in the new node.
    */
    void insertFirst(int val);

    /*
        @brief: Inserts a node at the end of the list.
        @param val: The value to be inserted in the new node.
    */
    void insertend(int val);

    /*
        @brief: Inserts a node at a specified position in the list.
        @param val: The value to be inserted in the new node.
        @param position: The position at which the new node should be inserted (0 for front, 1 for second, etc.).
    */
    void insertAtPosition(int val, int position);

    /*
        @brief: Deletes the first node in the list.
    */
    void delete_begin();

    /*
        @brief: Traverses the list and prints the values of the nodes.
    */
    void traverse();

    /*
        @brief: Reverses the doubly linked list.
    */
    void reverse();

    /*
        @brief: Displays the contents of alternate nodes in the list.
    */
    void displayAlternate();
};