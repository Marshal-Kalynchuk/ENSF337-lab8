// hydro.cpp
// ENSF 337 Fall 2022 Lab 8 Exercise C

#include "iostream"
#include "stdlib.h"
#include "hydro.h"
#include "list.h"
using namespace std;

int main(void){
  displayHeader();
  pressEnter();
  int choice = menu();
  return 0;
};

void displayHeader(void){
  cout << "Program: Flow Studies - Fall 2020" << endl;
  cout << "Version: 1.0" << endl;
  cout << "Lab section: B05" << endl;
  cout << "Produced by: Marshal Kalynchuk" << endl;
};

int readData(FlowList *list, const char *file_path){

};

int menu(void){
  int choice;
  while(true) {
    cout << "1. Display flow list, and the average" << endl;
    cout << "2. Add data." << endl;
    cout << "3. Save data into the file" << endl;
    cout << "4. Remove data" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice (1, 2, 3, 4, or 5):" << endl;
    cin >> choice;
    if (!cin.fail() && choice > 0 && choice <= 5)
      return choice;
    else {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "\nInvalid input\n" << endl;
    };
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