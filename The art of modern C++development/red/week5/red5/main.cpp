//#include "../../week1/red1/test_runner.h"
//#include "../../week2/red1/profiler.h"

#include <iostream>
#include <map>
#include <string>
#include <future>
#include <set>
#include <vector>
#include <functional>
#include <sstream>
using namespace std;

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other){
    for( const auto& i : other.word_frequences ){
        this->word_frequences[i.first] += i.second;
    }
  }
};

Stats ExploreLine(const set<string>& key_words, const string& line) {
    Stats res;
    if(key_words.find(line) != key_words.end()){
        res.word_frequences[move(line)]++;
    }
    return res;
}

Stats ExploreKeyWordsSingleThread(
  const set<string>& key_words, vector<string> input
) {
  Stats result;
  auto it = input.begin();
  while( it != input.end() ) {
    result += ExploreLine(key_words, *it);
    it++;
  }
  return result;
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
    Stats result;
    vector<future<Stats>> vec;
    int p = 0;
    unsigned int numThreads = 32;
    vector<vector<string>> words(numThreads);
    string line;
    /*for( string line; getline(input, line); ){
        lines[p%numThreads] << line << '\n';
        p++;
    }*/
    while( input >> line ){
        words[p%numThreads].push_back(move(line));
        p++;
    }
    for( auto& t : words ){
        vec.push_back(async([&key_words, &t]{ return ExploreKeyWordsSingleThread(key_words, t); }));
    }
    for( auto& v : vec ){
        result += v.get();
    }
    return result;
}

