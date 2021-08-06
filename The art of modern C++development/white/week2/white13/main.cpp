#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, cnt;
    cin >> n;
    string s, s2;
    map< string, vector<string> > buses, stops;
    for( int i = 0; i < n; i++ ){
        cin >> s;
        if( s == "NEW_BUS" ){
            cin >> s2;
            cin >> cnt;
            for( int j = 0; j < cnt; j++ ){
                cin >> s;
                buses[s2].push_back(s);
                stops[s].push_back(s2);
            }
        }else if( s == "BUSES_FOR_STOP"){
            cin >> s;
            if( stops.find(s) == stops.end() ){
                cout << "No stop" << endl;
                continue;
            }
            for( const auto& i : stops[s] )
                cout << i << ' ';
            cout << endl;

        }else if( s == "STOPS_FOR_BUS" ){
            cin >> s;
            if( buses.find(s) == buses.end() ){
                cout << "No bus" << endl;
                continue;
            }
            for( const auto& i : buses[s] ){
                cout << "Stop " << i << ": ";
                int amount_bus = 0;
                if (!stops[i].empty()){
                    for ( const auto& j : stops[i] ){
                        if ( j == s )
                            continue;
                        amount_bus++;
                        cout << j << ' ';
                    }
                }
                if(!amount_bus)
                    cout << "no interchange";
                cout << endl;
            }

        }else{
            if (!buses.empty())
                for ( const auto& i : buses ){
                    cout << "Bus " << i.first << ": ";
                    for( const auto& j: i.second )
                        cout << j << ' ';
                    cout << endl;
                }
            else
                cout << "No buses" << endl;

        }
    }
    return 0;
}

