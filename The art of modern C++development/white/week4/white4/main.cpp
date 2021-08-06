#include <iostream>
#include <fstream>

using namespace std;

/*int main()
{
    ifstream input("input.txt");
    if( input ){
        string str;
        while(getline(input, str))
            cout << str << endl;
    }
    return 0;
}*/


int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    if( input ){
        string str;
        while(getline(input, str))
            output << str << endl;
    }
    return 0;
}
