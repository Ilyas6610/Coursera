#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
        auto p = dict.insert(word);
      if (p.second) {
        ++newWords;
      }
    }
    return newWords;
  }

  vector<string> KnownWords() {
    return vector<string>(dict.begin(), dict.end());
  }
};
