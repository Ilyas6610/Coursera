#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x, s = 0, r = 0;
    vector<int> v;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        v.push_back(x);
        s += x;
    }
    s /= n;
    for( int i = 0; i < n; i++ ){
        if ( v[i] > s )
            r++;
    }
    cout << r << endl;
    for( int i = 0; i < n; i++ ){
        if ( v[i] > s )
            cout << i << ' ';
    }
    return 0;
}
