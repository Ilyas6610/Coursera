#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    string command, task;
    vector< vector <string> > dailyTasks(31);
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 0;
    for( int i = 0; i < n; i++ ){
        cin >> command;
        if( command == "ADD" ){
            cin >> x >> task;
            dailyTasks[x - 1].push_back(task);
        }else if( command == "DUMP" ){
            cin >> x;
            cout << dailyTasks[x - 1].size() << ' ';
            for( auto t: dailyTasks[x - 1] )
                cout << t << ' ';
            cout << endl;

        }else{
            if( daysInMonth[month] > daysInMonth[(month+1)%12] ){

                for( int j = daysInMonth[(month+1)%12]; j < daysInMonth[month]; j++ ){
 //                   for( auto s: dailyTasks[j] )
  //                      dailyTasks[daysInMonth[(x+1)%12]].push_back(s);
                    dailyTasks[daysInMonth[(month+1)%12] - 1].insert(end(dailyTasks[daysInMonth[(month+1)%12] - 1]),
                                                                     begin(dailyTasks[j]), end(dailyTasks[j]) );
                }
            }
            dailyTasks.resize(daysInMonth[(month+1)%12]);
            month = (month+1)%12;

        }
    }
    return 0;
}
