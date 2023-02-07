#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>
using namespace std;

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
set<T> setIntersection(set<T>& s1, set<T>& s2)
{
    set<T> interSet;   
    for(typename set<T>::iterator it = s1.begin(); it != s1.end(); ++it){
        if(s2.find(*it) != s2.end()){ 
            interSet.insert(*it);
        }
    }
    return interSet;
}
template <typename T>
set<T> setUnion(set<T>& s1, set<T>& s2)
{
    set<T> unionSet;
    for(typename set<T>::iterator it = s1.begin(); it != s1.end(); ++it){
        unionSet.insert(*it);
    }
    
    for(typename set<T>::iterator it = s2.begin(); it != s2.end(); ++it){
        if(s1.find(*it) != s1.end()){
            continue;
        }
        else{
            unionSet.insert(*it);
        }
    }
    return unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

string convToLower(string src);

set<string> parseStringToWords(string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
string &ltrim(string &s) ;

// Removes any trailing whitespace
string &rtrim(string &s) ;

// Removes leading and trailing whitespace
string &trim(string &s) ;
#endif
