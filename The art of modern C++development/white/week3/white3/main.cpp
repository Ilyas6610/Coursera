#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        str.push_back(s);
        sort(str.begin(), str.end());
    }
    vector<string> GetSortedStrings() {
        return str;
    }
private:
    vector<string> str;
};

