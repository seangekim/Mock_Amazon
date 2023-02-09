#include <sstream>
#include <iomanip>
#include "util.h"

#include "book.h"

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string isbn, string author) :
    Product(category, name, price, qty)
{
    isbn_ = isbn;
    author_ = author;
}

Book::~Book(){

}


string Book::getAuthor() const{
    return author_;
}


string Book::getIsbn() const{
    return isbn_;
}

set<string> Book::keywords() const{

    set<string> set_author = parseStringToWords(getIsbn());
    set<string> set_name = parseStringToWords(getName());
    set_name.insert(getAuthor());
    set<string> all = setUnion<string>(set_author, set_name);

    return all;
}

string Book::displayString() const{
    string str = "";
    str.append(getName());
    str += "\nAuthor: ";
    str.append(getIsbn());
    str += " ISBN: ";
    str.append(getAuthor());
    str += "\n";
    str.append(to_string(getPrice()));
    str += " ";
    str.append(to_string(getQty()));
    str += " left.\n";

    return str;

}

void Book::dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << author_ << "\n" << isbn_ << endl;
}