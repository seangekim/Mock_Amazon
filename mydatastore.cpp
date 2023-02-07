#include "util.h"
#include "myDataStore.h"


myDataStore::~myDataStore(){
    products.clear();
    users.clear();
    userCart.clear();
    keyMap.clear();
}

void myDataStore::addProduct(Product* p){
    


}

void myDataStore::addUser(User* u){



}

vector<Product*> myDataStore::search(vector<string>& terms, int type){



}

void myDataStore::dump(ostream& ofile){



}

void myDataStore::purchaseCart(string username){



}

void myDataStore::addToCart(string username, int match_ind, vector<Product*> matches){



}

bool myDataStore::isUser(string username){

    set<User*>::iterator it;
    for(users.begin(); it != users.end(); ++it){
        if((*it)->getName() == username){
            return true;
        }
    }
    return false;
}

User* myDataStore::getUser(string username){

    if(isUser(username)){
        set<User*>::iterator it;
        for(users.begin(); it != users.end(); ++it){
            if((*it)->getName() == username){
                return *it;
            }
        }
    }   
    else{
        throw("Not valid user");
    }
}

vector<Product*> myDataStore::getCart(string username){



}

vector<Product*> myDataStore::getProducts(){

}
