#include "util.h"
#include "mydatastore.h"
#include <iostream>



myDataStore::~myDataStore(){
    for(size_t i=0; i<products.size(); i++){
        delete (products[i]);
    }
    for(set<User*>::iterator it = users.begin(); it != users.end(); ++it){
        delete *it;
    }
}

void myDataStore::addProduct(Product* p){
    // create the string of keywords

    set<string> p_keywords = p->keywords();

    // loop through keywords and make each one a key, push back every product as values
    for(set<string>::iterator it = p_keywords.begin(); it != p_keywords.end(); ++it){
        // make it undercase
        string prod_name = *it;
        // if current keyword is already in map
        if((p_keywords).find(*it) != p_keywords.end()){
            // add value to map
            (wordMap[prod_name]).insert(p);
        }
        // if keyword is not in map
        else{
            // add new key and value to map
            set<Product*> newSet;
            newSet.insert(p); 
            wordMap[prod_name] = newSet;
        }
    }
    // push back product into list of products
    products.push_back(p);
}

void myDataStore::addUser(User* u){
    users.insert(u);
}

vector<Product*> myDataStore::search(vector<string>& terms, int type){
    set<Product*> outputSet;

    // check if type is valid
    if (type == 0 || type == 1){
        // run loop through term vector
        for(size_t i=0; i<terms.size(); i++){
            // new set that will be pushed into outputSet
            set<Product*> termSet;
            // set temp term
            string temp_term = (terms[i]);
            // cout << "Looking at term: " << temp_term << endl;
            // if term is a key, push to set
            // // debugging script
            // for(map<string, set<Product*> >::iterator it = wordMap.begin(); it != wordMap.end(); ++it){
            //     cout << "RAWR " << it->first << endl;
            // }
            if(wordMap.find(temp_term) != wordMap.end()){
                // new set equal to value in temp_term key
                set<Product*> keySet = wordMap[temp_term];
                // loop to iterate through set 
                // cout << "Found term: " << temp_term << endl;
                for(set<Product*>::iterator it = keySet.begin(); it != keySet.end(); ++it){
                    termSet.insert(*it);
                }
                // if type is 1, perform or search
                if(type == 1){
                    // call union between termSet and outputSet
                    outputSet = setUnion(outputSet, termSet);  
                }
                // else, perform and search
                else{
                    // check if outputSet is empty
                    if(outputSet.size() == 0){
                        outputSet = setUnion(outputSet, termSet);
                    }
                    else{
                        // call intersection between two sets
                        outputSet = setIntersection(outputSet, termSet); 
                    }
                }          
            }
        }
    }

    else{
        throw "Invalid search type";
    }

    vector<Product*> outputVect;
    for(set<Product*>::iterator it = outputSet.begin(); it != outputSet.end(); ++it){
        outputVect.push_back(*it);
    }
    return outputVect;
}

void myDataStore::dump(ostream& ofile){
    ofile << "<products>" << endl;

    // loops through all products and lists them out
    for(size_t i=0; i < products.size(); i++){
        (products[i])->dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;


    // loops through users and lists them out
    for(set<User*>::iterator it = users.begin(); it != users.end(); ++it){
        ofile << (*it)->getName() << " " << (*it)->getBalance() << " " << (*it)->getType() << endl;
    }
    ofile << "</users>" << endl;

}

void myDataStore::purchaseCart(string username){
    User* curr_user = getUser(username);
    vector<Product*> curr_cart = userCart[curr_user];

    if(isUser(username) == false){
        cout << "Invalid username" << endl;
    }
    else{
        for(size_t i=0; i<curr_cart.size(); i++){
            // checks if cart has item and user has enough money
            // cout << "Name: " << curr_cart[i]->getName() << endl;
            // cout << "User Balance: " << curr_user->getBalance() << endl;
            // cout << "Quantity: " << curr_cart[i]->getQty() << endl;
            // cout << "Price: " << curr_cart[i]->getPrice() << endl;

            if(curr_cart[i]->getQty() > 0 && curr_cart[i]->getPrice() < curr_user->getBalance()){
                // charges user price of item
                curr_user->deductAmount(curr_cart[i]->getPrice());
                // subtracts 1 from item qty
                curr_cart[i]->subtractQty(1);
                // erases item from cart
                userCart[curr_user].erase(userCart[curr_user].begin());
            }
            else{
                continue;
            }
        }
    }
}

void myDataStore::addToCart(string username, int match_ind, vector<Product*> matches){
    // checks if match index and username are valid
    if(isUser(username) == false || size_t(match_ind) >= matches.size() || match_ind < 0){
        cout << "Invalid request" << endl;
    }
    else{
        User* curr_user = getUser(username);
        // push product into users cart
        userCart[curr_user].push_back(matches[match_ind]);
        
    }
}

bool myDataStore::isUser(string username){

    set<User*>::iterator it;
    for(it = users.begin(); it != users.end(); ++it){
        if((*it)->getName() == username){
            return true;
        }
    }
    return false;
}

User* myDataStore::getUser(string username){

    if(isUser(username)){
        set<User*>::iterator it;
        for(it = users.begin(); it != users.end(); ++it){
            if((*it)->getName() == username){
                return *it;
            }
        }
    }   
    else{
        cout << "Invalid username" << endl;
    }
    return NULL;
}

vector<Product*> myDataStore::viewCart(string username){
    User* curr_user = getUser(username);
    return userCart[curr_user];
}

