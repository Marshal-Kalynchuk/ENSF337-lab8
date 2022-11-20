// hydro.cpp
// ENSF 337 Fall 2022 Lab 8 Exercise C

#include "iostream"
#include "stdlib.h"
#include "hydro.h"
#include "list.h"
using namespace std;

void main(void){

};

void displayHeader(void){
  cout << "Program: Flow Studies - Fall 2020" << endl;
  cout << "Version: 1.0" << endl;
  cout << "Lab section: B05" << endl;
  cout << "Produced by: Marshal Kalynchuk" << endl;
  cout << "<<<< Press Enter to continue >>>>" << endl;
};

int readData(FlowList *list, const char *file_path){

};

int menu(void){
  int choice = 0;
  while(true) {
    cout << "1. Display flow list, and the average" << endl;
    cout << "2. Add data." << endl;
    cout << "3. Save data into the file" << endl;
    cout << "4. Remove data" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    if (choice > 0 && choice <= 5)
      return choice;
    else
      cout << "Invalid input" << endl;
  };
};

void display(void){

};

int addData(FlowList *list){

};

void removeData(void){

};

double average(FlowList *list){

};

void saveData(FlowList *list, const char *file_path){

};

void pressEnter(void){
  cout << "<<<< Press Enter to continue >>>>" << endl;
  cin.get();
};