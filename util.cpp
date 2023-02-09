#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
string convToLower(string src)
{
    transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
set<string> parseStringToWords(string rawWords)
{
    set<string> wordSet;    
    // for loop to split by punctuation
    int initial = 0;
    for(size_t i=0; i<rawWords.size(); i++){

        if(rawWords[i] == ',' || rawWords[i] == '.' || rawWords[i] == ';' || rawWords[i] == ':' || rawWords[i] == ' ' || rawWords[i] == '\''){
            // edge case if punctuation is at end of string
            if(i == rawWords.size()-1){
                break;
            }
            string pushed_str = rawWords.substr(initial, i-initial);
            initial = i+1; 
            pushed_str = convToLower(pushed_str);

            // checks length of string, then pushes back 
            if(pushed_str.size() > 1){
                wordSet.insert(pushed_str);

            }
        }

        // edge case for last substr 
        else if(i == rawWords.size()-1){
            string pushed_str = rawWords.substr(initial, i-initial+1);
            pushed_str = convToLower(pushed_str);
            // checks length of string, then pushes back 
            if(pushed_str.size() > 1){
                wordSet.insert(pushed_str);
            }
        }
    }
   return wordSet;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from 
// trim from start
string &ltrim(string &s) {
    s.erase(s.begin(), 
	    find_if(s.begin(), 
			 s.end(), 
			 not1(ptr_fun<int, int>(isspace))));
    return s;
}

// trim from end
string &rtrim(string &s) {
    s.erase(
	    find_if(s.rbegin(), 
			 s.rend(), 
			 not1(ptr_fun<int, int>(isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
string &trim(string &s) {
    return ltrim(rtrim(s));
}
