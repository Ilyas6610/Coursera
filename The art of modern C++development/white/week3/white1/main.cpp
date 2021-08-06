#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for( int i = 0; i < n; i++ ){
        cin >> p[i];
    }
    sort(p.begin(), p.end(), [](int a, int b){return abs(a) < abs(b);});
    for( const auto& i : p )
        cout << i << ' ';
}
