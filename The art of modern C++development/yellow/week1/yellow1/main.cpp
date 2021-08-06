#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

int main()
{
    int n, x, num = 0;
    int64_t sum = 0;
    cin >> n;
    vector<int64_t> temp;
    for( int i = 0; i < n; i++ ){
        cin >> x;
        temp.push_back(x);
        sum+=x;
    }
    int64_t avg = sum/n;
    for( int i = 0; i < n; i++ ){
        if( temp[i] > avg )
            num++;
    }
    cout << num << endl;
    for( int i = 0; i < n; i++ ){
        if( temp[i] > avg )
            cout << i << ' ';
    }
    return 0;
}
