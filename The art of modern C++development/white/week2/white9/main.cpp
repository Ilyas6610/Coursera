#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, cnt;
    string s;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> s;
        if( s == "COME" ){
            cin >> cnt;
            v.resize(v.size() + cnt);
        }
        else if(s == "WORRY"){
            cin >> cnt;
            v[cnt] = 1;
        }
        else if(s == "QUIET"){
            cin >> cnt;
            v[cnt] = 0;
        }
        else if(s == "WORRY_COUNT"){
            cout << count(begin(v), end(v), 1) << endl;
        }
    }
    return 0;
}
