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

    int insert(const int year, const double flow);
    // PROMISES:
    //    A node with a copy of itemA is added in 
    //    a way that preserves the nondecreasing 
    //    order of items in nodes.
    //    Return 1 if successfully added, 0 otherwise.

    int remove(const int year);
    //  PROMISES:
    //    If no node has an item matching itemA, 
    //    list is unchanged.
    //    Otherwise exactly one node with 
    //    its item == itemA is removed.
    //    Returns number of records

    void print() const;
    // PROMISES:
    //   Prints items in list on a single line, with commas separating
    //   the items and square brackets marking the ends of the list.
    // NOTE:
    //   This is different from the print function presented in lectures.

    ListItem generate();
    // PROMISES:
    //    Cycles through the list, returning the list items of the list
    //    Return ListItem{-99,-99} at the end of the list or if the list is empty.
    int get_num_records();
    // PROMISES:
    //    Return the number of records in the list.

  private:
    Node* headM;
    Node* posM;
    int num_records = 0;
    // From OLList
    int destroy(); // PROMISES: destoyes a list.
    int copy(const FlowList& source); // PROMISES: list becomes copy of source.
};
#endif