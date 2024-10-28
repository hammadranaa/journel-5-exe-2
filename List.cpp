#include "List.h"
#include <iostream>
using namespace std;

list::list()
{
    head = nullptr;
    tail = nullptr;
}

list::~list()
{
    node* temp = head;
    while (temp != nullptr)
    {
        node* next = temp->next;
        delete temp;
        temp = next;
    }
}

bool list::emptyList()
{
    return (head == nullptr);  // Return true if the list is empty
}

void list::insertFirst(int val)
{
    node* pNewNode = new node;
    pNewNode->data = val;
    pNewNode->next = nullptr;
    pNewNode->prev = nullptr;

    if (emptyList())
    {
        // If the list is empty, both head and tail point to the new node
        head = tail = pNewNode;
    }
    else
    {
        // Insert at the front
        head->prev = pNewNode;
        pNewNode->next = head;
        head = pNewNode;
    }
}

void list::insertend(int val)
{
    node* pNewNode = new node;
    pNewNode->data = val;
    pNewNode->next = nullptr;
    pNewNode->prev = nullptr;

    if (emptyList())
    {
        // If the list is empty, both head and tail point to the new node
        head = tail = pNewNode;
    }
    else
    {
        // Insert at the end
        tail->next = pNewNode;
        pNewNode->prev = tail;
        tail = pNewNode;
    }
}

void list::insertAtPosition(int val, int position)
{
    if (position < 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    node* pNewNode = new node;
    pNewNode->data = val;
    pNewNode->next = nullptr;
    pNewNode->prev = nullptr;

    if (position == 0) {
        // Insert at the beginning
        insertFirst(val);
        return;
    }

    if (emptyList()) {
        // If the list is empty and position is not 0, cannot insert
        cout << "List is empty. Cannot insert at position " << position << endl;
        return;
    }

    node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete pNewNode;  // Clean up memory
            return;
        }
        temp = temp->next;
    }

    // If we're inserting at the end or in the middle
    if (temp == tail) {
        // Inserting at the end
        insertend(val);
    }
    else {
        // Insert in the middle
        pNewNode->next = temp->next;
        pNewNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = pNewNode;
        }

        temp->next = pNewNode;
    }
}

void list::delete_begin()
{
    if (emptyList())
    {
        cout << "List is empty, nothing to delete!" << endl;
    }
    else if (head == tail)
    {
        // If there is only one element, delete it and reset the list
        delete head;
        head = tail = nullptr;
    }
    else
    {
        // Delete the first node and update head
        node* toDelete = head;
        head = head->next;
        head->prev = nullptr;
        delete toDelete;
    }
}

void list::traverse()
{
    if (emptyList())
    {
        cout << "List is empty." << endl;
    }
    else
    {
        node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void list::reverse()
{
    if (emptyList())
    {
        cout << "List is empty. Nothing to reverse." << endl;
        return;
    }

    node* current = head;
    node* temp = nullptr;

    // Swap next and prev for all nodes
    while (current != nullptr)
    {
        temp = current->prev; // Temporarily store the previous node
        current->prev = current->next; // Reverse the next pointer
        current->next = temp; // Reverse the prev pointer
        current = current->prev; // Move to the next node (which is prev now)
    }

    // Adjust head and tail
    if (temp != nullptr)
    {
        tail = head;
        head = temp->prev;
    }
}

void list::displayAlternate()
{
    if (emptyList())
    {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = head;
    int count = 0;

    while (temp != nullptr)
    {
        if (count % 2 == 0) // Check for alternate nodes
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
        count++;
    }
    cout << endl;
}

int main()
{
    list l;

    l.insertFirst(1);
    l.insertend(2);
    l.insertend(3);
    l.insertend(4);
    l.insertend(5);

    cout << "Original List: ";
    l.traverse();  // Output: 1 2 3 4 5

    cout << "Alternate nodes: ";
    l.displayAlternate();  // Output: 1 3 5

    l.reverse();  // Reverse the list

    cout << "Reversed List: ";
    l.traverse();  // Output: 5 4 3 2 1

    return 0;
}