#include <iostream>
#include <cstdint>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
#include <deque>

using namespace std;

struct Hotel{
    Hotel(){};
    Hotel( const string& name_ ) : name(name_)
    {};

    int64_t GetAmountBooks(int64_t time){
        if( time >= last_time_books ){
            if( !books.empty() && abs(time - books.back().first) >= 86400 ){
                books.clear();
                books_last_day = 0;
            }else
                while( !books.empty() && (time - books.front().first) >= 86400 ){
                    books_last_day -= books.front().second;
                    books.pop_front();
                }
            last_time_books = time;
        }
        return books_last_day;
    };

    int64_t GetAmountClients(int64_t time){
        if( time >= last_time_cli ){
            if( !clients.empty() && abs(time - clients.back().first) >= 86400 ){
                clients.clear();
                cli_count.clear();
            } else
                while( !clients.empty() && (time - clients.front().first) >= 86400 ){
                    cli_count[clients.front().second]--;
                    if( cli_count[clients.front().second]  < 1 )
                        cli_count.erase(clients.front().second);
                    clients.pop_front();
                }
            persons = cli_count.size();
            last_time_cli = time;
        }
        return persons;
    };

    void addBook( int64_t time, int cli, int room_c ){
        books.push_back(make_pair(time, room_c));
        books_last_day += room_c;
        clients.push_back(make_pair(time, cli));
        cli_count[cli]++;
    }

    int64_t books_last_day = 0;
    int64_t last_time_cli = numeric_limits<int64_t>::min();
    int64_t last_time_books = numeric_limits<int64_t>::min();
    int64_t persons = 0;
    string name;
    deque<pair<int64_t, int>> books;
    deque<pair<int64_t, int>> clients;
    map<int, int> cli_count;
};

bool operator<(const Hotel& lhs, const Hotel& rhs){
    return lhs.name < rhs.name;
}

bool operator==(const Hotel& lhs, const Hotel& rhs){
    return lhs.name == rhs.name;
}

class Booker{
public:
    Booker(){};

    void BookHotel (int64_t time, const string& hotel, unsigned int cli, unsigned int room_c){
        if( hotels.count(hotel) == 0 )
            hotels[hotel] = Hotel(hotel);
        hotels[hotel].addBook( time, cli, room_c );
    }

    int GetAmountCli(const string& hotel, int64_t time){
        if( hotels.count(hotel) == 0 )
            return 0;
        else{
            return hotels[hotel].GetAmountClients(time);
        }
    }


    int GetAmountRooms(const string& hotel, int64_t time){
        if( hotels.count(hotel) == 0 )
            return 0;
        else{
            return hotels[hotel].GetAmountBooks(time);
        }
    }

private:
    map<string, Hotel> hotels;
};

int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    string command, hotel;
    unsigned int cli_id, room_c;
    int64_t time;
    Booker b;
    for( int i = 0; i < n; i++ ){
        cin >> command;
        if( command == "BOOK" ){
            cin >> time >> hotel >> cli_id >> room_c;
            b.BookHotel(time, hotel, cli_id, room_c);
        }else if( command == "CLIENTS" ){
            cin >> hotel;
            cout << b.GetAmountCli(hotel, time) << endl;
        }else if( command == "ROOMS" ){
            cin >> hotel;
            cout << b.GetAmountRooms(hotel, time) << endl;
        }
    }

    return 0;
}
