// OLList.cpp
// ENSF 337 Fall 2021 Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        // point three
    }
    // the remaining part of this function is missing. As part of exercise A
    // students are supposed to complete the rest of the definition of this function.
}

void OLList::destroy()
{
    
    // this function is not properly designed. As part of the exercise A
    // students are supposed to remove the folloiwng lines and
    // complete the definition of this helper function.
    cout << "OLList::destroy was called but isn't ready for use"
    << "--program is terminated.\n";
    headM = 0;
}

void OLList::copy(const OLList& source)
{
    // Setup iterable pointer
    Node* p = source.headM;
    // if empty, set empty
    if(p == 0){
        headM = 0;
        return;
    }

    // Init first node and copy first node
    Node* new_node = new Node;
    new_node->item = p->item;
    // Setup prev_node
    Node* prev_node = new_node;
    // Set headM
    headM = new_node;
    // First iteration of source list
    p = p->next;
    while (p != nullptr){
        // New node and copying
        new_node = new Node;
        new_node->item = p->item;
        // Linking prev node with new node
        prev_node->next = new_node;
        // Setting prev_node
        prev_node = new_node;
        // Iterating source list
        p = p->next;
    }
}


