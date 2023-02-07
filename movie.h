#include <sstream>
#include <iomanip>
#include "product.cpp"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


class Movie : public Product{
    public:
        Movie(const string category, const string name, double price, int qty, string genre, string rating);
        ~Movie();

        set<string> keywords() const;

        bool isMatch(vector<string>& searchTerms) const;

        string displayString() const;

        void dump(ostream& os) const;

        string getGenre() const;

        string getRating() const;

    protected:
        string genre_;
        string rating_;






};