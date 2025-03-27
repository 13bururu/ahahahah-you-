#include <iostream>
#include <string>

class t {
private:
    std::string name;
    double price;
public:
    t() = default;
    t(std::string n, double p) : name(n), price(p) {};
    friend std::ostream& operator<<(std::ostream& out, const t& p);
    friend std::istream& operator>>(std::istream& in, t& p);
    double g1() { return price; }
    std::string g2() { return name; }
};

class database {
private:
    t* tov;
    int size;
    void totxt();
    void fromtxt();
public:
    database();
    ~database();
    void printb();
    void add(t n);
    void search(std::string name1, double price1);
    void deletee(int pl);
    void editt(int y);
};

