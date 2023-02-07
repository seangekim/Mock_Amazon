#include <sstream>
#include <iomanip>
#include "product.cpp"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


class Clothing : public Product{
    public:
        Clothing(const string category, const string name, double price, int qty, string size, string brand);
        ~Clothing();

        set<string> keywords() const;

        bool isMatch(vector<string>& searchTerms) const;

        string displayString() const;

        void dump(ostream& os) const;

        string getSize() const;

        string getBrand() const;

    protected:
        string size_;
        string brand_;






};
