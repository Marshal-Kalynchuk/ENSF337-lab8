// list.cpp
// ENSF337 Fall 2022 Lab 8 Exercise C

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList(): headM(0), posM(0) {};

FlowList::~FlowList()
{
  destroy();
};

void FlowList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << " [" << headM->item.year << ", " << headM->item.flow << ']';
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", [" << p->item.year << ", " << p->item.flow << ']';
    }
    cout << " ]\n";
};

int FlowList::insert(const int year, const double flow)
{
    Node *new_node = new Node;
    new_node->item.year = year;
    new_node->item.flow = flow;
    
    if (headM == 0 || year <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
    return ++num_records;
}

int FlowList::remove(const int year)
{
    // if list is empty, do nothing
    if (headM == 0 || year < headM->item.year)
        return num_records;
    
    Node *doomed_node = 0;
    
    if (year == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && year > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        // set doomed_node and splice list
        if (year == maybe_doomed->item.year){
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
        // Doesn't exist
        else
            return num_records;
    }
    // Remove node
    delete doomed_node;
    return ++num_records;
};

ListItem FlowList::generate() {
    posM = posM == nullptr ? headM : posM->next;
    return posM == nullptr ? ListItem {-99,-99} : posM->item;
};

int FlowList::get_num_records(){
    return num_records;
};

int FlowList::destroy()
{
    Node* p = headM;
    while(p != nullptr){
        p = p->next;
        delete headM;
        headM = p;
    };
    return (num_records = 0);
};