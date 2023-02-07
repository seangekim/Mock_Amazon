#include <sstream>
#include <iomanip>
#include "product.cpp"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


class Book : public Product{
    public:
        Book(const string category, const string name, double price, int qty, string isbn, string author);
        ~Book();

        set<string> keywords() const;

        bool isMatch(vector<string>& searchTerms) const;

        string displayString() const;

        void dump(ostream& os) const;

        string getIsbn() const;

        string getAuthor() const;

    protected:
        string isbn_;
        string author_;






};