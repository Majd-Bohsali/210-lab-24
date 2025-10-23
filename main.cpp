// COMSC210 | lab 23 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();


    list<Goat> trip; 
    int selection; 

    do { 
        selection = main_menu();
        if(selection == 1) { 
            add_goat(trip, names, colors);
        } else if (selection == 2) { 
            delete_goat(trip); 
        } else if (selection == 3) { 
            display_trip(trip);
        }
    } while (selection != 4); 

   
    return 0;
}

int main_menu() { 
    int selection; 
    do { 
        cout << "*** GOAT MANAGER 3001" << endl;
        cout << "[1] Add a goat" << endl; 
        cout << "[2] Delete a goat" << endl; 
        cout << "[3] List goats" << endl; 
        cout << "[4] Quit" << endl;
        cout << "Choice --> "; 
        cin >> selection;
    } while (selection < 1 || selection > 4);
    return selection; 
}
