// list.h
// ENSF 337 Fall 2022 Lab 8 Exercise C

#ifndef LIST_H
#define LIST_H

struct ListItem {
  int year;
  double flow;
};
struct Node {
  ListItem item;
  Node* next;
};

class FlowList{
  public:
    FlowList(); // PROMISES: Creates empty list.
    //FlowList(const FlowList& source);
    //FlowList& operator=(const FlowList& rhs); // PROMISES: Copies a list.
    ~FlowList(); // PROMISES: Deletes a list.

    void insert(const int year, const double flow);
    // PROMISES:
    //    A node with a copy of itemA is added in 
    //    a way that preserves the nondecreasing 
    //    order of items in nodes.

    void remove(const int year);
    //  PROMISES:
    //    If no node has an item matching itemA, 
    //    list is unchanged.
    //    Otherwise exactly one node with 
    //    its item == itemA is removed.

    void print() const;
    // PROMISES:
    //   Prints items in list on a single line, with commas separating
    //   the items and square brackets marking the ends of the list.
    // NOTE:
    //   This is different from the print function presented in lectures.


  private:
    Node* headM;
    // From OLList
    void destroy(); // PROMISES: destoyes a list.
    void copy(const FlowList& source); // PROMISES: list becomes copy of source.
};
#endif