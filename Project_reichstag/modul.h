#pragma once
#include <iostream>
#include <string>
#include <windows.h> 
#include <fstream>
#include <iomanip>
using namespace std;
struct jk {
    int number;
    char first_station[50];
    char last_station[50];
    double time_first;
    double time_last;
    double distance;
};
void create_file(string filename, jk& abonents);//створення
void add_file(string filename, jk& list);//додавання
void read_file(string filename, jk& list);//читання
void vvedenyaTimeVidp(string filename, jk& list);//3
void searchStation1(string path, jk& list);//1
void searchStation2(string path, jk& list);//2
void searchStation3(string path, jk& list);//5
bool compare(const jk& a, const jk& b);
void swap(jk& a, jk& b);
void sortinfile(string filename);//6
void trainsodnochasno(string filename);//4
void printTrainTable(int arr[], int size);