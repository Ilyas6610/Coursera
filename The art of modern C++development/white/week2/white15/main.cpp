#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    string x;
    cin >> n;
    set<string> s;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
