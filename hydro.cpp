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
  int num_records = 0;
  char* file_path = "./flow.txt";
  num_records = readData(&flow_list, file_path);
  int quit = 0;
  displayHeader();
  pressEnter();

  while(!quit){
    switch(menu()){
      case 1:
        display(&flow_list);
        pressEnter();
        break;
      case 2:
        num_records = addData(&flow_list);
        pressEnter();
        break;
      case 3:
        break;
        saveData(&flow_list, file_path);
        pressEnter();
        break;
      case 4:
        num_records = removeData(&flow_list);
        pressEnter();
        break;
      case 5:
        cout << "Program terminated" << endl;
        quit = 1;
        break;
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

int readData(FlowList* flow_list, const char *file_path){
  // Open file
  ifstream file(file_path);
  if (!file){
    cout << "Error: failed to open file: " << file_path << endl;
    exit(1);
  };

  int year;
  double flow;
  int num_records = 0;
  // Read data and insert into flow list
  while(!file.eof()){
    file >> year;
    file >> flow;
    if(!(*flow_list).insert(year, flow)){
      cout << "Error: duplicate data. Program terminated" << endl;
      exit(1);
    }
  }
  // Clearn up and return num records
  file.close();
  return (*flow_list).get_num_records();
};

int menu(void){
  int choice;
  cout << "1. Display flow list, and the average" << endl;
  cout << "2. Add data." << endl;
  cout << "3. Save data into the file" << endl;
  cout << "4. Remove data" << endl;
  cout << "5. Quit" << endl;
  cout << "Enter your choice (1, 2, 3, 4, or 5): ";
  cin >> choice;
  cin.clear();
  cin.ignore(10000, '\n');
  return choice;
};

void display(FlowList *list){
  (*list).print();
  cout << "Average: " << average(list) << endl;;
};

int addData(FlowList *list){
  int year;
  double flow;

  // User input
  cout << "\nPlease enter a year: ";
  cin >> year;
  cout << "Please enter the flow: ";
  cin >> flow;

  // Inserting data into the flow list
  if (cin.fail())
    cout << "Invalid data" << endl;
  else
    cout << ((*list).insert(year, flow) ? "New record inserted successfully" : "Error: duplicate data.") << endl;

  // Clean up and return num records
  cin.clear();
  cin.ignore(10000, '\n');
  return (*list).get_num_records();
};

int removeData(FlowList* flow_list){
  int year;
  cout << "\nPlease enter the year you would like to remove: ";
  cin >> year;
  cout  << ((*flow_list).remove(year) ? "Record was successfully removed." : "Error: no such data.") << endl;
  cin.clear();
  cin.ignore(10000, '\n');
  return (*flow_list).get_num_records();
};

double average(FlowList *list){
  ListItem item = (*list).generate();
  int count = 0;
  double sum = 0;
  while(item.year != -99 && item.flow != -99){
    count++;
    sum += item.flow;
    item = (*list).generate();
  }
  return sum / count;
};

void saveData(FlowList *list, const char *file_path){

};

void pressEnter(void){
  cout << "<<<< Press Enter to continue >>>>" << endl;
  cin.get();
};