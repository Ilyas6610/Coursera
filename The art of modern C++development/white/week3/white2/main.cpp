#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> p(n);
    for( int i = 0; i < n; i++ ){
        cin >> p[i];
    }
    sort(p.begin(), p.end(), [](string a, string b){
         transform(a.begin(), a.end(), a.begin(), [](char c){return tolower(c);});
         transform(b.begin(), b.end(), b.begin(), [](char c){return tolower(c);});
         return a < b;
    });
    for( const auto& i : p )
        cout << i << ' ';
    return 0;
}
