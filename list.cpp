// list.cpp
// ENSF337 Fall 2022 Lab 8 Exercise C

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"

FlowList::FlowList(): headM(0) {};

FlowList::~FlowList()
{
  destroy();
};

void FlowList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA.year < headM->item.year)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA.year > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        // point three
        // set doomed_node and splice list
        if (itemA == maybe_doomed->item){
            doomed_node = maybe_doomed;
            before->next = maybe_doomed->next;
        }
        // Doesn't exist
        else
            return;
    }
    // Remove node
    delete doomed_node;
};


void FlowList::destroy()
{
    Node* p = headM;
    while(p != nullptr){
        p = p->next;
        delete headM;
        headM = p;
    };
};