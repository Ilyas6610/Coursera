#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s){
    int l = s.length();
    for(int i = 0; i < l/2; i++ ){
        if( s[i] != s[l - 1 - i])
            return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> palindroms;
    for (auto w: words){
        if( w.length() >= minLength ){
            if(IsPalindrom(w))
                palindroms.push_back(w);
        }
    }
    return palindroms;
}
