#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

class InvertedIndex {
public:
  void Add(const string& document);
  const unordered_map<size_t, size_t>& Lookup(const string& word) const;

  const string& GetDocument(size_t id) const {
    return docs[id];
  }

private:
  unordered_map<string, unordered_map<size_t, size_t>> index;
  unordered_map<size_t, size_t> l = {};
  vector<string> docs;
};

class SearchServer {
public:
  SearchServer() = default;
  explicit SearchServer(istream& document_input);
  void UpdateDocumentBase(istream& document_input);
  void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
  InvertedIndex index;
//  mutex m;
};
