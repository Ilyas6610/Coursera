#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
using namespace std;

class Stats {
public:
    Stats();
    void AddMethod(string_view method);
    void AddUri(string_view uri);
    const map<string_view, int>& GetMethodStats() const;
    const map<string_view, int>& GetUriStats() const;

private:
    map<string_view, int> Methods;
    map<string_view, int> Uri;
    const string unknown_method = "UNKNOWN";
    const string unknown_uri = "unknown";
};

HttpRequest ParseRequest(string_view line);
