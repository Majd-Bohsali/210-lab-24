// COMSC210 | lab 24 | Majd Bohsali
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

void add_goat(list<Goat> &trip, string names[], string colors[]) { 
    string name = names[rand() % SZ_NAMES];
    int age = rand() % MAX_AGE + 1;
    string color = colors[rand() % SZ_COLORS];

    Goat goat(name, age, color);
    trip.push_back(goat); 
    cout << "\tGoat added" << endl;
}

void delete_goat(list<Goat> &trip) { 

    if(trip.empty()) { 
        cout << "\tGoat list is currently empty" << endl;
        return; 
    }

    cout << endl; 
    int selection;
    cout << "Select a goat to delete" << endl; 
    display_trip(trip);
    cout << "\tChoice --> ";
    cin >> selection;
    while (selection < 1 || selection > trip.size()) { 
        cout << "Invalid choice, please select a valid goat to delete" << endl;
        cout << "Choice --> ";
        cin >> selection; 
    }

    // iterates to correct goat and deletes 
    auto it = trip.begin(); 
    advance(it, selection-1);
    trip.erase(it);
    cout << endl; 
}

void display_trip(list<Goat> trip) { 
    int counter = 1;

    if(trip.empty()) { 
        cout << "\tGoat list is currently empty" << endl;
        return; 
    }

    cout << "\tCurrent Goats:" << endl;
    for(auto it = trip.begin(); it != trip.end(); it++) { 
        cout << "\t[" << counter << "] " << (*it).get_name() << " (" << (*it).get_age() << ", " << (*it).get_color() << ") " << endl; 
        counter++; 
    }
}
 
int main_menu() { 
    cout << endl;
    int selection; 
    do { 
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl; 
        cout << "[2] Delete a goat" << endl; 
        cout << "[3] List goats" << endl; 
        cout << "[4] Quit" << endl;
        cout << "Choice --> "; 
        cin >> selection;
    } while (selection < 1 || selection > 4);
    cout << endl; 
    return selection; 
}
