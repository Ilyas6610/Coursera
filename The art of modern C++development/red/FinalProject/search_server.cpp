#include "search_server.h"
#include "iterator_range.h"
//#include "../week2/red1/profiler.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <unordered_map>

vector<string> SplitIntoWords(const string& line) {
  istringstream words_input(line);
  return {istream_iterator<string>(words_input), istream_iterator<string>()};
}

SearchServer::SearchServer(istream& document_input) {
  UpdateDocumentBase(document_input);
}

void SearchServer::UpdateDocumentBase(istream& document_input) {
  InvertedIndex new_index;

  for (string current_document; getline(document_input, current_document); ) {
    new_index.Add(move(current_document));
  }

  index = move(new_index);
}

void SearchServer::AddQueriesStream(
  istream& query_input, ostream& search_results_output
) {
    vector<pair<size_t, size_t>> docid_count(50000, {0, 0});
    //vector<size_t> not_null(1000000);
    //int pos = 0;

  for (string current_query; getline(query_input, current_query); ) {
    const auto words = SplitIntoWords(current_query);

//    for( int i = 0; i < pos; i++ ){
//        docid_count[not_null[i]].second = 0;
//    }
    //int k = 0;
    //docid_count.clear();
    fill(docid_count.begin(), docid_count.end(), pair<size_t, size_t>(0, 0));
    for (const auto& word : words) {
      for (const auto docid : index.Lookup(word)) {
            //cout << docid << endl;
        docid_count[docid.first].second+=docid.second;
        docid_count[docid.first].first = docid.first;
//        not_null[k] = docid;
      }
    }
    //pos = k;

    /*vector<pair<size_t, size_t>> search_results(
      make_move_iterator(docid_count.begin()),
      make_move_iterator(docid_count.end())
    );*/
    partial_sort(
      begin(docid_count),
      begin(docid_count) + 5,
      end(docid_count),
      [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
        int64_t lhs_docid = lhs.first;
        auto lhs_hit_count = lhs.second;
        int64_t rhs_docid = rhs.first;
        auto rhs_hit_count = rhs.second;
        return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
      }
    );

    search_results_output << current_query << ':';
    for (int i = 0; i < 5; i++ ) {
//        auto it = min_element(docid_count.begin(), docid_count.end(), [](size_t lhs, size_t rhs) {
//                return lhs > rhs;
//                });
//      int res = distance(docid_count.begin(), it);
        if( docid_count[i].second == 0 )
            break;
      search_results_output << " {"
        << "docid: " << docid_count[i].first << ", "
        << "hitcount: " << docid_count[i].second << '}';
    docid_count[i].second = 0;
    }
    search_results_output << endl;
  }
}

void InvertedIndex::Add(const string& document) {
  docs.push_back(document);

  const size_t docid = docs.size() - 1;
  for (const auto& word : SplitIntoWords(document)) {
    index[word][docid]++;
  }
}

const unordered_map<size_t, size_t>& InvertedIndex::Lookup(const string& word) const {
  if (auto it = index.find(word); it != index.end()) {
    return it->second;
  } else {
    return l;
  }
}
