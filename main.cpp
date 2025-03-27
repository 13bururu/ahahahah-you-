#include "database.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    database bd;
    int r;
    do {
        cout << "\n1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. search" << endl;
        cout << "4. delete" << endl;
        cout << "5. edit" << endl;
        cout << "0. exit" << endl;
        cin >> r;
        if (cin.fail()) {
            cout << "Error" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
            if (r < 0 || r > 5) {
                cout << "Error" << endl;
            }

        switch (r) {
        case 1: {
            bd.printb();
            break;
        }
        case 2: {
            string name;
            double price;
            cout << "enter name & price: ";
            cin >> name;
            if (cin.fail()) {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cin >> price;
            if (cin.fail()) {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }

            t n(name, price);
            bd.add(n);
            break;
        }
        case 3: {
            string name1;
            double price1;
            cout << "enter name & price:";
            cin >> name1 >> price1;
            bd.search(name1, price1);
            break;

        }
        case 4: {
            cout << "che udalit'? number: ";
            int pl;
            cin >> pl;
            if (cin.fail()) {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            bd.deletee(pl - 1);
            break;
        }
        case 5: {
            cout << "kakoi momer redaktirovat'????:";
            int y;
            cin >> y;
            if (cin.fail()) {
                cout << "Error" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            bd.editt(y - 1);
            break;
        }
        }
    } while (r != 0);
    return 0;
}