#include "query.h"

istream& operator >> (istream& is, Query& q) {
    string op;
    q.stops.clear();
    is >> op;
    if(op == "NEW_BUS"){
        q.type = QueryType::NewBus;
        is >> q.bus;
        int cnt;
        is >> cnt;
        string s;
        for( int i = 0; i < cnt; i++ ){
            is >> s;
            q.stops.push_back(s);
        }
    }else if (op == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }else if (op == "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }else if (op == "ALL_BUSES")
        q.type = QueryType::AllBuses;
    return is;
}
