#include "database.h"
#include <fstream>
using namespace std;

ostream& operator<<(ostream& out, const t& p) {
    out << p.name << " " << p.price;
    return out;
}

istream& operator>>(istream& in, t& p) {
    in >> p.name >> p.price;
    return in;
}

database::database() {
    fromtxt();
}

database::~database() {
    totxt();
    delete[] tov;
}

void database::totxt() {
    ofstream out("zxc.txt");
    if (!out.is_open()) { cout << "Error" << endl; return; }
    for (int i = 0; i < size; i++) {
        out << tov[i] << endl;
    }
    out.close();
}

void database::fromtxt() {
    ifstream in("zxc.txt");
    if (!in.is_open()) {
        size = 0;
        tov = nullptr;
        return;
    }
    size = 0;
    string sraka;
    while (getline(in, sraka)) {
        if (!sraka.empty()) size++;
    }
    if (size == 0) {
        tov = nullptr;
        in.close();
        return;
    }
    delete[] tov;
    tov = nullptr;

    in.clear();
    in.seekg(0, ios::beg);
    tov = new t[size];
    for (int i = 0; i < size; i++) {
        in >> tov[i];
    }
    in.close();
}

void database::printb() {
    if (size == 0) { cout << "\n pusto " << endl; return; }
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << tov[i] << endl;
    }
}

void database::add(t n) {
    t* sraka = new t[size + 1];
    for (int i = 0; i < size; i++)
        sraka[i] = tov[i];
    sraka[size] = n;
    delete[] tov;
    tov = sraka;
    size++;
}

void database::search(string name1, double price1) {
    int q;
    q = 0;
    for (int i = 0; i < size; i++) {
        if (tov[i].g1() == price1 && tov[i].g2() == name1) {
            cout << i + 1 << ". " << tov[i] << endl;
            q = 1;
        }
    }
    if (q != 1) { cout << "net" << endl; }
}

void database::deletee(int pl) {
    if (pl < 0 || pl >= size) {
        cout << "Error" << endl;
        return;
    }
    t* vr = new t[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != pl) {
            vr[j] = tov[i];
            j++;
        }
    }
    delete[] tov;
    tov = vr;
    size--;
}

void database::editt(int y) {
    if (y < 0 || y >= size) { cout << "Error"; return; }
    cout << " novie dannie(name & price): ";
    string newname;
    double newprice;
    cin >> newname;
    if (cin.fail()) {
        cout << "Error" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin >> newprice;
    if (cin.fail()) {
        cout << "Error" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    if (newprice < 0) {
        cout << "Error" << endl;
        return;
    }
    tov[y] = t(newname, newprice);
}