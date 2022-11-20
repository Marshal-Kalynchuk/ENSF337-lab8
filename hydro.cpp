// hydro.cpp
// ENSF 337 Fall 2022 Lab 8 Exercise C

#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "hydro.h"
#include "list.h"
using namespace std;

int main(void){
  FlowList flow_list;
  int num_records;
  char* file_path = "./flow.txt";
  num_records = readData(flow_list, file_path);
  cout << num_records << endl;
  displayHeader();
  pressEnter();
  while(1){
    switch(menu()){
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      default:
        cout << "Invalid input" << endl;
        pressEnter();
    }
  }
  return 0;
};

void displayHeader(void){
  cout << "Program: Flow Studies - Fall 2020" << endl;
  cout << "Version: 1.0" << endl;
  cout << "Lab section: B05" << endl;
  cout << "Produced by: Marshal Kalynchuk" << endl;
};

int readData(FlowList list, const char *file_path){
  ifstream file(file_path);
  if (!file){
    cout << "Error: failed to open file: " << file_path << endl;
    exit(1);
  };

  int year;
  double flow;
  while( !file.eof()){
    file >> year;
    file >> flow;
    cout << year << " " << flow << endl;
    // Insert node...
  }


  file.close();
};

int menu(void){
  int choice;
  cout << "1. Display flow list, and the average" << endl;
  cout << "2. Add data." << endl;
  cout << "3. Save data into the file" << endl;
  cout << "4. Remove data" << endl;
  cout << "5. Quit" << endl;
  cout << "Enter your choice (1, 2, 3, 4, or 5):" << endl;
  cin >> choice;
  cin.clear();
  cin.ignore(10000, '\n');
  return choice;
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