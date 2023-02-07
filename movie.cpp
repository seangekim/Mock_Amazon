#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"


using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating) :
    Product(category, name, price, qty)
{
    genre_ = genre;
    rating_ = rating;
}

Movie::~Movie()
{

}


string Movie::getGenre() const{
    return genre_;
}


string Movie::getRating() const{
    return rating_;
}

set<string> Movie::keywords() const{
    set<string> set_genre = parseStringToWords(getGenre());
    set<string> set_name = parseStringToWords(getName());
    set<string> all = setUnion<string>(set_genre, set_name);

    return all;

}

string Movie::displayString() const{
    string str = "";
    str.append(getName());
    str += "\nGenre: ";
    str.append(getGenre());
    str += " Rating: ";
    str.append(getRating());
    str += "\n";
    str.append(to_string(getPrice()));
    str += " ";
    str.append(to_string(getQty()));
    str += " left.\n";

    return str;

}

void Movie::dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}