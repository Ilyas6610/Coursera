#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");
    int m, n;
    int s;
    input >> m >> n;
    for( int i = 0; i < m; i++ ){
        for( int j = 0; j < n; j++ ){
            input >> s;
            cout << setw(10) << s;
            if( j != n - 1 ){
                input.ignore(1);
                cout << ' ';
            }
        }
        if( i != m - 1)
            cout << endl;
    }
    return 0;
}
