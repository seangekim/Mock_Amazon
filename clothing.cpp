#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand) :
    Product(category, name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing()
{

}


string Clothing::getSize() const
{
    return size_;
}


string Clothing::getBrand() const
{
    return brand_;
}

set<string> Clothing::keywords() const
{
    set<string> set_clothes = parseStringToWords(getBrand());
    set<string> set_name = parseStringToWords(getName());
    set<string> all = setUnion<string>(set_clothes, set_name);

    return all;

}

string Clothing::displayString() const
{
    string str = "";
    str.append(getName());
    str += "\nSize: ";
    str.append(getSize());
    str += " Brand: ";
    str.append(getBrand());
    str += "\n";
    str.append(to_string(getPrice()));
    str += " ";
    str.append(to_string(getQty()));
    str += " left.\n";

    return str;
}

void Clothing::dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;

}