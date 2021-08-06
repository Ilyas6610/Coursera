#include "bus_manager.h"
#include "responses.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    buses_to_stops[bus] = stops;
    for( const auto& stop : stops ){
        stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse b;
    b.bus = (stops_to_buses.count(stop) == 0) ? vector<string>() : stops_to_buses.at(stop);
    return b;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse s;
    s.bus = bus;
    s.stop = (buses_to_stops.count(bus) == 0) ? vector<string>() : buses_to_stops.at(bus);
    s.stops_to_buses = stops_to_buses;
    return s;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse resp;
    resp.buses_to_stops = buses_to_stops;
    return resp;
}


