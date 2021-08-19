#include <iostream>
#include "stats.h"

using namespace std;

HttpRequest ParseRequest(string_view line){
    HttpRequest hr;
    array<string_view, 3> ar;
    int i = 0;
    size_t k = line.find_first_not_of(' ', 0);
    line.remove_prefix(k);
    while(true){
        size_t s = line.find(' ');
        ar[i] = line.substr(0, s);
        if( s == line.npos )
            break;
        else{
            line.remove_prefix(s+1);
            i++;
        }
    }
    hr = {ar[0], ar[1], ar[2]};
    //cout << hr.method << ' ' << hr.protocol << ' ' << hr.uri << endl;
    return hr;
}


Stats::Stats(){
    Methods["GET"] = 0;
    Methods["POST"] = 0;
    Methods["PUT"] = 0;
    Methods["DELETE"] = 0;
    Methods["UNKNOWN"] = 0;

    Uri["/"] = 0;
    Uri["/order"] = 0;
    Uri["/product"] = 0;
    Uri["/basket"] = 0;
    Uri["/help"] = 0;
    Uri["unknown"] = 0;
}

void Stats::AddMethod(string_view method){
        if( method != "GET" && method != "POST" && method != "PUT" && method != "DELETE" ){
            method = string_view(unknown_method);
        }
        Methods[method]++;

}

void Stats::AddUri(string_view uri){
        if( uri != "/" && uri != "/order" && uri != "/product" && uri != "/basket" && uri != "/help"){
            uri = string_view(unknown_uri);
        }
        Uri[uri]++;

}

const map<string_view, int>& Stats::GetMethodStats() const{
        return Methods;
    }

const map<string_view, int>& Stats::GetUriStats() const{
        return Uri;
}
