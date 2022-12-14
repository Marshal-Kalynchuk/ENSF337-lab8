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
    //    Returns 1 for successful deletion, 0 otherwise.

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
    int destroy(); 
    // PROMISES: destoys a list.
    //    Returns 1 after the list is destroyed
};
#endif