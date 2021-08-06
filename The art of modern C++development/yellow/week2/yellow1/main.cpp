#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

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

struct BusesForStopResponse {
    vector<string> bus;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.bus.size() == 0) {
        os << "No stop";
    } else {
        for (const string& bus : r.bus) {
            os << bus << " ";
        }
    }
    return os;
}

struct StopsForBusResponse {
    string bus;
    vector<string> stop;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stop.size() == 0) {
        os << "No bus";
    } else {
        for (const string& stop : r.stop) {
            os << "Stop " << stop << ": ";
            if (r.stops_to_buses.at(stop).size() == 1) {
                os << "no interchange";
            } else {
                for (const string& other_bus : r.stops_to_buses.at(stop)) {
                    if (r.bus != other_bus) {
                        os << other_bus << " ";
                    }
                }
            }
            os << endl;
        }
    }

    return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.buses_to_stops.empty()) {
        os << "No buses";
    } else {
        for (const auto& bus_item : r.buses_to_stops) {
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                os << stop << " ";
            }
            os << endl;
        }
    }

    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        buses_to_stops[bus] = stops;
        for( const auto& stop : stops ){
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        BusesForStopResponse b;
        b.bus = (stops_to_buses.count(stop) == 0) ? vector<string>() : stops_to_buses.at(stop);
        return b;
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        StopsForBusResponse s;
        s.bus = bus;
        s.stop = (buses_to_stops.count(bus) == 0) ? vector<string>() : buses_to_stops.at(bus);
        s.stops_to_buses = stops_to_buses;
        return s;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse resp;
        resp.buses_to_stops = buses_to_stops;
        return resp;
    }

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};



int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
