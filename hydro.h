// hydro.h
// ENSF 337 Fall 2022 Lab 8 Exercise C

#ifndef HYDRO_H
#define HYDRO_H

#include "list.h"

void displayHeader();
// PROMISES
//    Displays the introcution to the screen.

int readData(FlowList* list, const char *file_path);
// PROMISES
//    Reads flow records from a input file,
//    inserts them into the list of records, and
//    returns the number of records in the file.

int menu(void);
// PROMISES
//    Displays a menu and return the users choice.
//    (Integer from 1 to 5)

void display(FlowList* list);
//  PROMISES
//    Displays the years and flows, and shows the
//    average flows in the list.

int addData(FlowList *list);
//  PROMISES
//    Prompts the user to enter new data, inserts
//    the new data into the list, and updates the
//    number of records.
//    Returns the number of records

int removeData(FlowList* flow_list);
// PROMISES
//    Prompts the user to indicate what year to be
//    removed, removes a single record from the list,
//    and updates the number of records.

double average(FlowList *list);
// PROMISES
//   Returns the flow average in the given list.

void saveData(FlowList *list, const char *file_path);
//  PROMISES
//    Writes the contents of the linked list to a txt file.

void pressEnter(void);
//  PROMISES:
//    Waits for user to press enter.

#endif