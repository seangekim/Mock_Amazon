
#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "product.h"
#include "user.h"
#include "datastore.h"
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

class myDataStore : public DataStore{
public:
    
    ~myDataStore();

    void addProduct(Product* p);

    void addUser(User* u);

    vector<Product*> search(vector<string>& terms, int type);

    void dump(ostream& ofile);

    void purchaseCart(string username);

    void addToCart(string username, int match_ind, vector<Product*> matches);

    bool isUser(string username);

	User* getUser(string username);

	void viewCart(string username);

protected:
    vector<Product*> products;
	set<User*> users;
	map<User*, vector<Product*> > userCart;
	map<string, set<Product*> > wordMap;




};
#endif